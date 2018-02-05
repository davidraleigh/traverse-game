cmake_minimum_required(VERSION 3.5)
project(traverse_lib)

include_directories(${CMAKE_SOURCE_DIR}/traverse/traverse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# TODO this might change depending on system
set(SOURCE_FILES
        ./Traverse.cpp
        ./Traverse.h)

add_library(traverse_lib ${SOURCE_FILES})
