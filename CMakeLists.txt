cmake_minimum_required(VERSION 3.3)
project(Assignment_12___DFS)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Graph.h Location.h OutputHeading.cpp Header.h Locations.cpp Graph.cpp)
add_executable(Assignment_12___DFS ${SOURCE_FILES})