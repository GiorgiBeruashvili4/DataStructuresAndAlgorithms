#pragma once
#include <cstddef>
#include <ostream>

template <typename T>
class DoublyLinkedList
{
private:
	struct Node
	{
		T data;
		Node* next;
		Node* previous;

		Node(const T& value) :data(value), next(nullptr), previous(nullptr) {}
	};
public:
	class Iterator
	{
	public:
		Iterator(Node* node);
		T& operator*()const;
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
		const T& operator*()const;
		ConstIterator& operator++();
		bool operator!=(const ConstIterator& other) const;
		bool operator==(const ConstIterator& other) const;
	private:
		const Node* current;
	};

	DoublyLinkedList();
	DoublyLinkedList(const DoublyLinkedList& other);
	DoublyLinkedList(DoublyLinkedList&& other) noexcept;
	~DoublyLinkedList();

	DoublyLinkedList& operator=(const DoublyLinkedList& other);
	DoublyLinkedList& operator=(DoublyLinkedList&& other) noexcept;

	bool empty() const;
	std::size_t size() const;

	void clear();

	void push_front(const T& value);
	void push_back(const T& value);

	void pop_front();
	void pop_back();

	void insert(const T& value, std::size_t index);

	void removeAt(std::size_t index);
	bool removeValue(const T& value);

	bool contains(const T& value) const;
	int indexOf(const T& value) const;

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


// list
template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList()
	:head(nullptr),
	tail(nullptr),
	listSize(0)
{
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(const DoublyLinkedList& other)
	:head(nullptr),
	tail(nullptr),
	listSize(0)
{
	for (const T& value : other)
	{
		push_back(value);
	}
}

template<typename T>
inline DoublyLinkedList<T>::DoublyLinkedList(DoublyLinkedList&& other) noexcept
	:head(other.head),
	tail(other.tail),
	listSize(other.listSize)
{
	other.head = nullptr;
	other.tail = nullptr;
	other.listSize = 0;
}

template<typename T>
inline DoublyLinkedList<T>::~DoublyLinkedList()
{
	clear();
}

template<typename T>
inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(const DoublyLinkedList& other)
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
inline DoublyLinkedList<T>& DoublyLinkedList<T>::operator=(DoublyLinkedList&& other) noexcept
{
	if (this != &other)
	{
		clear();

		head = other.head;
		tail = other.tail;
		listSize = other.listSize;

		other.head = nullptr;
		other.tail = nullptr;
		other.listSize = 0;
	}

	return *this;
}

template<typename T>
inline bool DoublyLinkedList<T>::empty() const
{
	return listSize == 0;
}

template<typename T>
inline std::size_t DoublyLinkedList<T>::size() const
{
	return listSize;
}

template<typename T>
inline void DoublyLinkedList<T>::clear()
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
inline void DoublyLinkedList<T>::push_front(const T& value)
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
		head->previous = newNode;
		head = newNode;
	}

	++listSize;
}

template<typename T>
inline void DoublyLinkedList<T>::push_back(const T& value)
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
		newNode->previous = tail;
		tail = newNode;
	}

	++listSize;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_front()
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
		head->previous = nullptr;
		delete temp;
	}

	--listSize;
}

template<typename T>
inline void DoublyLinkedList<T>::pop_back()
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
		Node* temp = tail;
		tail = tail->previous;
		tail->next = nullptr;
		delete temp;
	}

	--listSize;
}

template<typename T>
inline void DoublyLinkedList<T>::insert(const T& value, std::size_t index)
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

	Node* nextNode = current->next;

	newNode->next = nextNode;
	newNode->previous = current;
	current->next = newNode;
	nextNode->previous = newNode;

	++listSize;
}

template<typename T>
inline void DoublyLinkedList<T>::removeAt(std::size_t index)
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
	temp->next->previous = current;
	delete temp;

	--listSize;
}

