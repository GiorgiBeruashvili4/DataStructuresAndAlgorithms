#pragma once
#include <cstddef>
#include <stdexcept>

namespace dsa
{
	template<typename T>
	class Stack
	{
	private:
		struct Node
		{
			T data;
			Node* next;
			Node(const T& value) : data(value), next(nullptr) {}
		};
	public:
		Stack();
		Stack(const Stack& other);
		~Stack();
		Stack& operator=(const Stack& other);

		bool empty() const;
		std::size_t size() const;

		void clear();

		void push(const T& value);
		void pop();

		T& peek();
		const T& peek() const;
	private:
		Node* top;
		std::size_t stackSize;
	};

	template<typename T>
	inline Stack<T>::Stack() : top(nullptr), stackSize(0)
	{
	}

	template<typename T>
	inline Stack<T>::Stack(const Stack& other)
		: top(nullptr), stackSize(0)
	{
		if (this == &other || other.empty())
		{
			return;
		}

		this->top = new Node(other.top->data);
		Node* thisCurrent = this->top;
		Node* otherCurrent = other.top->next;

		while (otherCurrent != nullptr)
		{
			thisCurrent->next = new Node(otherCurrent->data);
			thisCurrent = thisCurrent->next;
			otherCurrent = otherCurrent->next;
		}

		this->stackSize = other.stackSize;
	}

	template<typename T>
	inline Stack<T>::~Stack()
	{
		clear();
	}

	template<typename T>
	inline Stack<T>& Stack<T>::operator=(const Stack& other)
	{
		if (this != &other)
		{
			clear();

			if (!other.empty())
			{
				top = new Node(other.top->data);
				Node* thisCurrent = top;
				Node* otherCurrent = other.top->next;

				while (otherCurrent != nullptr)
				{
					thisCurrent->next = new Node(otherCurrent->data);
					thisCurrent = thisCurrent->next;
					otherCurrent = otherCurrent->next;
				}

				stackSize = other.stackSize;
			}
		}

		return *this;
	}

	template<typename T>
	inline bool Stack<T>::empty() const
	{
		return stackSize == 0;
	}

	template<typename T>
	inline std::size_t Stack<T>::size() const
	{
		return stackSize;
	}

	template<typename T>
	inline void Stack<T>::clear()
	{
		Node* current = top;
		while (current != nullptr)
		{
			Node* nextNode = current->next;
			delete current;
			current = nextNode;
		}

		top = nullptr;
		stackSize = 0;
	}

	template<typename T>
	inline void Stack<T>::push(const T& value)
	{
		Node* newNode = new Node(value);
		newNode->next = top;
		top = newNode;
		++stackSize;
	}

	template<typename T>
	inline void Stack<T>::pop()
	{
		if (empty())
		{
			throw std::out_of_range("Stack is empty");
		}

		Node* temp = top->next;
		delete top;
		top = temp;
		--stackSize;
	}

	template<typename T>
	inline T& Stack<T>::peek()
	{
		if (empty())
		{
			throw std::out_of_range("Stack is empty");
		}

		return top->data;
	}

	template<typename T>
	inline const T& Stack<T>::peek() const
	{
		if (empty())
		{
			throw std::out_of_range("Stack is empty");
		}

		return top->data;
	}
}