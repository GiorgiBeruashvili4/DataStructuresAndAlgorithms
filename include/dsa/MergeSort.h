#pragma once
#include <vector>

// Merge Sort
// 
// Time complexity:
// Best case: O(n log n)
// Average case: O(n log n)
// Worst case: O(n log n)
//
// Space complexity: O(n) -> Temporary left/right subarrays
// Stable: Yes
// In-place: No
//
// Recursively splits the array into two halves until each subarray has one element.
// Then each pair of sorted halves is merged back together.

namespace dsa
{
	template<typename T, typename Compare = std::less<T>>
	void Merge(std::vector<T>& arr, std::size_t start, std::size_t mid, std::size_t end, Compare compare = Compare())
	{
		std::vector<T> left(arr.begin() + start, arr.begin() + mid + 1);
		std::vector<T> right(arr.begin() + mid + 1, arr.begin() + end + 1);

		std::size_t i = 0;
		std::size_t j = 0;
		std::size_t k = start;

		while (i < left.size() && j < right.size())
		{
			if (!compare(right[j], left[i]))
			{
				arr[k] = left[i];
				++i;
			}
			else
			{
				arr[k] = right[j];
				++j;
			}

			++k;
		}

		while (i < left.size())
		{
			arr[k] = left[i];
			++i;
			++k;
		}

		while (j < right.size())
		{
			arr[k] = right[j];
			++j;
			++k;
		}
	}

	template<typename T, typename Compare = std::less<T>>
	void MergeSort(std::vector<T>& arr, std::size_t start, std::size_t end, Compare compare = Compare())
	{
		if (end <= start)
		{
			return;
		}

		std::size_t mid = start + (end - start) / 2;

		MergeSort(arr, start, mid, compare);
		MergeSort(arr, mid + 1, end, compare);

		Merge(arr, start, mid, end, compare);
	}

	template<typename T, typename Compare = std::less<T>>
	void MergeSort(std::vector<T>& arr, Compare compare = Compare())
	{
		if (arr.size() <= 1)
		{
			return;
		}

		MergeSort(arr, 0, arr.size() - 1, compare);
	}
}