template<typename T>
inline bool DoublyLinkedList<T>::removeValue(const T& value)
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
			else
			{
				temp->next->previous = current;
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
inline bool DoublyLinkedList<T>::contains(const T& value) const
{
	return indexOf(value) != -1;
}

template<typename T>
inline int DoublyLinkedList<T>::indexOf(const T& value) const
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
inline void DoublyLinkedList<T>::reverse()
{
	if (empty() || head == tail)
	{
		return;
	}

	Node* current = head;
	while (current != nullptr)
	{
		Node* next = current->next;
		current->next = current->previous;
		current->previous = next;
		current = next;
	}

	Node* oldHead = head;
	head = tail;
	tail = oldHead;
}

template<typename T>
inline T& DoublyLinkedList<T>::front()
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	return head->data;
}

template<typename T>
inline const T& DoublyLinkedList<T>::front() const
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	return head->data;
}

template<typename T>
inline T& DoublyLinkedList<T>::back()
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	return tail->data;
}

template<typename T>
inline const T& DoublyLinkedList<T>::back() const
{
	if (empty())
	{
		throw std::out_of_range("List is empty");
	}

	return tail->data;
}

template<typename T>
inline T& DoublyLinkedList<T>::at(std::size_t index)
{
	if (index >= listSize)
	{
		throw std::out_of_range("Index out of range");
	}

	if (index < listSize / 2)
	{
		Node* current = head;
		for (std::size_t i = 0;i < index;++i)
		{
			current = current->next;
		}

		return current->data;
	}
	else
	{
		Node* current = tail;
		for (std::size_t i = listSize - 1;i > index;--i)
		{
			current = current->previous;
		}

		return current->data;
	}
}

template<typename T>
inline const T& DoublyLinkedList<T>::at(std::size_t index) const
{
	if (index >= listSize)
	{
		throw std::out_of_range("Index out of range");
	}

	if (index < listSize / 2)
	{
		const Node* current = head;
		for (std::size_t i = 0;i < index;++i)
		{
			current = current->next;
		}

		return current->data;
	}
	else
	{
		const Node* current = tail;
		for (std::size_t i = listSize - 1;i > index;--i)
		{
			current = current->previous;
		}

		return current->data;
	}
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::begin()
{
	return Iterator(head);
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator DoublyLinkedList<T>::end()
{
	return Iterator(nullptr);
}

template<typename T>
inline typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::begin() const
{
	return ConstIterator(head);
}

template<typename T>
inline typename DoublyLinkedList<T>::ConstIterator DoublyLinkedList<T>::end() const
{
	return ConstIterator(nullptr);
}


// Iterator
template<typename T>
inline DoublyLinkedList<T>::Iterator::Iterator(Node* node)
	:current(node)
{
}

template<typename T>
inline T& DoublyLinkedList<T>::Iterator::operator*() const
{
	return current->data;
}

template<typename T>
inline typename DoublyLinkedList<T>::Iterator& DoublyLinkedList<T>::Iterator::operator++()
{
	current = current->next;
	return *this;
}

template<typename T>
inline bool DoublyLinkedList<T>::Iterator::operator!=(const Iterator& other) const
{
	return current != other.current;
}

template<typename T>
inline bool DoublyLinkedList<T>::Iterator::operator==(const Iterator& other) const
{
	return current == other.current;
}


// ConstIterator
template<typename T>
inline DoublyLinkedList<T>::ConstIterator::ConstIterator(const Node* node)
	:current(node)
{
}

template<typename T>
inline const T& DoublyLinkedList<T>::ConstIterator::operator*() const
{
	return current->data;
}

template<typename T>
inline typename DoublyLinkedList<T>::ConstIterator& DoublyLinkedList<T>::ConstIterator::operator++()
{
	current = current->next;
	return *this;
}

template<typename T>
inline bool DoublyLinkedList<T>::ConstIterator::operator!=(const ConstIterator& other) const
{
	return current != other.current;
}

template<typename T>
inline bool DoublyLinkedList<T>::ConstIterator::operator==(const ConstIterator& other) const
{
	return current == other.current;
}