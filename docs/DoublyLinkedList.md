# Doubly Linked List

A generic doubly linked list implementation.

## Features

- `DoublyLinkedList<T>` template - works with any data type.
- Dynamic size - grows and shrinks as elements are added/removed.
- Rule-of-five - copy constructor, move constructor, copy assignment, move assignments, destructor
- Forward iterator (`begin()` / `end()`), including `const` iteration and range-based `for` loops.

## Time Complexity

| Operation | Complexity | Notes|
|---|---|---|
| `push_front` | O(1) | |
| `push_back` | O(1) | |
| `pop_front` | O(1) | |
| `pop_back` | O(1) | uses `tail->previous` |
| `front` / `back` | O(1) | |
| `at(index)` | O(n) worst case | walks from nearer end |
| `insert` / `removeAt` | O(n) | walks to the target index |
| `contains` / `indexOf` | O(n) | linear scan |
| `reverse` | O(n) | swaps `next`/`previous` on every node, then swaps `head`/`tail` |
| `clear` / destructor | O(n) | deletes every node |
| copy constructor / copy assignment | O(n) | deep copy |

## Key Difference From The Singly Linked List Version

Every `Node` stores both a `nest` and a `previous` pointer,
that makes `pop_back()` O(1) instead of O(n). Also allows `at(index)` 
to traverse from whichever end is closer to the requested index.

## API Overview

```cpp
DoublyLinkedList<int> list;

list.push_back(1);
list.push_front(0);
list.insert(5, 1);
list.removeAt(0);
list.removeValue(5);
list.front();
list.back();
list.at(0);
list.contains(1);
list.indexOf(1);
list.reverse();
list.size();
list.empty();
list.clear();

for (int value : list)
{
	std::cout << value << " ";
}
```