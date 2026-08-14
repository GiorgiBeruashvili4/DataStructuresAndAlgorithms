cmake_minimum_required(VERSION 3.20)

project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(DoublyLinkedList INTERFACE)

target_include_directories(
    DoublyLinkedList INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

enable_testing()
add_subdirectory(tests)