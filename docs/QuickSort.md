# Quick Sort

## Overview
Quick sort is a comparison-based, divide-and-conquer sorting algorithm that selects a pivot element
and partitions the array, so that smaller elements end up to the left of the pivot and larger elements
to the right. It then recursively applies the same process to the sub-arrays on each side of the pivot.

Implementation provides two partition methods (Lomuto and Hoare)
and four pivot selection methods (first element, last element, random element and median-of-three).

## Algorithm Steps
1. Choose a pivot element from the array.
2. Partition the array so that elements smaller than the pivot come before it and elements greater come after it.
3. Recursively apply the same process to the sub-array before the pivot.
4. Recursively apply the same process to the sub-array after the pivot.
5. A sub-array of zero or one element is already sorted.

## Partition Methods

### Lomuto Partition
Uses a single index to track the boundary between elements smaller than the pivot and the rest,
scanning left to right and swapping elements. The pivot ends up exactly at the returned index.

### Hoare Partition
Uses two indices starting from opposite ends of the array, moving inward and swapping elements until the indices cross. 
Performs fewer swaps on average than Lomuto partition method, but the returned index is a split point.

## Pivot Selection Methods

### Last Element Pivot
Always selects the last element of the current range as the pivot. 
Simple, but slow (O(n²)) if the array is already sorted or sorted in reverse.

### First Element Pivot
Always selects the first element of the current range as the pivot. 
Simple, but slow (O(n²)) if the array is already sorted or sorted in reverse.

### Random Pivot
Selects a random element from the current range as the pivot. 
Avoids slow performance on sorted array, since the pivot is not fixed.

### Median-of-Three Pivot
Selects the median of the first, middle and last elements of the current range as the pivot. 
Avoids picking the smallest or largest value as pivot on already-sorted or reverse-sorted input.

## Complexity Analysis
| Case | Time | Notes |
|------|------|------|
| Best | O(n log n)  | |
| Average | O(n log n)  | |
| Worst | O(n²)  | Only with a poorly chosen pivot. Random and median-of-three pivots make this practically unreachable for typical input. |

| Case | Space | Notes |
|------|------|------|
| Average | O(log n) | Recursion stack |
| Worst | O(n) | With an unbalanced partition |

## Properties
- Stable: No
- In-place: Yes

## Advantages
- Fast in practice.
- In-place, no significant extra memory required.
- Random and median-of-three pivot methods help avoid slow performance on sorted input.

## Disadvantages
- Worst case O(n²) if pivot selection is poor.
- Not stable - equal elements may be reordered.
- Recursive implementation risks stack overflow on unbalanced partitions for very large input.

## Usage
Input: [5, 3, 4, 6, 8]

Output: [3, 4, 5, 6, 8]

Custom comparator (descending order):

Input: [5, 3, 4, 6, 8], Compare: `std::greater<int>()`

Output: [8, 6, 5, 4, 3]