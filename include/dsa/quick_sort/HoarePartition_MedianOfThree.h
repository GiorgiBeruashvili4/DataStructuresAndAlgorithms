#pragma once
#include <vector>
#include <algorithm>

// Quick Sort - Hoare Partition, Median-of-Three Pivot
// 
// Time complexity:
// Best case: O(n log n)
// Average case: O(n log n)
// Worst case: O(n²) -> Only with input specifically chosen against this pivot method
//
// Space complexity: O(log n) -> Recursion stack (O(n) worst case)
// Stable: No
// In-place: Yes
//
// Partitions array using Hoare method.
// Finds the median of arr[start], arr[mid], arr[end], then uses that value as the pivot.
// Two indices move inward from opposite ends, swapping elements until they cross.
// The returned index is a split point.

namespace dsa
{
	namespace HoareQuickSort_MedianOfThree
	{
		template<typename T, typename Compare = std::less<T>>
		std::size_t Partition(std::vector<T>& arr, std::size_t start, std::size_t end, Compare compare = Compare())
		{
			std::size_t mid = start + (end - start) / 2;

			if (compare(arr[mid], arr[start]))
			{
				std::swap(arr[mid], arr[start]);
			}
			if (compare(arr[end], arr[start]))
			{
				std::swap(arr[end], arr[start]);
			}
			if (compare(arr[end], arr[mid]))
			{
				std::swap(arr[end], arr[mid]);
			}

			std::swap(arr[start], arr[mid]);
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
}