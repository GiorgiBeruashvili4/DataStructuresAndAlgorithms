#pragma once
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <algorithm>

namespace dsa
{
	template<typename T>
	class BST
	{
	private:
		struct Node
		{
			T data;
			Node* left;
			Node* right;
			Node(const T& value) :data(value), left(nullptr), right(nullptr) {}
		};

		Node* root;
	public:
		BST();
		BST(const BST& other);

		~BST();

		BST& operator=(const BST& other);
		bool operator==(const BST& other) const;

		void insertIterative(const T& value);
		bool removeIterative(const T& value);
		bool containsIterative(const T& value) const;

		void insertRecursive(const T& value);
		bool removeRecursive(const T& value);
		bool containsRecursive(const T& value) const;

		void preOrder(std::ostream& out = std::cout) const;
		void inOrder(std::ostream& out = std::cout) const;
		void postOrder(std::ostream& out = std::cout) const;

		std::size_t size() const;
		std::size_t height() const;
		bool empty() const;

		void clear();

		const T& min() const;
		const T& max() const;
	private:
		Node* copy(Node* node);

		bool equals(Node* first, Node* second) const;

		void insertIterative(Node*& node, const T& value);
		bool removeIterative(Node*& node, const T& value);
		bool containsIterative(Node* node, const T& value) const;

		void insertRecursive(Node*& node, const T& value);
		bool removeRecursive(Node*& node, const T& value);
		bool containsRecursive(Node* node, const T& value) const;

		void preOrder(std::ostream& out, Node* node) const;
		void inOrder(std::ostream& out, Node* node) const;
		void postOrder(std::ostream& out, Node* node) const;

		std::size_t size(Node* node) const;
		std::size_t height(Node* node) const;

		void clear(Node* node);

		Node* findMin(Node* node) const;
		Node* findMax(Node* node) const;
	};

	template<typename T>
	inline BST<T>::BST() : root(nullptr)
	{
	}

	template<typename T>
	inline BST<T>::BST(const BST& other)
		: root(copy(other.root))
	{
	}

	template<typename T>
	inline BST<T>::~BST()
	{
		clear();
	}

	template<typename T>
	inline BST<T>& BST<T>::operator=(const BST& other)
	{
		if (this == &other)
		{
			return *this;
		}

		clear();
		root = copy(other.root);

		return *this;
	}

	template<typename T>
	inline bool BST<T>::operator==(const BST& other) const
	{
		return equals(root, other.root);
	}

	template<typename T>
	inline void BST<T>::insertIterative(const T& value)
	{
		insertIterative(root, value);
	}

	template<typename T>
	inline bool BST<T>::removeIterative(const T& value)
	{
		return removeIterative(root, value);
	}

	template<typename T>
	inline bool BST<T>::containsIterative(const T& value) const
	{
		return containsIterative(root, value);
	}

	template<typename T>
	inline void BST<T>::insertRecursive(const T& value)
	{
		insertRecursive(root, value);
	}

	template<typename T>
	inline bool BST<T>::removeRecursive(const T& value)
	{
		return removeRecursive(root, value);
	}

	template<typename T>
	inline bool BST<T>::containsRecursive(const T& value) const
	{
		return containsRecursive(root, value);
	}

	template<typename T>
	inline void BST<T>::preOrder(std::ostream& out) const
	{
		preOrder(out, root);
	}

	template<typename T>
	inline void BST<T>::inOrder(std::ostream& out) const
	{
		inOrder(out, root);
	}

	template<typename T>
	inline void BST<T>::postOrder(std::ostream& out) const
	{
		postOrder(out, root);
	}

	template<typename T>
	inline std::size_t BST<T>::size() const
	{
		return size(root);
	}

	template<typename T>
	inline std::size_t BST<T>::height() const
	{
		return height(root);
	}

	template<typename T>
	inline bool BST<T>::empty() const
	{
		return root == nullptr;
	}

	template<typename T>
	inline void BST<T>::clear()
	{
		clear(root);
		root = nullptr;
	}

	template<typename T>
	inline const T& BST<T>::min() const
	{
		if (empty())
		{
			throw std::runtime_error("BST is empty");
		}

		return findMin(root)->data;
	}

	template<typename T>
	inline const T& BST<T>::max() const
	{
		if (empty())
		{
			throw std::runtime_error("BST is empty");
		}

		return findMax(root)->data;
	}

	template<typename T>
	inline typename BST<T>::Node* BST<T>::copy(Node* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		Node* newNode = new Node(node->data);
		newNode->left = copy(node->left);
		newNode->right = copy(node->right);

		return newNode;
	}

	template<typename T>
	inline bool BST<T>::equals(Node* first, Node* second) const
	{
		if (first == nullptr && second == nullptr)
		{
			return true;
		}

		if (first == nullptr || second == nullptr)
		{
			return false;
		}

		return first->data == second->data &&
			equals(first->left, second->left) &&
			equals(first->right, second->right);
	}

