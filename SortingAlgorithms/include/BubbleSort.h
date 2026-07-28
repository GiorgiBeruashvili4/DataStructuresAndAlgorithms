#pragma once
#include <vector>
#include <algorithm>

// Bubble Sort
// 
// Time complexity:
// Best case: O(n) -> If array is already sorted
// Average case: O(n²)
// Worst case: O(n²) -> If array is sorted in reverse order
//
// Space complexity: O(1)
// Stable: Yes
// In-place: Yes

template<typename T>
void BubbleSort(std::vector<T>& arr)
{
	const std::size_t size = arr.size();

	for (std::size_t i = 0;i + 1 < size;++i)
	{
		bool swapped = false;
		for (std::size_t j = 0;j + 1 < size - i;++j)
		{
			if (arr[j + 1] < arr[j])
			{
				std::swap(arr[j], arr[j + 1]);
				swapped = true;
			}
		}

		if (!swapped)
		{
			break;
		}
	}
}