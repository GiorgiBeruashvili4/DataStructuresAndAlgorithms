#pragma once
#include <vector>

// Insertion Sort
// 
// Time complexity:
// Best case: O(n) -> If array is already sorted
// Average case: O(n²)
// Worst case: O(n²) -> If array is sorted in reverse order
//
// Space complexity: O(1)
// Stable: Yes
// In-place: Yes

namespace dsa
{
	template<typename T, typename Compare = std::less<T>>
	void InsertionSort(std::vector<T>& arr, Compare compare = Compare())
	{
		const std::size_t size = arr.size();

		for (std::size_t i = 1;i < size;++i)
		{
			T key = arr[i];
			std::size_t j = i;

			while (j > 0 && compare(key, arr[j - 1]))
			{
				arr[j] = arr[j - 1];
				--j;
			}

			arr[j] = key;
		}
	}
}