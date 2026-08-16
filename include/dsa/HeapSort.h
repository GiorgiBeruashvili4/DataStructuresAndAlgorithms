#pragma once
#include <vector>
#include <algorithm>

// Heap Sort
// 
// Time complexity:
// Best case: O(n log n)
// Average case: O(n log n)
// Worst case: O(n log n)
//
// Space complexity: O(1)
// Stable: No
// In-place: Yes
//
// Builds a max-heap from array (O(n)).
// Then repeatedly swaps the root (largest element) with the last element.
// Then shrinks the heap by one and reheapifies the root to restore the max-heap property.


namespace dsa
{
	template<typename T, typename Compare = std::less<T>>
	void Heapify(std::vector<T>& arr, std::size_t size, std::size_t i, Compare compare = Compare())
	{
		std::size_t largest = i;
		std::size_t left = 2 * i + 1;
		std::size_t right = 2 * i + 2;

		if (left < size && compare(arr[largest], arr[left]))
		{
			largest = left;
		}
		if (right < size && compare(arr[largest], arr[right]))
		{
			largest = right;
		}
		if (largest != i)
		{
			std::swap(arr[i], arr[largest]);
			Heapify(arr, size, largest, compare);
		}
	}

	template<typename T, typename Compare = std::less<T>>
	void MakeHeap(std::vector<T>& arr, std::size_t size, Compare compare = Compare())
	{
		if (size < 2)
		{
			return;
		}

		std::size_t i = size / 2;
		while (i-- > 0)
		{
			Heapify(arr, size, i, compare);
		}
	}

	template<typename T, typename Compare = std::less<T>>
	void PopHeap(std::vector<T>& arr, std::size_t size, Compare compare = Compare())
	{
		std::swap(arr[0], arr[size - 1]);
		Heapify(arr, size - 1, 0, compare);
	}

	template<typename T, typename Compare = std::less<T>>
	void HeapSort(std::vector<T>& arr, Compare compare = Compare())
	{
		std::size_t size = arr.size();

		MakeHeap(arr, size, compare);

		while (size > 1)
		{
			PopHeap(arr, size--, compare);
		}
	}
}