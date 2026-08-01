#pragma once
#include <vector>
#include <algorithm>

// Quick Sort - Hoare Partition, First Element Pivot
// 
// Time complexity:
// Best case: O(n log n)
// Average case: O(n log n)
// Worst case: O(n²) -> If array is already sorted or sorted in reverse order
//
// Space complexity: O(log n) -> Recursion stack (O(n) worst case)
// Stable: No
// In-place: Yes
//
// Partitions array using Hoare method.
// Uses the first element of the range as the pivot.
// Two indices move inward from opposite ends, swapping elements until they cross.
// The returned index is a split point.

namespace HoareQuickSort_FirstPivot
{
	template<typename T, typename Compare = std::less<T>>
	std::size_t Partition(std::vector<T>& arr, std::size_t start, std::size_t end, Compare compare = Compare())
	{
		T pivot = arr[start];

		std::ptrdiff_t left = static_cast<std::ptrdiff_t>(start) - 1;
		std::ptrdiff_t right = static_cast<std::ptrdiff_t>(end) + 1;

		while (true)
		{
			do
			{
				++left;
			} while (compare(arr[left], pivot));

			do
			{
				--right;
			} while (compare(pivot, arr[right]));

			if (right <= left)
			{
				return static_cast<std::size_t>(right);
			}

			std::swap(arr[left], arr[right]);
		}
	}

	template<typename T, typename Compare = std::less<T>>
	void QuickSort(std::vector<T>& arr, std::size_t start, std::size_t end, Compare compare = Compare())
	{
		if (end <= start)
		{
			return;
		}

		std::size_t partitionIndex = Partition(arr, start, end, compare);

		if (start < partitionIndex)
		{
			QuickSort(arr, start, partitionIndex, compare);
		}

		QuickSort(arr, partitionIndex + 1, end, compare);
	}

	template<typename T, typename Compare = std::less<T>>
	void QuickSort(std::vector<T>& arr, Compare compare = Compare())
	{
		if (arr.size() <= 1)
		{
			return;
		}

		QuickSort(arr, 0, arr.size() - 1, compare);
	}
}