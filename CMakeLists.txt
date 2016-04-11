cmake_minimum_required(VERSION 3.3)
project(Assignment_12_DFS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graph.h Graph.cpp Location.h Location.cpp OutputHeading.cpp Header.h)
add_executable(Assignment_12_DFS ${SOURCE_FILES})