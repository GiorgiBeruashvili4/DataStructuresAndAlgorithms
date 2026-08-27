# Data Structures And Algorithms

![C++](https://img.shields.io/badge/C%2B%2B-20-blue.svg)
![CMake](https://img.shields.io/badge/CMake-3.20%2B-blue.svg)
![License](https://img.shields.io/badge/license-MIT-green.svg)

A header-only C++20 Library of hand-implemented data structures and 
algorithms, built for learning.

## Requirements

- CMake 3.20+
- C++20-compliant compiler
- Git (for fetching GoogleTest via `FetchContent`)

## Contents

### Data Structures
| Header | Description |
|---|---|
| `Stack.h` | Templated LIFO stack implemented using a singly linked list |
| `Queue.h` | Templated FIFO queue implemented using a singly linked list |
| `PriorityQueue.h` | Templated priority queue implemented using a binary heap over a `std::vector` |
| `SinglyLinkedList.h` | Generic singly linked list - push/pop front & back, insert, remove, reverse |
| `DoublyLinkedList.h` | Generic doubly linked list - O(1) push/pop both ends, insert, remove, reverse |
| `BST.h` | Binary search tree with both iterative and recursive insert/remove/contains |
| `AVL.h` | Self-balancing binary search tree - guaranteed O(log n) height. |

### Sorting Algorithms
| Header | Description |
|---|---|
| `BubbleSort.h` | O(n²) comparison sort, stable |
| `InsertionSort.h` | O(n²) comparison sort, stable |
| `SelectionSort.h` | O(n²) comparison sort, not stable |
| `MergeSort.h` | O(n log n), stable, extra O(n) space |
| `HeapSort.h` | O(n log n), not stable, no extra space |
| `HoarePartition_*.h` / `LomutoPartition_*.h` | Six QuickSort variants comparing Hoare and Lomuto partition schemes with different pivot-selection strategies - see `docs/QuickSort.md` |

## Documentation

Detailed write-ups (API overview, complexity analysis, usage example) for each 
data structure and algorithm are available in the [`docs/`](docs/) directory.

- [AVL](docs/AVL.md), [BST](docs/BST.md)
- [DoublyLinkedList](docs/DoublyLinkedList.md), [SinglyLinkedList](docs/SinglyLinkedList.md)
- [Stack](docs/Stack.md), [Queue](docs/Queue.md), [PriorityQueue](docs/PriorityQueue.md)
- [BubbleSort](docs/BubbleSort.md), [InsertionSort](docs/InsertionSort.md), [SelectionSort](docs/SelectionSort.md), [MergeSort](docs/MergeSort.md), [HeapSort](docs/HeapSort.md), [QuickSort](docs/QuickSort.md)

## Building & Testing

Requires CMake 3.20+ and C++20 compiler.


For Visual Studio / multi-configuration generators:

```sh
cmake -B build
cmake --build build
ctest --test-dir build -C Debug --output-on-failure
```

For single-configuration generators:

```sh
cmake -B build
cmake --build build
ctest --test-dir build --output-on-failure
```

This fetches GoogleTest via `FetchContent` and builds a single 
`DataStructuresAndAlgorithmsTests` binary from everything in `tests/`. 
Test sources are collected with `GLOB CONFIGURE_DEPENDS`, so newly added test files are 
automatically detected when CMake reconfigures the project.

## Using the Library

### With CMake

Add the project as a subdirectory:

```
add_subdirectory(DataStructuresAndAlgorithms)
target_link_libraries(YourTarget PRIVATE dsa)
```

Then include the headers you need:

```
#include <dsa/Stack.h>
#include <dsa/BST.h>
#include <dsa/quick_sort/HoarePartition_FirstPivot.h>
```

### Without CMake

The library is header-only, so you can simply add the `include/` directory to your compiler's include path.

Then:
```
#include <dsa/Stack.h>
#include <dsa/BubbleSort.h>
```

## Project Status

This project is actively being developed as a learning project.

The implementations are written from scratch to practice:
- C++ templates
- Object-oriented programming
- Data structures
- Algorithms
- Generic programming
- CMake
- Unit testing with GoogleTest

## Goals

The main goal of this project is to understand the implementations, complexity 
and trade-offs of common data structures and algorithms rather than provide a 
production-ready alternative to the C++ standard library.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.