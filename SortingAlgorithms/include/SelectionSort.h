#pragma once
#include <vector>
#include <algorithm>

// Selection Sort
// 
// Time complexity:
// Best case: O(n²)
// Average case: O(n²)
// Worst case: O(n²)
//
// Space complexity: O(1)
// Stable: No
// In-place: Yes

template<typename T>
void SelectionSort(std::vector<T>& arr)
{
	const std::size_t size = arr.size();

	for (std::size_t i = 0;i + 1 < size;++i)
	{
		std::size_t minIndex = i;
		for (std::size_t j = i + 1;j < size;++j)
		{
			if (arr[j] < arr[minIndex])
			{
				minIndex = j;
			}
		}

		std::swap(arr[i], arr[minIndex]);
	}
}