# Memory Maps

## Aliasing Example

### Key Execution Points
1. (Lines 24 - 25) Pointers to variables a and b are created. Both pointers are NULL.
2. (Line 30) a pointer assigned to the return value of function `make_numbers(n)`. Return value here should be an address
3. (Line 7) Pointer variable `*arr` created which currently is NULL.
4. (Line 12) Heap space is allocated and arr points to the first byte of that block of allocated space
5. (Lines 16 - 17) All integers within the arr array are calculated as their index * 11.
6. (Line 19) The address of the first byte of the array is returned
7. (Line 30) The pointer variable a is equal to the address of the array that was just created
8. (Line 34) A varaible `b` is created which is the same value as `a` which is the address to the first byte of the array that was created
9. (Line 36) Accessing and printing the addresses that are contained in pointers `a` and `b`. Also access and printing the 2-index of `a` and `b` arrays
10. (Line 38) Frees the memory of `a`. Memory that was allocated in the heap for `a` is now available to use again. The `a` pointer is now invalid
11. (Line 40) Memory at pointer `b` is attempted to be accessed. However, since the memory was already freed using the `a` pointer, this results in a use-after-free. `b` is still a valid pointer.
12. (Line 42) Value at `b[2]` is 0. This is valid but the memory there is no longer allocated for this pointer, so it could be anything.
13. (Line 44-45) Writing and accessing memory at `b[3]`

### AI Generated Memory Map

### Memory Map Walkthrough: `aliasing_example.c`
 
This document traces `aliasing_example.c` step by step, showing the stack, heap, and pointer state at each point in execution — including the aliasing and use-after-free bug that Valgrind flags.
 
#### Step 0 — `main()` starts
 
```
STACK
┌─────────────────────────────┐
│ main()                       │
│   a = NULL                   │
│   b = NULL                   │
│   n = 5                      │
└─────────────────────────────┘
 
HEAP
(empty)
```
 
#### Step 1 — `make_numbers(5)` is called
 
A new stack frame is pushed on top of `main`'s frame.
 
```
STACK
┌─────────────────────────────┐
│ make_numbers()                │
│   n   = 5   (parameter)       │
│   i   = 0                     │
│   arr = NULL                  │
├─────────────────────────────┤
│ main()                        │
│   a = NULL                    │
│   b = NULL                    │
│   n = 5                       │
└─────────────────────────────┘
 
HEAP
(empty)
```
 
#### Step 2 — `malloc(5 * sizeof(int))` succeeds
 
A 20-byte block is allocated on the heap (call its address `H`). Contents are uninitialized garbage until the loop runs.
 
```
STACK
┌─────────────────────────────┐
│ make_numbers()                │
│   n   = 5                     │
│   i   = 0                     │
│   arr = H   ───────────┐      │
├─────────────────────────┼─────┤
│ main()                  │      │
│   a = NULL              │      │
│   b = NULL              │      │
│   n = 5                 │      │
└─────────────────────────┼─────┘
                           │
HEAP                       ▼
┌─────────────────────────────────────────┐
│ H: [ ????, ????, ????, ????, ???? ]      │  (20 bytes, state: ALLOCATED)
└─────────────────────────────────────────┘
```
 
#### Step 3 — the `for` loop fills the array
 
```
HEAP
┌─────────────────────────────────────────┐
│ H: [ 0, 11, 22, 33, 44 ]                 │  (state: ALLOCATED, owner: arr)
└─────────────────────────────────────────┘
```
 
`arr` still holds `H`; `i` has reached 5 and the loop exits.
 
#### Step 4 — `return arr;` — `make_numbers`'s frame is popped
 
The function returns the pointer value `H`. Its stack frame (and the local variables `n`, `i`, `arr` inside it) cease to exist — but note that `H` itself is heap memory, not stack memory, so the array data survives the frame's destruction.
 
```
STACK
┌─────────────────────────────┐
│ main()                       │
│   a = H    ← received        │
│   b = NULL                   │
│   n = 5                      │
└─────────────────────────────┘
 
HEAP
┌─────────────────────────────────────────┐
│ H: [ 0, 11, 22, 33, 44 ]                 │  (state: ALLOCATED, owner: a)
└─────────────────────────────────────────┘
```
 
#### Step 5 — `b = a;` (aliasing)
 
`b` is assigned the same address as `a`. No new heap memory is created — `a` and `b` are now **two independent pointer variables that alias the same object**.
 
```
STACK
┌─────────────────────────────┐
│ main()                       │
│   a = H   ──┐                │
│   b = H   ──┤ both alias H   │
│   n = 5     │                │
└─────────────┼────────────────┘
              ▼
HEAP
┌─────────────────────────────────────────┐
│ H: [ 0, 11, 22, 33, 44 ]                 │  (state: ALLOCATED, owners: a, b)
└─────────────────────────────────────────┘
```
 
`a[2]` and `b[2]` both read `22`, confirmed by the printf.
 
#### Step 6 — `free(a);`
 