	template<typename T>
	inline void BST<T>::insertIterative(Node*& node, const T& value)
	{
		Node* current = node;
		Node* parent = nullptr;

		while (current != nullptr)
		{
			parent = current;
			if (value < current->data)
			{
				current = current->left;
			}
			else if (current->data < value)
			{
				current = current->right;
			}
			else
			{
				return;
			}
		}

		current = new Node(value);

		if (parent == nullptr)
		{
			node = current;
		}
		else if (value < parent->data)
		{
			parent->left = current;
		}
		else
		{
			parent->right = current;
		}
	}

	template<typename T>
	inline bool BST<T>::removeIterative(Node*& node, const T& value)
	{
		Node* current = node;
		Node* parent = nullptr;

		while (current != nullptr)
		{
			parent = current;
			if (value < current->data)
			{
				current = current->left;
			}
			else if (current->data < value)
			{
				current = current->right;
			}
			else
			{
				break;
			}
		}

		if (current == nullptr)
		{
			return false;
		}

		// two children case
		if (current->left != nullptr && current->right != nullptr)
		{
			Node* successor = current->left;
			Node* successorParent = current;

			while (successor->right != nullptr)
			{
				successorParent = successor;
				successor = successor->right;
			}

			current->data = successor->data;

			if (successorParent->right == successor)
			{
				successorParent->right = successor->left;
			}
			else
			{
				successorParent->left = successor->left;
			}

			delete successor;
			return true;
		}

		// zero or one child case
		Node* child = (current->left != nullptr) ? current->left : current->right;

		if (parent == nullptr)
		{
			node = child;
		}
		else if (parent->left == current)
		{
			parent->left = child;
		}
		else
		{
			parent->right = child;
		}

		delete current;
		return true;
	}

	template<typename T>
	inline bool BST<T>::containsIterative(Node* node, const T& value) const
	{
		Node* current = node;
		while (current != nullptr)
		{
			if (value < current->data)
			{
				current = current->left;
			}
			else if (current->data < value)
			{
				current = current->right;
			}
			else
			{
				return true;
			}
		}

		return false;
	}

	template<typename T>
	inline void BST<T>::insertRecursive(Node*& node, const T& value)
	{
		if (node == nullptr)
		{
			node = new Node(value);
			return;
		}

		if (value < node->data)
		{
			insertRecursive(node->left, value);
		}
		else if (node->data < value)
		{
			insertRecursive(node->right, value);
		}
		else
		{
			return;
		}
	}

	template<typename T>
	inline bool BST<T>::removeRecursive(Node*& node, const T& value)
	{
		if (node == nullptr)
		{
			return false;
		}

		if (value < node->data)
		{
			return removeRecursive(node->left, value);
		}
		else if (node->data < value)
		{
			return removeRecursive(node->right, value);
		}

		if (node->left != nullptr && node->right != nullptr)
		{
			Node* successor = node->left;

			while (successor->right != nullptr)
			{
				successor = successor->right;
			}

			node->data = successor->data;

			return removeRecursive(node->left, successor->data);
		}

		Node* toDelete = node;
		node = (node->left != nullptr) ? node->left : node->right;

		delete toDelete;

		return true;
	}

	template<typename T>
	inline bool BST<T>::containsRecursive(Node* node, const T& value) const
	{
		if (node == nullptr)
		{
			return false;
		}

		if (value < node->data)
		{
			return containsRecursive(node->left, value);
		}
		else if (node->data < value)
		{
			return containsRecursive(node->right, value);
		}
		else
		{
			return true;
		}
	}

	template<typename T>
	inline void BST<T>::preOrder(std::ostream& out, Node* node) const
	{
		if (node == nullptr)
		{
			return;
		}

		out << node->data << " ";
		preOrder(out, node->left);
		preOrder(out, node->right);
	}

	template<typename T>
	inline void BST<T>::inOrder(std::ostream& out, Node* node) const
	{
		if (node == nullptr)
		{
			return;
		}

		inOrder(out, node->left);
		out << node->data << " ";
		inOrder(out, node->right);
	}

	template<typename T>
	inline void BST<T>::postOrder(std::ostream& out, Node* node) const
	{
		if (node == nullptr)
		{
			return;
		}

		postOrder(out, node->left);
		postOrder(out, node->right);
		out << node->data << " ";
	}

	template<typename T>
	inline std::size_t BST<T>::size(Node* node) const
	{
		if (node == nullptr)
		{
			return 0;
		}

		return size(node->left) + size(node->right) + 1;
	}

	template<typename T>
	inline std::size_t BST<T>::height(Node* node) const
	{
		if (node == nullptr)
		{
			return 0;
		}

		return std::max(height(node->left), height(node->right)) + 1;
	}

	template<typename T>
	inline void BST<T>::clear(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		clear(node->left);
		clear(node->right);
		delete node;
	}

	template<typename T>
	inline typename BST<T>::Node* BST<T>::findMin(Node* node) const
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		while (node->left != nullptr)
		{
			node = node->left;
		}

		return node;
	}

	template<typename T>
	inline typename BST<T>::Node* BST<T>::findMax(Node* node) const
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		while (node->right != nullptr)
		{
			node = node->right;
		}

		return node;
	}
}