cmake_minimum_required(VERSION 3.5)
project(traverse_game)

add_subdirectory(${CMAKE_CURRENT_SOURCE_DIR}/traverse/traverse)

include_directories(${CMAKE_SOURCE_DIR}/traverse/traverse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
        traverse/traverse-game/main.cpp)

add_executable(traverse_game ${SOURCE_FILES})
target_link_libraries(traverse_game traverse_lib)