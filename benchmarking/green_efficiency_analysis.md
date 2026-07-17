# Green Efficiency Analysis

## Measurement Methodology

I tested three programs. 
- baseline_loop.c runs a counting loop 100,000,000 times. I ran it 3 times and recorded each execution time. 
- comparison_algorithms.c counts even numbers in a 50,000-element array two ways (naive and single-pass). I ran it 3 times (Run A, B, C), recording both results and times each run, then averaged the naive times and single-pass times separately. 
- instrumentation_lab.c builds, processes, and reduces a 50,000-number list. I compiled it once and ran it 3 times, recording TOTAL, BUILD_DATA, PROCESS, and REDUCE each run.

## Observed Performance Differences

### Baseline Loop
0.076653s, 0.071211s, 0.071493s. Average: 0.073119s. The times are close but not identical, even though iteration count is the same throughout all 3 runs.

### Algorithm Comparison
- Naive: 0.769337s, 0.760977s, 0.766777s (average 0.765697s), result = 625,025,000 every run.
- Single-pass: 0.000032s, 0.000031s, 0.000029s (average 0.0000307s), result = 25,000 every run.

Single-pass is about 25,000 times faster, cutting runtime by 99.996%. Its result (25,000) matches the real number of even values in the array as ARRAY_SIZE was 50,000. The naive result takes longer because its nested loop re-checks earlier elements on every outer iteration, so even numbers get counted repeatedly instead of once. This repeated work is why naive is both slower and produces a different total.

### Instrumentation Lab

#### Run 1
TOTAL seconds: 0.000676
BUILD_DATA seconds: 0.000320
PROCESS seconds: 0.000237
REDUCE seconds: 0.000113

#### Run 2
TOTAL seconds: 0.000714
BUILD_DATA seconds: 0.000284
PROCESS seconds: 0.000282
REDUCE seconds: 0.000134

#### Run 3
TOTAL seconds: 0.000839
BUILD_DATA seconds: 0.000416
PROCESS seconds: 0.000282
REDUCE seconds: 0.000133

##
