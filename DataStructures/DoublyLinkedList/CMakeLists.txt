cmake_minimum_required(VERSION 3.20)

project(DoublyLinkedList)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(DoublyLinkedList
    src/main.cpp
)

target_include_directories(
    DoublyLinkedList PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include
)