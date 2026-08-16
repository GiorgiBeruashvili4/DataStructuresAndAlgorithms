#pragma once
#include <cstddef>
#include <stdexcept>

template<typename T>
class Queue
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node(const T& value) : data(value), next(nullptr) {}
	};
public:
	Queue();
	Queue(const Queue& other);
	~Queue();
	Queue& operator=(const Queue& other);

	bool empty() const;
	std::size_t size() const;

	void clear();

	void enqueue(const T& value);
	void dequeue();

	T& front();
	const T& front() const;
private:
	Node* head;
	Node* tail;
	std::size_t queueSize;
};

template<typename T>
inline Queue<T>::Queue() 
	: head(nullptr), tail(nullptr), queueSize(0)
{
}

template<typename T>
inline Queue<T>::Queue(const Queue& other)
	: head(nullptr), tail(nullptr), queueSize(0)
{
	if (this != &other)
	{
		Node* current = other.head;
		while (current != nullptr)
		{
			enqueue(current->data);
			current = current->next;
		}
	}
}

template<typename T>
inline Queue<T>::~Queue()
{
	clear();
}

template<typename T>
inline Queue<T>& Queue<T>::operator=(const Queue& other)
{
	if (this != &other)
	{
		clear();

		Node* current = other.head;
		while (current != nullptr)
		{
			enqueue(current->data);
			current = current->next;
		}
	}

	return *this;
}

template<typename T>
inline bool Queue<T>::empty() const
{
	return queueSize == 0;
}

template<typename T>
inline std::size_t Queue<T>::size() const
{
	return queueSize;
}

template<typename T>
inline void Queue<T>::clear()
{
	Node* current = head;
	while (current != nullptr)
	{
		Node* nextNode = current->next;
		delete current;
		current = nextNode;
	}

	head = nullptr;
	tail = nullptr;
	queueSize = 0;
}

template<typename T>
inline void Queue<T>::enqueue(const T& value)
{
	Node* newNode = new Node(value);

	if (empty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		tail->next = newNode;
		tail = newNode;
	}

	++queueSize;
}

template<typename T>
inline void Queue<T>::dequeue()
{
	if (empty())
	{
		throw std::out_of_range("Queue is empty");
	}

	Node* temp = head->next;
	delete head;
	head = temp;

	if (head == nullptr)
	{
		tail = nullptr;
	}

	--queueSize;
}

template<typename T>
inline T& Queue<T>::front()
{
	if (empty())
	{
		throw std::out_of_range("Queue is empty");
	}

	return head->data;
}

template<typename T>
inline const T& Queue<T>::front() const
{
	if (empty())
	{
		throw std::out_of_range("Queue is empty");
	}

	return head->data;
}