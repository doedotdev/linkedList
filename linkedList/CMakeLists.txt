cmake_minimum_required(VERSION 3.6)
project(linkedList)

set(CMAKE_CXX_STANDARD 11)
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googlemock/include)
include_directories(lib/googletest-release-1.8.0/googletest/include)

set(SOURCE_FILES main.cpp tests/doublyLinkedList.h tests/tests.cpp)
add_executable(linkedList ${SOURCE_FILES} tests/doublyLinkedList.h tests/tests.cpp)
target_link_libraries(linkedList gtest gtest_main)