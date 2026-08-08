cmake_minimum_required(VERSION 3.20)

project(BST LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(BST INTERFACE)
target_include_directories(BST INTERFACE ${CMAKE_SOURCE_DIR}/include)

enable_testing()
add_subdirectory(tests)