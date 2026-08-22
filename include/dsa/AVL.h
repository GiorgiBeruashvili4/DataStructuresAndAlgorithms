#pragma once
#include <iostream>
#include <ostream>
#include <stdexcept>
#include <algorithm>

namespace dsa
{
	template<typename T>
	class AVL
	{
	private:
		struct Node
		{
			T data;
			Node* left;
			Node* right;
			int height;

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

		int getHeight(Node* node) const;
		int getBalance(Node* node) const;
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

	template<typename T>
	inline AVL<T>::AVL() : root(nullptr), count(0)
	{
	}

	template<typename T>
	inline AVL<T>::AVL(const AVL& other)
		: root(copy(other.root)), count(other.count)
	{
	}

	template<typename T>
	inline AVL<T>::~AVL()
	{
		clear();
	}

	template<typename T>
	inline AVL<T>& AVL<T>::operator=(const AVL& other)
	{
		if (this == &other)
		{
			return *this;
		}

		clear();
		root = copy(other.root);
		count = other.count;

		return *this;
	}

	template<typename T>
	inline bool AVL<T>::operator==(const AVL& other) const
	{
		return equals(root, other.root);
	}

	template<typename T>
	inline std::size_t AVL<T>::size() const
	{
		return count;
	}

	template<typename T>
	inline bool AVL<T>::empty() const
	{
		return count == 0;
	}

	template<typename T>
	inline void AVL<T>::insert(const T& value)
	{
		insert(root, value);
	}

	template<typename T>
	inline bool AVL<T>::remove(const T& value)
	{
		return remove(root, value);
	}

	template<typename T>
	inline bool AVL<T>::contains(const T& value) const
	{
		return contains(root, value);
	}

	template<typename T>
	inline void AVL<T>::preOrder(std::ostream& out) const
	{
		preOrder(out, root);
	}

	template<typename T>
	inline void AVL<T>::inOrder(std::ostream& out) const
	{
		inOrder(out, root);
	}

	template<typename T>
	inline void AVL<T>::postOrder(std::ostream& out) const
	{
		postOrder(out, root);
	}

	template<typename T>
	inline void AVL<T>::clear()
	{
		clear(root);
		root = nullptr;
		count = 0;
	}

	template<typename T>
	inline const T& AVL<T>::max() const
	{
		if (empty())
		{
			throw std::runtime_error("AVL is empty");
		}

		return findMax(root)->data;
	}

	template<typename T>
	inline const T& AVL<T>::min() const
	{
		if (empty())
		{
			throw std::runtime_error("AVL is empty");
		}

		return findMin(root)->data;
	}

	template<typename T>
	inline typename AVL<T>::Node* AVL<T>::copy(Node* node)
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
	inline bool AVL<T>::equals(Node* first, Node* second) const
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
	inline int AVL<T>::getHeight(Node* node) const
	{
		return node == nullptr ? 0 : node->height;
	}

	template<typename T>
	inline int AVL<T>::getBalance(Node* node) const
	{
		if (node == nullptr)
		{
			return 0;
		}

		return getHeight(node->left) - getHeight(node->right);
	}

	template<typename T>
	inline void AVL<T>::updateHeight(Node* node)
	{
		if (node == nullptr)
		{
			return;
		}

		node->height = std::max(getHeight(node->left), getHeight(node->right)) + 1;
	}

	template<typename T>
	inline typename AVL<T>::Node* AVL<T>::balance(Node* node)
	{
		if (node == nullptr)
		{
			return nullptr;
		}

		updateHeight(node);
		int balanceFactor = getBalance(node);

		// left heavy
		if (balanceFactor > 1)
		{
			if (getBalance(node->left) < 0)
			{
				// LR case
				node->left = leftRotate(node->left);
			}

			// LL case
			return rightRotate(node);
		}

		// right heavy
		if (balanceFactor < -1)
		{
			if (getBalance(node->right) > 0)
			{
				// RL case
				node->right = rightRotate(node->right);
			}

			// RR case
			return leftRotate(node);
		}

		return node;
	}

	template<typename T>
	inline void AVL<T>::insert(Node*& node, const T& value)
	{
		if (node == nullptr)
		{
			node = new Node(value);
			++count;
			return;
		}

		if (value < node->data)
		{
			insert(node->left, value);
		}
		else if (node->data < value)
		{
			insert(node->right, value);
		}
		else
		{
			return;
		}

		node = balance(node);
	}

	template<typename T>
	inline bool AVL<T>::remove(Node*& node, const T& value)
	{
		if (node == nullptr)
		{
			return false;
		}

		bool removed = false;

		if (value < node->data)
		{
			removed = remove(node->left, value);
		}
		else if (node->data < value)
		{
			removed = remove(node->right, value);
		}
		else
		{
			if (node->left != nullptr && node->right != nullptr)
			{
				Node* predecessor = node->left;

				while (predecessor->right != nullptr)
				{
					predecessor = predecessor->right;
				}

				node->data = predecessor->data;

				removed = remove(node->left, predecessor->data);
			}
			else
			{
				Node* toDelete = node;
				node = (node->left != nullptr) ? node->left : node->right;

				delete toDelete;
				--count;
				removed = true;

				if (node == nullptr)
				{
					return true;
				}
			}
		}

		node = balance(node);
		return removed;
	}

	template<typename T>
	inline bool AVL<T>::contains(Node* node, const T& value) const
	{
		if (node == nullptr)
		{
			return false;
		}

		if (value < node->data)
		{
			return contains(node->left, value);
		}
		else if (node->data < value)
		{
			return contains(node->right, value);
		}
		else
		{
			return true;
		}
	}

	template<typename T>
	inline void AVL<T>::preOrder(std::ostream& out, Node* node) const
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
	inline void AVL<T>::inOrder(std::ostream& out, Node* node) const
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
	inline void AVL<T>::postOrder(std::ostream& out, Node* node) const
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
	inline void AVL<T>::clear(Node* node)
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
	inline typename AVL<T>::Node* AVL<T>::findMin(Node* node) const
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
	inline typename AVL<T>::Node* AVL<T>::findMax(Node* node) const
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

	template<typename T>
	inline typename AVL<T>::Node* AVL<T>::leftRotate(Node* node)
	{
		if (node == nullptr || node->right == nullptr)
		{
			return node;
		}
		
		Node* temp = node->right;
		node->right = temp->left;
		temp->left = node;

		updateHeight(node);
		updateHeight(temp);

		return temp;
	}

	template<typename T>
	inline typename AVL<T>::Node* AVL<T>::rightRotate(Node* node)
	{
		if (node == nullptr || node->left == nullptr)
		{
			return node;
		}

		Node* temp = node->left;
		node->left = temp->right;
		temp->right = node;

		updateHeight(node);
		updateHeight(temp);

		return temp;
	}
}