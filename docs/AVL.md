# AVL — Self-Balancing Binary Search Tree

A templated, header-only AVL Tree implementation in C++. Automatically
rebalances on isertion and removal to guarantee O(log n) height at all times.

## Features

- **Generic**: works with any type `T` that supports `operator<`
- **Rule of Three**: copy constructor, copy assignment and destructor
- **Equality comparison**: structural + value comparison via `operator==`
- **Self-Balancing**: automatic rotations (LL, LR, RR, RL) keeps the tree balanced after every insert and remove
- **Traversals**: pre-order, in-order and post-order
- **Tree metrics**: `size()`, `empty()`
- **Min/Max**: `min()` and `max()` retrieve the smallest/largest element

## API Reference

| Method | Description |
|---|---|
| `AVL()` | Creates an empty tree |
| `AVL(const AVL& other)` | Deep-copies another tree |
| `~AVL()` | Frees all nodes |
| `operator=(const AVL& other)` | Deep-copy assignment |
| `operator==(const AVL& other) const` | Structural + value equality |
| `insert(const T& value)` | Inserts a value and rebalances the tree if needed |
| `remove(const T& value)` | Removes a value and rebalances the tree; returns `true` if found and removed |
| `contains(const T& value) const` | Recursive lookup |
| `preOrder(std::ostream& out = std::cout) const` | Root → Left → Right |
| `inOrder(std::ostream& out = std::cout) const` | Left → Root → Right (sorted order) |
| `postOrder(std::ostream& out = std::cout) const` | Left → Right → Root |
| `size() const` | Number of nodes |
| `empty() const` | Whether the tree has no nodes |
| `clear()` | Removes all nodes |
| `min() const` | Smallest value; throws `std::runtime_error` if empty |
| `max() const` | Largest value; throws `std::runtime_error` if empty |

## Complexity

| Operation | Average | Worst Case |
|---|---|---|
| Insert | O(log n) | O(log n) |
| Remove | O(log n) | O(log n) |
| Search | O(log n) | O(log n) |
| Min / Max | O(log n) | O(log n) |

Unlike a plain BST, an AVL tree self-balances after every insert and remove, so 
its height is always O(log n) - there is no degenerate worst case, even with sorted input.

## Usage

```cpp
#include "AVL.h"
#include <iostream>

int main()
{
    AVL<int> tree;

    tree.insert(50);
    tree.insert(30);
    tree.insert(70);
    tree.insert(20);

    std::cout << "In-order: ";
    tree.inOrder();
    std::cout << "\n";

    std::cout << "Contains 20: " << tree.contains(20) << "\n";
    std::cout << "Min: " << tree.min() << ", Max: " << tree.max() << "\n";
    std::cout << "Size: " << tree.size() << "\n";

    tree.remove(30);
    std::cout << "After removing 30, in-order: ";
    tree.inOrder();
    std::cout << "\n";
}
```