# Merge Sort

## Overview
Merge sort is a simple comparison-based, divide-and-conquer sorting algorithm that splits the 
array into halves, recursively sorts each half and then merges the sorted halves back together.

## Algorithm Steps
1. Divide the array into two halves.
2. Recursively sort the left half.
3. Recursively sort the right half.
4. Merge the two sorted halves back into a single sorted array.
5. Repeat until the base case is reached (subarray of size 1 or 0).

## Complexity Analysis
Time complexity:
- Best case: O(n log n)
- Average Case: O(n log n)
- Worst case: O(n log n)

Space complexity: O(n) - Temporary left/right subarrays

## Properties
- Stable: Yes
- In-place: No

## Advantages
- Consistent O(n log n) performance.
- Stable, preserves the relative order of equal elements.

## Disadvantages
- Requires additional memory.
- Not in-place, extra copying is needed at every merge step.

## Usage
Input: [5, 3, 4, 6, 8]

Output: [3, 4, 5, 6, 8]

Custom comparator (descending order):

Input: [5, 3, 4, 6, 8], Compare: `std::greater<int>()`

Output: [8, 6, 5, 4, 3]