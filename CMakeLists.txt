cmake_minimum_required(VERSION 3.20)

project(DataStructuresAndAlgorithms LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_library(dsa INTERFACE)

target_include_directories(dsa
	INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/include
)

include(CTest)
enable_testing()

include(FetchContent)

FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)

file(GLOB TEST_SOURCES CONFIGURE_DEPENDS ${CMAKE_CURRENT_SOURCE_DIR}/tests/*.cpp)

add_executable(DataStructuresAndAlgorithmsTests ${TEST_SOURCES})

target_link_libraries(DataStructuresAndAlgorithmsTests
PRIVATE
    dsa
    GTest::gtest_main
)

include(GoogleTest)

gtest_discover_tests(DataStructuresAndAlgorithmsTests)