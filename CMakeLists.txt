cmake_minimum_required(VERSION 3.5)
project(linkedlist)

set(CMAKE_CXX_STANDARD 14)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -g")
set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} -O3")

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

#-------------------
# User program
#-------------------

add_executable(linkedlist main.cpp exception.h Node.hpp ListIterator.hpp List.hpp)

#-------------------
# Test
#-------------------
enable_testing()
include_directories(${COMMON_INCLUDES})

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/src/*.cpp)

add_executable(runAllTests ${TEST_SRC_FILES})
target_link_libraries(runAllTests gtest gtest_main ${CMAKE_THREAD_LIBS_INIT})