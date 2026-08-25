# Singly Linked List

A generic singly linked list implementation.

## Features

- `SinglyLinkedList<T>` template - works with any data type.
- Dynamic size - grows and shrinks as elements are added/removed.
- Rule-of-five - copy constructor, move constructor, copy assignment, move assignments, destructor
- Forward iterator (`begin()` / `end()`), including `const` iteration and range-based `for` loops.

## Time Complexity

| Operation | Complexity | Notes|
|---|---|---|
| `push_front` | O(1) | |
| `push_back` | O(1) | tracked via `tail` pointer |
| `pop_front` | O(1) | |
| `pop_back` | O(n) | walks from `head` |
| `front` / `back` | O(1) | |
| `at(index)` | O(n)  | walks from `head` |
| `insert` / `removeAt` | O(n) | walks to the target index |
| `contains` / `indexOf` | O(n) | linear scan |
| `reverse` | O(n) | visits every node |
| `clear` / destructor | O(n) | deletes every node |
| copy constructor / copy assignment | O(n) | deep copy |

## API Overview

```cpp
#include "dsa/SinglyLinkedList.h"
#include <iostream>

int main()
{
	dsa::SinglyLinkedList<int> list;

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
}
```
