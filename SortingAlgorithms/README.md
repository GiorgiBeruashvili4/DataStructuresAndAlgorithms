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

Custom comparator (descending order):

Input: [5, 3, 4, 6, 8], Compare: `std::greater<int>()`

Output: [8, 6, 5, 4, 3]





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

Custom comparator (descending order):

Input: [5, 3, 4, 6, 8], Compare: `std::greater<int>()`

Output: [8, 6, 5, 4, 3]





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