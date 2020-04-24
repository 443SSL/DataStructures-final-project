cmake_minimum_required(VERSION 3.15)
project(proj4)

set(CMAKE_CXX_STANDARD 14)

add_executable(proj4 Driver.cpp Heap.h Heap.cpp PinHit.h PinHit.cpp MinHeap.cpp MinHeap.h MaxHeap.cpp MaxHeap.h)