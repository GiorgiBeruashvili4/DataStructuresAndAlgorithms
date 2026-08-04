#pragma once
#include <cstddef>
#include <ostream>

template<typename T>
class List
{
private:
	struct Node
	{
		T data;
		Node* next;

		Node(const T& value) : data(value), next(nullptr) {}
	};
public:
	class Iterator
	{
	public:
		Iterator(Node* node);
		T& operator*() const;
		Iterator& operator++();
		bool operator!=(const Iterator& other) const;
		bool operator==(const Iterator& other) const;
	private:
		Node* current;
	};

	class ConstIterator
	{
	public:
		ConstIterator(const Node* node);
		const T& operator*() const;
		ConstIterator& operator++();
		bool operator!=(const ConstIterator& other) const;
		bool operator==(const ConstIterator& other) const;
	private:
		const Node* current;
	};

	List();
	List(const List& other);
	~List();

	List& operator=(const List& other);

	bool empty() const;
	std::size_t size() const;

	void clear();

	void push_back(const T& value);
	void push_front(const T& value);

	void pop_back();
	void pop_front();

	void insert(const T& value, std::size_t index);

	void removeAt(std::size_t index);
	bool removeValue(const T& value);

	bool contains(const T& value) const;
	std::size_t indexOf(const T& value) const;

	void reverse();

	T& front();
	const T& front() const;

	T& back();
	const T& back() const;

	T& at(std::size_t index);
	const T& at(std::size_t index) const;

	Iterator begin();
	Iterator end();

	ConstIterator begin() const;
	ConstIterator end() const;
private:
	Node* head;
	Node* tail;
	std::size_t listSize;
};


// List
template<typename T>
inline List<T>::List()
	: head(nullptr),
	tail(nullptr),
	listSize(0)
{
}

template<typename T>
inline List<T>::List(const List& other)
	: head(nullptr),
	tail(nullptr),
	listSize(0)
{
	for (const T& value : other)
	{
		push_back(value);
	}
}

template<typename T>
inline List<T>::~List()
{
	clear();
}

template<typename T>
inline List<T>& List<T>::operator=(const List& other)
{
	if (this != &other)
	{
		clear();

		for (const T& value : other)
		{
			push_back(value);
		}
	}

	return *this;
}

template<typename T>
inline bool List<T>::empty() const
{
	return listSize == 0;
}

template<typename T>
inline std::size_t List<T>::size() const
{
	return listSize;
}

template<typename T>
inline void List<T>::clear()
{
	Node* current = head;

	while (current != nullptr)
	{
		Node* next = current->next;
		delete current;
		current = next;
	}

	head = nullptr;
	tail = nullptr;
	listSize = 0;
}

template<typename T>
inline void List<T>::push_back(const T& value)
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

	++listSize;
}

template<typename T>
inline void List<T>::push_front(const T& value)
{
	Node* newNode = new Node(value);

	if (empty())
	{
		head = newNode;
		tail = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	
	++listSize;
}

template<typename T>
inline void List<T>::pop_back()
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	if (head == tail)
	{
		delete head;
		
		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* current = head;
		while (current->next != tail)
		{
			current = current->next;
		}

		delete tail;
		tail = current;
		tail->next = nullptr;
	}

	--listSize;
}

template<typename T>
inline void List<T>::pop_front()
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	if (head == tail)
	{
		delete head;

		head = nullptr;
		tail = nullptr;
	}
	else
	{
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	--listSize;
}

template<typename T>
inline void List<T>::insert(const T& value, std::size_t index)
{
	if (index > listSize)
	{
		throw std::out_of_range("Index out of range");
	}

	if (index == 0)
	{
		push_front(value);
		return;
	}

	if (index == listSize)
	{
		push_back(value);
		return;
	}

	Node* newNode = new Node(value);
	Node* current = head;

	for (std::size_t i = 0;i < index - 1;i++)
	{
		current = current->next;
	}

	newNode->next = current->next;
	current->next = newNode;

	++listSize;
}

