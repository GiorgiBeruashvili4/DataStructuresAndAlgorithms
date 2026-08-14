cmake_minimum_required(VERSION 3.20)

project(SinglyLinkedList)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(SinglyLinkedList INTERFACE)

target_include_directories(
    SinglyLinkedList INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

enable_testing()
add_subdirectory(tests)