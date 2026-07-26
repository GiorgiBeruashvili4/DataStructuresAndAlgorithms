cmake_minimum_required(VERSION 3.20)

project(SinglyLinkedList)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(SinglyLinkedList
    include/list.h
    include/test.h
    src/main.cpp
)