template<typename T>
inline void List<T>::removeAt(std::size_t index)
{
	if (index >= listSize)
	{
		throw std::out_of_range("Index out of range");
	}

	if (index == 0)
	{
		pop_front();
		return;
	}

	if (index == listSize - 1)
	{
		pop_back();
		return;
	}

	Node* current = head;

	for (std::size_t i = 0;i < index - 1;i++)
	{
		current = current->next;
	}

	Node* temp = current->next;
	current->next = temp->next;
	delete temp;

	--listSize;
}

template<typename T>
inline bool List<T>::removeValue(const T& value)
{
	if (empty())
	{
		return false;
	}

	if (head->data == value)
	{
		pop_front();
		return true;
	}

	Node* current = head;
	while (current->next != nullptr)
	{
		if (current->next->data == value)
		{
			Node* temp = current->next;
			current->next = temp->next;

			if (temp == tail)
			{
				tail = current;
			}

			delete temp;
			--listSize;

			return true;
		}

		current = current->next;
	}

	return false;
}

template<typename T>
inline bool List<T>::contains(const T& value) const
{
	return indexOf(value) != -1;
}

template<typename T>
inline std::size_t List<T>::indexOf(const T& value) const
{
	int index = 0;
	for (ConstIterator it = begin();it != end();++it, ++index)
	{
		if (*it == value)
		{
			return index;
		}
	}

	return -1;
}

template<typename T>
inline void List<T>::reverse()
{
	if (empty() || head == tail)
	{
		return;
	}

	Node* previous = nullptr;
	Node* current = head;

	tail = head;
	while (current != nullptr)
	{
		Node* next = current->next;
		current->next = previous;
		previous = current;
		current = next;
	}

	head = previous;
}

template<typename T>
inline T& List<T>::front()
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	return head->data;
}

template<typename T>
inline const T& List<T>::front() const
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	return head->data;
}

template<typename T>
inline T& List<T>::back()
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	return tail->data;
}

template<typename T>
inline const T& List<T>::back() const
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	return tail->data;
}

template<typename T>
inline T& List<T>::at(std::size_t index)
{
	if (index >= listSize)
	{
		throw std::out_of_range("Index out of range");
	}

	Node* current = head;
	for (std::size_t i = 0;i < index;++i)
	{
		current = current->next;
	}

	return current->data;
}

template<typename T>
inline const T& List<T>::at(std::size_t index) const
{
	if (index >= listSize)
	{
		throw std::out_of_range("Index out of range");
	}

	const Node* current = head;
	for (std::size_t i = 0;i < index;++i)
	{
		current = current->next;
	}

	return current->data;
}

template<typename T>
inline List<T>::Iterator List<T>::begin()
{
	return Iterator(head);
}

template<typename T>
inline List<T>::Iterator List<T>::end()
{
	return Iterator(nullptr);
}

template<typename T>
inline List<T>::ConstIterator List<T>::begin() const
{
	return ConstIterator(head);
}

template<typename T>
inline List<T>::ConstIterator List<T>::end() const
{
	return ConstIterator(nullptr);
}


// Iterator
template<typename T>
inline List<T>::Iterator::Iterator(Node* node)
	: current(node)
{
}

template<typename T>
inline T& List<T>::Iterator::operator*() const
{
	return current->data;
}

template<typename T>
inline List<T>::Iterator& List<T>::Iterator::operator++()
{
	current = current->next;
	return *this;
}

template<typename T>
inline bool List<T>::Iterator::operator!=(const Iterator& other) const
{
	return current != other.current;
}

template<typename T>
inline bool List<T>::Iterator::operator==(const Iterator& other) const
{
	return current == other.current;
}


// ConstIterator
template<typename T>
inline List<T>::ConstIterator::ConstIterator(const Node* node)
	: current(node)
{
}

template<typename T>
inline const T& List<T>::ConstIterator::operator*() const
{
	return current->data;
}

template<typename T>
inline List<T>::ConstIterator& List<T>::ConstIterator::operator++()
{
	current = current->next;
	return *this;
}

template<typename T>
inline bool List<T>::ConstIterator::operator!=(const ConstIterator& other) const
{
	return current != other.current;
}

template<typename T>
inline bool List<T>::ConstIterator::operator==(const ConstIterator& other) const
{
	return current == other.current;
}