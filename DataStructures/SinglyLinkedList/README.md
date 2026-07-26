# Singly Linked List

A generic singly linked list implementation.

## Features

- `List<T>` template - works with any data type.
- Dynamic size - grows and shrinks as elements are added/removed.
- Rule-of-five - copy constructor, move constructor, copy assignment, move assignments, destructor
- Forward iterator (`begin()` / `end()`), including `const` iteration and range-base `for` loops.

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
List list;

List.push_back(1);
List.push_front(0);
List.insert(5, 1);
List.removeAt(0);
List.removeValue(5);
List.front();
List.back();
List.at(0);
List.contains(1);
List.indexOf(1);
List.reverse();
List.size();
List.empty();
List.clear();

for (int value : list)
{
	std::cout << value << " ";
}
```
