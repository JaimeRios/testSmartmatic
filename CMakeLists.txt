cmake_minimum_required(VERSION 2.6)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

PROJECT(test)

add_executable(ProducerConsumer main.cpp SortAlgorithms.cpp)

