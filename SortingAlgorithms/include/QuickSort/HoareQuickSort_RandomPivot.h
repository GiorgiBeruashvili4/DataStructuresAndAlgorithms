#pragma once
#include <vector>
#include <algorithm>
#include <random>

// Quick Sort - Hoare Partition, Random Pivot
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
// Partitions array using Hoare method.
// Picks a random index and uses that element as the pivot.
// Two indices move inward from opposite ends, swapping elements until they cross.
// The returned index is a split point.

namespace HoareQuickSort_RandomPivot
{
	template<typename T, typename Compare = std::less<T>>
	std::size_t Partition(std::vector<T>& arr, std::size_t start, std::size_t end, std::default_random_engine& engine, Compare compare = Compare())
	{
		std::uniform_int_distribution<std::size_t> dist(start, end);
		std::size_t randomPivotIndex = dist(engine);

		std::swap(arr[start], arr[randomPivotIndex]);
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
	void QuickSort(std::vector<T>& arr, std::size_t start, std::size_t end, std::default_random_engine& engine, Compare compare = Compare())
	{
		if (end <= start)
		{
			return;
		}

		std::size_t partitionIndex = Partition(arr, start, end, engine, compare);

		if (start < partitionIndex)
		{
			QuickSort(arr, start, partitionIndex, engine, compare);
		}

		QuickSort(arr, partitionIndex + 1, end, engine, compare);
	}

	template<typename T, typename Compare = std::less<T>>
	void QuickSort(std::vector<T>& arr, Compare compare = Compare())
	{
		if (arr.size() <= 1)
		{
			return;
		}

		static std::random_device dr;
		std::default_random_engine engine(dr());

		QuickSort(arr, 0, arr.size() - 1, engine, compare);
	}
}