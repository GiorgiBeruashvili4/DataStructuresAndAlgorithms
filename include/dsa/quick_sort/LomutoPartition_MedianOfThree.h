#pragma once
#include <vector>
#include <algorithm>

// Quick Sort - Lomuto Partition, Median-of-Three Pivot
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
// Partitions array using Lomuto method.
// Finds the median of arr[start], arr[mid], arr[end], then uses that value as the pivot.
// Elements less than the pivot are moved before it, element greater or equal are moved after it.
// The pivot ends up placed exactly at the returned index.

namespace dsa
{
	namespace LomutoQuickSort_MedianOfThree
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

			T pivot = arr[mid];
			std::swap(arr[mid], arr[end]);

			std::size_t j = start;
			for (std::size_t i = start;i < end;++i)
			{
				if (compare(arr[i], pivot))
				{
					std::swap(arr[i], arr[j]);
					++j;
				}
			}

			std::swap(arr[j], arr[end]);

			return j;
		}

		template<typename T, typename Compare = std::less<T>>
		void QuickSort(std::vector<T>& arr, std::size_t start, std::size_t end, Compare compare = Compare())
		{
			if (end <= start)
			{
				return;
			}

			std::size_t pivotIndex = Partition(arr, start, end, compare);

			if (start < pivotIndex)
			{
				QuickSort(arr, start, pivotIndex - 1, compare);
			}

			QuickSort(arr, pivotIndex + 1, end, compare);
		}

		template<typename T, typename Compare = std::less<T>>
		void QuickSort(std::vector<T>& arr, Compare compare = Compare())
		{
			if (arr.empty())
			{
				return;
			}

			QuickSort(arr, 0, arr.size() - 1, compare);
		}
	}
}