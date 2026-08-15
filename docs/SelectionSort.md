# Selection Sort

## Overview
Selection sort is a simple comparison-based sorting algorithm that repeatedly 
selects the smallest element from the unsorted portion of the array and places it 
in the correct position. 

## Algorithm Steps
1. Assume the first element is the minimum.
2. Find smaller value in the remaining unsorted portion.
3. If a smaller element is found, remember its index.
4. Swap the minimum element with the first unsorted element.
5. Repeat until the entire array is sorted.

## Complexity Analysis
Time complexity:
- Best case: O(n²)
- Average Case: O(n²)
- Worst case: O(n²)

Space complexity: O(1)

## Properties
- Stable: No
- In-place: Yes

## Advantages
- Simple and easy to implement.
- No additional memory is needed.
- Performs at most one swap per pass that is suitable when swap operations are expensive.

## Disadvantages
- Inefficient for large data.
- Not stable.
- Always performs O(n²) comparisons, even if the array is already sorted.

## Usage
Input: [5, 3, 4, 6, 8]

Output: [3, 4, 5, 6, 8]

Custom comparator (descending order):

Input: [5, 3, 4, 6, 8], Compare: `std::greater<int>()`

Output: [8, 6, 5, 4, 3]