# Data Structures And Algorithms

A header-only C++20 Library of hand-implemented data structures and 
algorithms, built for learning.

## Layout

```text
DataStructuresAndAlgorithms/
├── .gitignore
├── README.md
├── CMakeLists.txt
├── docs/
│   ├── BST.md
│   ├── BubbleSort.md
│   ├── InsertionSort.md
│   ├── MergeSort.md
│   ├── HeapSort.md
│   ├── QuickSort.md
│   ├── SelectionSort.md
│   ├── doublyLinkedList.md
│   └── singlyLinkedList.md
│
├── include/
│   └── dsa/
│       ├── BST.h
│       ├── BubbleSort.h
│       ├── InsertionSort.h
│       ├── MergeSort.h
│       ├── HeapSort.h
│       ├── SelectionSort.h
│       ├── doublyLinkedList.h
│       ├── singlyLinkedList.h
│       ├── stack.h
│       ├── Queue.h
│       │
│       └── quick_sort/
│           ├── HoarePartition_FirstPivot.h
│           ├── HoarePartition_MedianOfThree.h
│           ├── HoarePartition_RandomPivot.h
│           ├── LomutoPartition_LastPivot.h
│           ├── LomutoPartition_MedianOfThree.h
│           └── LomutoPartition_RandomPivot.h
│
└── tests/
    ├── BSTTests.cpp
    ├── doublyLinkedListTests.cpp
    ├── singlyLinkedListTests.cpp
    └── stackTests.cpp
```

## Contents

### Data Structures
| Header | Description |
|---|---|
| `stack.h` | Templated LIFO stack implemented using a singly linked list |
| `Queue.h` | Templated FIFO queue implemented using a singly linked list |
| `singlyLinkedList.h` | Generic singly linked list - push/pop front & back, insert, remove, reverse |
| `doublyLinkedList.h` | Generic doubly linked list - O(1) push/pop both ends, insert, remove, reverse |
| `BST.h` | Binary search tree with both iterative and recursive insert/remove/contains |

### Sorting Algorithms
| Header | Description |
|---|---|
| `BubbleSort.h` | O(n²) comparison sort, stable |
| `InsertionSort.h` | O(n²) comparison sort, stable |
| `SelectionSort.h` | O(n²) comparison sort, not stable |
| `MergeSort.h` | O(n log n), stable, extra O(n) space |
| `HeapSort.h` | O(n log n), not stable, no extra space |
| `HoarePartition_*.h` / `LomutoPartition_*.h` | Six QuickSort variants comparing Hoare and Lomuto partition schemes with different pivot-selection strategies - see `docs/QuickSort.md` |

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
#include <dsa/stack.h>
#include <dsa/BST.h>
#include <dsa/quick_sort/HoarePartition_FirstPivot.h>
```

### Without CMake

The library is header-only, so you can simply add the `include/` directory to your compiler's include path.

Then:
```
#include <dsa/stack.h>
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