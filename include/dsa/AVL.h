#pragma once
#include <iostream>
#include <ostream>

template<typename T>
class AVL
{
private:
	struct Node
	{
		T data;
		Node* left;
		Node* right;
		std::size_t height;

		Node(const T& value) : data(value), left(nullptr), right(nullptr), height(1) {}
	};

	Node* root;
	std::size_t count;
public:
	AVL();
	AVL(const AVL& other);
	~AVL();
	AVL& operator=(const AVL& other);
	bool operator==(const AVL& other) const;

	std::size_t size() const;
	bool empty() const;

	void insert(const T& value);
	bool remove(const T& value);
	bool contains(const T& value) const;

	void preOrder(std::ostream& out = std::cout) const;
	void inOrder(std::ostream& out = std::cout) const;
	void postOrder(std::ostream& out = std::cout) const;

	void clear();

	const T& max() const;
	const T& min() const;
private:
	Node* copy(Node* node);
	bool equals(Node* first, Node* second) const;

	std::size_t getHeight(Node* node) const;
	std::size_t getBalance(Node* node) const;
	void updateHeight(Node* node);
	Node* balance(Node* node);

	Node* leftRotate(Node* node);
	Node* rightRotate(Node* node);

	void insert(Node*& node, const T& value);
	bool remove(Node*& node, const T& value);
	bool contains(Node* node, const T& value) const;

	void preOrder(std::ostream& out, Node* node) const;
	void inOrder(std::ostream& out, Node* node) const;
	void postOrder(std::ostream& out, Node* node) const;

	void clear(Node* node);

	Node* findMin(Node* node) const;
	Node* findMax(Node* node) const;
};