# Sorting Algorithms Performance

Implementation and performance comparison of multiple sorting algorithms using C++. This project evaluates runtime behavior across different input sizes and data conditions to analyze algorithm efficiency.

## Overview

This project implements several classic sorting algorithms and measures their runtime performance on arrays of increasing sizes. It compares O(n²) and O(n log n) algorithms under different input conditions to observe how theoretical complexity translates into real-world execution.

The program generates arrays, applies a selected sorting algorithm, and measures execution time. It supports different input configurations and allows optional printing of arrays for verification.

## Features

- Implemented sorting algorithms:
  - Bubble Sort (standard and optimized)
  - Insertion Sort
  - Merge Sort
  - Quick Sort
  - Shell Sort (Sedgewick gaps)
- Runtime benchmarking for varying input sizes
- Supports multiple input conditions:
  - Random
  - Ordered
  - Partially ordered
  - Reversed
- Command-line driver for selecting sort type and input size
- Execution time measurement using system timing functions

## Tech Stack

- C++
- STL (vector)
- Linux (g++ compiler)
- System timing (gettimeofday)

## Project Structure

```
Sorter.cpp        // Driver program for running sorts and timing
SortImpls.cpp     // Implementations of all sorting algorithms
report.pdf        // Performance analysis and graphs
```

## How to Run

Compile:

```
g++ Sorter.cpp -o Sorter
```

Run:

```
./Sorter SORT_TYPE ARRAY_SIZE [YES|NO]
```

Examples:

```
./Sorter QuickSort 1000 NO
./Sorter MergeSort 100
./Sorter BubbleSort 25 YES
```

## Supported Algorithms

- BubbleSort
- InsertionSort
- MergeSort
- QuickSort
- ShellSort

## Input Parameters

- SORT_TYPE: name of sorting algorithm
- ARRAY_SIZE: number of elements
- YES/NO: print array before and after sorting

## Testing

Performance was measured by running each algorithm multiple times and averaging results across different input sizes and configurations.

Test cases include:

- Random arrays
- Sorted arrays
- Partially sorted arrays
- Reverse-sorted arrays

Input sizes ranged from small datasets to large-scale inputs to observe growth behavior.

## Results

- O(n²) algorithms (BubbleSort, InsertionSort) show significant slowdown for large inputs
- O(n log n) algorithms (MergeSort, QuickSort) scale efficiently
- ShellSort performance varies depending on gap sequence
- Input ordering significantly affects performance, especially for BubbleSort and QuickSort
- Optimized BubbleSort performs near O(n) for nearly sorted data

## Key Concepts Demonstrated

- Algorithm complexity and runtime analysis
- Differences between theoretical and actual performance
- Impact of input distribution on algorithm efficiency
- Memory usage considerations in sorting implementations
