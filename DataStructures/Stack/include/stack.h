#pragma once
#include <cstddef>

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

	Node* topNode;
	std::size_t stackSize;
public:
	Stack();
	Stack(const Stack& other);
	~Stack();
	Stack& operator=(const Stack& other);

	bool empty() const;
	std::size_t size() const;
	
	void clear();

	void push(const T& value);
	bool pop();

	T& top();
	const T& top() const;
};