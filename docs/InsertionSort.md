# Insertion Sort

## Overview
Insertion sort is a simple comparison-based sorting algorithm that builds
the final sorted array one element at a time.

## Algorithm Steps
1. Start from the second element because the first element is already sorted.
2. Compare the current element with elements in the second portion.
3. Shift larger elements to the right.
4. Insert the current element into its correct position.
5. Repeat until the entire array is sorted.

## Complexity Analysis
| Case | Time | Notes |
|------|------|------|
| Best | O(n) | If array is already sorted |
| Average | O(n²) |  |
| Worst | O(n²) | If array is sorted in reverse order |

Space complexity: O(1)

## Properties
- Stable: Yes
- In-place: Yes

## Advantages
- Simple and easy to implement.
- No additional memory is needed.
- Efficient for small data.

## Disadvantages
- Inefficient for large data.
- Requires many shifts when elements are far from their correct position.

## Usage
Input: [5, 3, 4, 6, 8]

Output: [3, 4, 5, 6, 8]

Custom comparator (descending order):

Input: [5, 3, 4, 6, 8], Compare: `std::greater<int>()`

Output: [8, 6, 5, 4, 3]