# Stack

A generic LIFO stack implementation using a singly linked list.

## Features

- `Stack<T>` template - works with any data type.
- Dynamic size - grows and shrinks as elements are pushed/popped.
- Rule-of-three - copy constructor, copy assignment, destructor.
- Strict LIFO interface - only `push`, `pop` and `peek`. No arbitrary access, matching the classic stack abstraction (similar to `std::stack`).

## Time Complexity

| Operation | Complexity | Notes|
|---|---|---|
| `push` | O(1) | inserts at `top` |
| `pop` | O(1) | throws `std::out_of_range` if empty |
| `peek` | O(1) | `const` and non-`const` overloads; throws `std::out_of_range` if empty |
| `empty` / `size` | O(1) | |
| `clear` / destructor | O(n) | deletes every node |
| copy constructor / copy assignment | O(n) | deep copy, single pass |

## API Overview

```cpp
#include "dsa/Stack.h"
#include <iostream>

int main()
{
	dsa::Stack<int> stack;

	stack.push(1);
	stack.push(2);
	stack.push(3);

	stack.peek(); // 3
	stack.pop();
	stack.peek(); // 2

	stack.size();
	stack.empty();
	stack.clear();
}
```