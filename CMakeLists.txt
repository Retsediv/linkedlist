cmake_minimum_required(VERSION 3.5)
project(linkedlist)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(linkedlist main.cpp Node.hpp List.hpp)

add_executable(testNode Node.hpp testNode.cpp)
target_link_libraries(testNode ${GTEST_LIBRARIES} pthread)