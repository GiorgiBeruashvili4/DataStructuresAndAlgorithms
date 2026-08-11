# BST — Binary Search Tree

A templated, header-only Binary Search Tree implementation in C++, supporting both
iterative and recursive variants of core operations.

## Features

- **Generic**: works with any type `T` that supports `operator<`
- **Rule of Three**: copy constructor, copy assignment and destructor
- **Equality comparison**: structural + value comparison via `operator==`
- **Dual implementations**: insert, remove and contains are each available in
  iterative and recursive forms
- **Traversals**: pre-order, in-order and post-order
- **Tree metrics**: `size()`, `height()`, `empty()`
- **Min/Max**: `min()` and `max()` retrieve the smallest/largest element

## API Reference

### Constructors / Destructor
| Method | Description |
|---|---|
| `BST()` | Creates an empty tree |
| `BST(const BST& other)` | Deep-copies another tree |
| `~BST()` | Frees all nodes |
| `operator=(const BST& other)` | Deep-copy assignment |
| `operator==(const BST& other) const` | Structural + value equality |

### Insertion
| Method | Description |
|---|---|
| `insertIterative(const T& value)` | Inserts a value using an iterative loop |
| `insertRecursive(const T& value)` | Inserts a value using recursion |

### Removal
| Method | Description |
|---|---|
| `removeIterative(const T& value)` | Removes a value iteratively; returns `true` if found and removed |
| `removeRecursive(const T& value)` | Removes a value recursively; returns `true` if found and removed |

Both use the **in-order predecessor** strategy for nodes with two children.

### Search
| Method | Description |
|---|---|
| `containsIterative(const T& value) const` | Iterative lookup |
| `containsRecursive(const T& value) const` | Recursive lookup |

### Traversal
| Method | Description |
|---|---|
| `preOrder(std::ostream& out = std::cout) const` | Root → Left → Right |
| `inOrder(std::ostream& out = std::cout) const` | Left → Root → Right (sorted order) |
| `postOrder(std::ostream& out = std::cout) const` | Left → Right → Root |

### Utilities
| Method | Description |
|---|---|
| `size() const` | Number of nodes |
| `height() const` | Height of the tree (0 for empty, 1 for single node) |
| `empty() const` | Whether the tree has no nodes |
| `clear()` | Removes all nodes |
| `min() const` | Smallest value; throws `std::runtime_error` if empty |
| `max() const` | Largest value; throws `std::runtime_error` if empty |

## Complexity

| Operation | Average | Worst Case |
|---|---|---|
| Insert | O(log n) | O(n) |
| Remove | O(log n) | O(n) |
| Search | O(log n) | O(n) |
| Min / Max | O(log n) | O(n) |

Worst case occurs when the tree degenerates into a linked list (e.g., inserting
sorted data), since this implementation does not self-balance.

## Usage

```cpp
#include "BST.h"
#include <iostream>

int main()
{
    BST<int> tree;

    tree.insertRecursive(50);
    tree.insertRecursive(30);
    tree.insertRecursive(70);
    tree.insertRecursive(20);

    std::cout << "In-order: ";
    tree.inOrder();
    std::cout << "\n";

    std::cout << "Contains 20: " << tree.containsIterative(20) << "\n";
    std::cout << "Min: " << tree.min() << ", Max: " << tree.max() << "\n";
    std::cout << "Size: " << tree.size() << ", Height: " << tree.height() << "\n";

    tree.removeRecursive(30);
    std::cout << "After removing 30, in-order: ";
    tree.inOrder();
    std::cout << "\n";
}
```