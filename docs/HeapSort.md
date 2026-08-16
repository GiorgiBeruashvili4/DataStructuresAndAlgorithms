# Heap Sort

## Overview
Heap sort is a comparison-based sorting algorithm that builds a max-heap from the array, 
then repeatedly extracts the largest element and places is at the end, 
shrinking the heap by one each time until the array is fully sorted.

## Algorithm Steps
1. Build a max-heap from the array (starting from the last non-leaf node).
2. Swap the root (largest element) with the last element of the current heap.
3. Shrink the heap by one.
4. Reheapify the root to restore the max-heap property.
5. Repeat steps 2-4 until the heap contains only one element.

## Complexity Analysis
Time complexity:
- Best case: O(n log n)
- Average Case: O(n log n)
- Worst case: O(n log n)

Space complexity: O(1)

## Properties
- Stable: No
- In-place: Yes

## Advantages
- Guaranteed O(n log n) performance.
- In-place, requires no additional memory.

## Disadvantages
- Not stable - equal elements may be reordered.

## Usage
Input: [5, 3, 4, 6, 8]

Output: [3, 4, 5, 6, 8]

Custom comparator (descending order):

Input: [5, 3, 4, 6, 8], Compare: `std::greater<int>()`

Output: [8, 6, 5, 4, 3]