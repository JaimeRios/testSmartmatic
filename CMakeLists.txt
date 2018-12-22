cmake_minimum_required(VERSION 2.6)

PROJECT(test)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -pthread")

#compilation and link -pthreads
find_package(Threads REQUIRED)

add_executable(ProducerConsumer src/main.cpp src/SortAlgorithms.cpp src/Save.cpp)

#compilation and link -pthreads
target_link_libraries(ProducerConsumer ${CMAKE_THREAD_LIBS_INIT})

