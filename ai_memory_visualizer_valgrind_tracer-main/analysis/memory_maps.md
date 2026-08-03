# Memory Maps

## Aliasing-Example.c

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
