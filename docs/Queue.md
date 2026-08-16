# Queue

A generic FIFO queue implementation using a singly linked list.

## Features

- `Queue<T>` template - works with any data type.
- Dynamic size - grows and shrinks as elements are enqueued/dequeued.
- Rule-of-three - copy constructor, copy assignment, destructor.
- Strict FIFO interface - only `enqueue`, `dequeue` and `front`. No arbitrary access, matching the classic queue abstraction (similar to `std::queue`).

## Time Complexity

| Operation | Complexity | Notes|
|---|---|---|
| `enqueue` | O(1) | inserts at `tail` |
| `dequeue` | O(1) | throws `std::out_of_range` if empty; resets `tail` when queue becomes empty |
| `front` | O(1) | `const` and non-`const` overloads; throws `std::out_of_range` if empty |
| `empty` / `size` | O(1) | |
| `clear` / destructor | O(n) | deletes every node |
| copy constructor / copy assignment | O(n) | deep copy, single pass, preserves order |

## API Overview

```cpp
Queue<int> queue;

queue.enqueue(1);
queue.enqueue(2);
queue.enqueue(3);

queue.front(); // 1
queue.dequeue();
queue.front(); // 2

queue.size();
queue.empty();
queue.clear();
```