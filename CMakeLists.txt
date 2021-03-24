cmake_minimum_required(VERSION 3.17)
project(Sdizo)

set(CMAKE_CXX_STANDARD 14)

add_executable(Sdizo Code/main.cpp Code/list.cpp Code/list.h Code/table.cpp Code/table.h Code/heap.cpp Code/heap.h)