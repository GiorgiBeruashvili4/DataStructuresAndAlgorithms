#pragma once
#include <vector>
#include <random>
#include <algorithm>

// Quick Sort - Lomuto Partition, Random Pivot
// 
// Time complexity:
// Best case: O(n log n)
// Average case: O(n log n)
// Worst case: O(n²) -> Very unlikely, since the pivot is different each time
//
// Space complexity: O(log n) -> Recursion stack (O(n) worst case)
// Stable: No
// In-place: Yes
//
// Partitions array using Lomuto method.
// Picks a random index and uses that element as the pivot.
// Elements less than the pivot are moved before it, element greater or equal are moved after it.
// The pivot ends up placed exactly at the returned index.

namespace dsa
{
	namespace LomutoQuickSort_RandomPivot
	{
		template<typename T, typename Compare = std::less<T>>
		std::size_t Partition(std::vector<T>& arr, std::size_t start, std::size_t end, std::default_random_engine& engine, Compare compare = Compare())
		{
			std::uniform_int_distribution<std::size_t> dist(start, end);
			std::size_t randomPivotIndex = dist(engine);

			T pivot = arr[randomPivotIndex];
			std::swap(arr[end], arr[randomPivotIndex]);

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
		void QuickSort(std::vector<T>& arr, std::size_t start, std::size_t end, std::default_random_engine& engine, Compare compare = Compare())
		{
			if (end <= start)
			{
				return;
			}

			std::size_t pivotIndex = Partition(arr, start, end, engine, compare);

			if (start < pivotIndex)
			{
				QuickSort(arr, start, pivotIndex - 1, engine, compare);
			}

			QuickSort(arr, pivotIndex + 1, end, engine, compare);
		}

		template<typename T, typename Compare = std::less<T>>
		void QuickSort(std::vector<T>& arr, Compare compare = Compare())
		{
			if (arr.empty())
			{
				return;
			}

			static std::random_device dr;
			std::default_random_engine engine(dr());

			QuickSort(arr, 0, arr.size() - 1, engine, compare);
		}
	}
}