The allocator marks block `H` as free and may reuse/scramble its contents. **Critically, `free()` does not change the pointer variable `a` itself** — `a` still numerically holds the address `H`, it's just now a dangling pointer. `b` also still holds `H` and is dangling too, since freeing memory doesn't know or care how many pointers alias it.
 
```
STACK
┌─────────────────────────────┐
│ main()                       │
│   a = H   (dangling!)        │
│   b = H   (dangling!)        │
│   n = 5                      │
└─────────────────────────────┘
 
HEAP
┌─────────────────────────────────────────┐
│ H: [ freed — contents undefined ]        │  (state: FREED)
└─────────────────────────────────────────┘
```
 
#### Step 7 — `printf("... b=%p ...")`
 
Only the pointer *value* is printed — this is legal (printing an address doesn't dereference it). `b` still prints as `H`, giving the illusion nothing is wrong.
 
#### Step 8 — `b[2]` is read — use-after-free (read)
 
This dereferences freed memory. The behavior is undefined: it might print `22` (if the block hasn't been reused/overwritten yet), garbage, or in rare cases crash. This is exactly the class of bug Valgrind's `memcheck` flags as "Invalid read of size 4."
 
```
HEAP
┌─────────────────────────────────────────┐
│ H: [ ?, ?, ?, ?, ? ]                     │  (state: FREED — reading is UB)
└─────────────────────────────────────────┘
        ▲
        │
   b (dangling) — read attempted here
```
 
#### Step 9 — `b[3] = 1234;` — use-after-free (write)
 
This is worse: writing through a dangling pointer corrupts memory the allocator now considers free. It could silently corrupt allocator metadata or a future unrelated allocation that happens to reuse address `H`. Valgrind reports this as "Invalid write of size 4."
 
```
HEAP
┌─────────────────────────────────────────┐
│ H: [ ?, ?, ?, 1234(?), ? ]               │  (state: FREED — writing is UB,
└─────────────────────────────────────────┘    may corrupt heap metadata or
                                                 a future allocation at H)
```
 
#### Step 10 — `return 0;` — `main`'s frame is popped
 
```
STACK
(empty — program exiting)
 
HEAP
Block H: still marked FREED, was never re-allocated by this program,
so it just leaks back to the OS at process exit.
```
 
---
 
#### Summary of what's actually wrong
 
| Bug | Where | Why it matters |
|---|---|---|
| **Aliasing** | `b = a;` (step 5) | Not a bug by itself, but means `free(a)` invalidates `b` too — the program has no way to know from `b` alone that it's dangling. |
| **Use-after-free read** | `b[2]` (step 8) | Reads memory the allocator has reclaimed; value is unreliable. |
| **Use-after-free write** | `b[3] = 1234;` (step 9) | Writes into freed memory — can corrupt heap bookkeeping or a future object allocated at the same address. |
| **Dangling pointer** | `a` and `b` after step 6 | Neither is set to `NULL` after `free()`, so nothing distinguishes "valid pointer" from "freed pointer" at the type level. |
 
**Fix pattern:** set `a = NULL;` right after `free(a);`, and since `b` is just a copy of the same address, either avoid the second alias entirely or null it out too (`b = NULL;`) — nulling `a` alone doesn't protect `b`, since they're independent variables that happened to hold the same value.

### AI Assumptions and Inaccuracies

Step 8: "This is exactly the class of bug Valgrind's memcheck flags as "Invalid read of size 4."" - Assumption of Valgrind output despite no Valgrind output being present  
Step 9: "writing through a dangling pointer corrupts memory the allocator now considers free" - Very bad but doesn't necessarily corrupt the data. Corrupting data is a risk but the behaviour is undefined.  
Step 10: "Block H: still marked FREED, was never re-allocated by this program, so it just `leaks` back to the OS at process exit." - Could just be the wrong wording. Mememory leak happens specifically when memory isn't freed. 

## Crash Example

### AI Generated Memory Map

### Key Execution Points
1. (Line 24) The variable nums is assigned as a pointer in stack memory. Currently it holds the address NULL.
2. (Line 25) The varibale `n` is assigned the value 0 in stack memory.
3. (Line 28) The variable `n` is accessed from stack memory and its value printed out
4. (Line 30) Function `allocate_numbers()` called with the variable `n` passed through
5. (Line 6) The variable `arr` is assigned as a pointer in stack memory. This variable is local to the `allocate_numbers()` function. Holds the address NULL.
6. (Line 7) The variable `i` is assigned the value 0.
7. (Lines 9 - 10) `n` in this case contains the value of 0. Thus, the function returns the value NULL
8. The pointer nums, still holds the address NULL as that is what was returned from the `allocate_numbers` function
9. Program attempts to assign the value 42 to nums[0]. However, as nums holds the address NULL, it is attempting to store a value in memory that is does not have access to. The program should hit a segmentation error at this point.

### Memory Map Walkthrough: `crash_example.c`
 
This document traces `crash_example.c` step by step, showing the stack, heap, and pointer state at each point in execution — including the NULL-pointer dereference that causes the segmentation fault.
 
#### Step 0 — `main()` starts
 
```
STACK
┌─────────────────────────────┐
│ main()                       │
│   nums = NULL                │
│   n    = 0                   │
└─────────────────────────────┘
 
HEAP
(empty)
```
 
#### Step 1 — the two `printf` calls run
 
Nothing changes in memory; this just confirms `n = 0` is what will be passed to `allocate_numbers`.
 
```
STACK
┌─────────────────────────────┐
│ main()                       │
│   nums = NULL                │
│   n    = 0                   │
└─────────────────────────────┘
 
HEAP
(empty)
```
 
#### Step 2 — `allocate_numbers(0)` is called
 
A new stack frame is pushed on top of `main`'s frame.
 
```
STACK
┌─────────────────────────────┐
│ allocate_numbers()            │
│   n   = 0   (parameter)       │
│   arr = NULL                  │
│   i   = 0                     │
├─────────────────────────────┤
│ main()                        │
│   nums = NULL                 │
│   n    = 0                    │
└─────────────────────────────┘
 
HEAP
(empty)
```
 
#### Step 3 — `if (n <= 0) return NULL;` fires
 
Since `n` is `0`, the guard clause is true. The function returns immediately — **`malloc` is never reached**, so no heap allocation ever happens on this path. `arr` is discarded still holding `NULL`.
 
```
STACK
┌─────────────────────────────┐
│ allocate_numbers()            │
│   n   = 0                     │
│   arr = NULL   (never used)   │
│   i   = 0                     │
│   → returning NULL            │
├─────────────────────────────┤
│ main()                        │
│   nums = NULL                 │
│   n    = 0                    │
└─────────────────────────────┘
 
HEAP
(empty — malloc was skipped entirely)
```
 
#### Step 4 — `allocate_numbers`'s frame is popped
 
The return value `NULL` is handed back to `main` and assigned to `nums`. The callee's frame (`n`, `arr`, `i`) ceases to exist.
 
```
STACK
┌─────────────────────────────┐
│ main()                       │
│   nums = NULL   ← received   │
│   n    = 0                   │
└─────────────────────────────┘
 
HEAP
(empty)
```
 
At this point `nums` is a **null pointer**, not a dangling pointer — it was never made to point at valid memory in the first place. The bug here is different in kind from the aliasing/use-after-free example: there, pointers *became* invalid after a valid object was freed; here, the pointer was *never valid* to begin with, and nothing checked for that before using it.
 
#### Step 5 — `nums[0] = 42;` — NULL pointer dereference (crash)
 
`nums[0]` is shorthand for `*(nums + 0)`, i.e. "write to the memory at address `NULL + 0`." Address `0` (and the small range around it) is deliberately kept unmapped by the operating system precisely so that this kind of bug is caught immediately.
 
```
STACK
┌─────────────────────────────┐
│ main()                       │
│   nums = NULL   ─────┐       │
│   n    = 0            │       │
└───────────────────────┼──────┘
                         ▼
                  address 0x0
              ┌───────────────────┐
              │   UNMAPPED PAGE     │  ← write attempted here
              └───────────────────┘
                         │
                         ▼
              SIGSEGV — segmentation fault
              process terminates immediately
```
 
**Execution stops here.** The program never reaches the third `printf`, the `free(nums)` call, or `return 0;` — the OS kills the process as soon as the invalid write is attempted. Unlike the aliasing example (which produces silent, undefined-but-not-always-crashing behavior), this bug is **deterministic**: every run with `n = 0` crashes at exactly the same line, which is why the file is named `crash_example`.
 
#### Steps that never happen
 
Because the crash is fatal, the following never execute and are shown only for completeness of what *would* have happened if `nums` had been valid:
 
```
(unreached) printf("  nums[0]=%d\n", nums[0]);
(unreached) free(nums);
(unreached) return 0;
```
 
---
 
#### Summary of what's actually wrong
 
| Bug | Where | Why it matters |
|---|---|---|
| **Missing NULL check** | `nums = allocate_numbers(n);` (step 4) | `allocate_numbers` clearly documents (via its own `if (!arr) return NULL;` and `if (n <= 0) return NULL;` guards) that it can return `NULL`, but `main` never checks the result before using it. |
| **NULL pointer dereference** | `nums[0] = 42;` (step 5) | Writing through a `NULL` pointer accesses an intentionally unmapped page, so the OS raises `SIGSEGV` and kills the process on the spot. |
| **No allocation ever occurs** | `allocate_numbers(0)` (step 3) | Worth noting for contrast with the aliasing example: this isn't a heap-corruption or use-after-free bug — the heap is never touched at all. The entire bug lives in the stack/pointer logic in `main`. |
 
**Fix pattern:** check the return value before use:
 
```c
nums = allocate_numbers(n);
if (!nums) {
    fprintf(stderr, "allocation failed or n <= 0\n");
    return 1;
}
nums[0] = 42;
```
 
This turns a hard crash into a graceful, recoverable error path.

## AI Assumptions and Inaccuraties

Didn't note any inaccuracies here.


