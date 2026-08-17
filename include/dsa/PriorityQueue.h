#pragma once
#include <vector>
#include <algorithm>
#include <stdexcept>

namespace dsa
{
	template<typename T, typename Compare = std::less<T>>
	class PriorityQueue
	{
	private:
		std::vector<T> heap;
		Compare compare;

		void heapifyUp(std::size_t index);
		void heapifyDown(std::size_t index);
		std::size_t parent(std::size_t i);
		std::size_t leftChild(std::size_t i);
		std::size_t rightChild(std::size_t i);
	public:
		void push(const T& value);
		void pop();

		bool empty() const;
		std::size_t size() const;

		const T& top() const;
	};

	template<typename T, typename Compare>
	inline void PriorityQueue<T, Compare>::heapifyUp(std::size_t index)
	{
		while (index > 0 && compare(heap[parent(index)], heap[index]))
		{
			std::swap(heap[parent(index)], heap[index]);
			index = parent(index);
		}
	}

	template<typename T, typename Compare>
	inline void PriorityQueue<T, Compare>::heapifyDown(std::size_t index)
	{
		while (true)
		{
			std::size_t left = leftChild(index);
			std::size_t right = rightChild(index);
			std::size_t target = index;

			if (left < size() && compare(heap[target], heap[left]))
			{
				target = left;
			}
			if (right < size() && compare(heap[target], heap[right]))
			{
				target = right;
			}
			if (target == index)
			{
				break;
			}

			std::swap(heap[target], heap[index]);
			index = target;
		}
	}

	template<typename T, typename Compare>
	inline std::size_t PriorityQueue<T, Compare>::parent(std::size_t i)
	{
		return (i - 1) / 2;
	}

	template<typename T, typename Compare>
	inline std::size_t PriorityQueue<T, Compare>::leftChild(std::size_t i)
	{
		return 2 * i + 1;
	}

	template<typename T, typename Compare>
	inline std::size_t PriorityQueue<T, Compare>::rightChild(std::size_t i)
	{
		return 2 * i + 2;
	}

	template<typename T, typename Compare>
	inline void PriorityQueue<T, Compare>::push(const T& value)
	{
		heap.push_back(value);
		heapifyUp(size() - 1);
	}

	template<typename T, typename Compare>
	inline void PriorityQueue<T, Compare>::pop()
	{
		if (empty())
		{
			throw std::out_of_range("Priority Queue is empty");
		}

		std::swap(heap[0], heap[size() - 1]);
		heap.pop_back();
		heapifyDown(0);
	}

	template<typename T, typename Compare>
	inline bool PriorityQueue<T, Compare>::empty() const
	{
		return size() == 0;
	}

	template<typename T, typename Compare>
	inline std::size_t PriorityQueue<T, Compare>::size() const
	{
		return heap.size();
	}

	template<typename T, typename Compare>
	inline const T& PriorityQueue<T, Compare>::top() const
	{
		if (empty())
		{
			throw std::out_of_range("Priority Queue is empty");
		}

		return heap[0];
	}
}