# Bubble Sort

## Overview
Bubble sort is a simple comparison-based sorting algorithm that repeatedly 
compares neighboring elements and swaps them if they are in the wrong order.

## Algorithm Steps
1. Compares two neighboring elements.
2. If the left element is greater than the right element, swap.
3. Continue comparing elements until reaching the end of the array.
4. Repeat the process for the remaining unsorted portion.
5. Stop early if no swaps are made during a pass that means the array is already sorted.

## Complexity Analysis
Time complexity:
- Best case: O(n) - If array is already sorted (with optimization)
- Average Case: O(n²)
- Worst case: O(n²) - If array is sorted in reverse order

Space complexity: O(1)

## Properties
- Stable: Yes
- In-place: Yes

## Advantages
- Simple and easy to implement.
- No additional memory is needed.
- Can detect already sorted arrays.

## Disadvantages
- Inefficient for large data.
- Performs many unnecessary comparisons.

## Usage
Input: [5, 3, 4, 6, 8]

Output: [3, 4, 5, 6, 8]







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
Time complexity:
- Best case: O(n) - If array is already sorted
- Average Case: O(n²)
- Worst case: O(n²) - If array is sorted in reverse order

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