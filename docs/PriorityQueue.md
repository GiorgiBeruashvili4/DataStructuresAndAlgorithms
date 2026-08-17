# Priority Queue

A generic priority queue implementation using a binary heap over a `std::vector`.

## Features

- `PriorityQueue<T, Compare = std::less<T>>` template - works with any comparable data type.
- Custom comparator support - defaults to a max-heap (`std::less<T>`); pass `std::greater<T>` for a min-heap, or any custom comparator.
- Dynamic size - grows and shrinks as elements are pushed/popped.
- Rule-of-zero - no manual constructor/destructor/copy logic needed; `std::vector<T>` manages its own resources correctly.
- Strict priority queue interface - only `push`, `pop` and `top`. No arbitrary access, matching the classic priority queue abstraction (similar to `std::priority_queue`).

## Time Complexity

| Operation | Complexity | Notes|
|---|---|---|
| `push` | O(log n) | inserts at the back, then `heapifyUp` restores heap order |
| `pop` | O(log n) | throws `std::out_of_range` if empty; swaps root with last element, removes it, then `heapifyDown` restores heap order |
| `top` | O(1) | `const` only; throws `std::out_of_range` if empty |
| `empty` / `size` | O(1) | |
| copy constructor / copy assignment | O(n) | deep copy via `std::vector`'s own copy semantics |

## API Overview

```cpp
PriorityQueue<int> pq; // max-heap by default

pq.push(2);
pq.push(5);
pq.push(1);

pq.top(); // 5
pq.pop();
pq.top(); // 2

pq.size();
pq.empty();


// min-heap
PriorityQueue<int, std::greater<int>> minPq;

minPq.push(2);
minPq.push(5);
minPq.push(1);

minPq.top() // 1


// Custom type, ordered by a user-defined operator<
struct Task
{
    std::string name;
    int priority;

    bool operator<(const Task& other) const
    {
        return priority < other.priority;
    }
};

PriorityQueue<Task> tasks;
tasks.push({"low", 1});
tasks.push({"high", 10});

tasks.top().name; // "high"
```