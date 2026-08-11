cmake_minimum_required(VERSION 3.20)

project(Stack LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(Stack INTERFACE)
target_include_directories(Stack INTERFACE ${CMAKE_SOURCE_DIR}/include)

enable_testing()
add_subdirectory(tests)