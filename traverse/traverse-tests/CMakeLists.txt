cmake_minimum_required(VERSION 3.5)
project(traverse_test)

include_directories(${CMAKE_SOURCE_DIR}/cxxtest
        ${CMAKE_SOURCE_DIR}/traverse/traverse)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# TODO this might change depending on system
set(CXX_PYTHON_COMMAND "python")
# windows version
#C:\Python27\python.exe $(SolutionDir)cxxtest\cxxtest_cpp_update.py -c $(SolutionDir)cxxtest\python -t $(ProjectDir)
message(COMMAND
        ${CXX_PYTHON_COMMAND}
        ${CMAKE_SOURCE_DIR}/cxxtest/cxxtest_cpp_update.py
        -c ${CMAKE_SOURCE_DIR}/cxxtest/python
        -t ${CMAKE_SOURCE_DIR}/traverse/traverse-tests)

execute_process(COMMAND
        ${CXX_PYTHON_COMMAND}
        ${CMAKE_SOURCE_DIR}/cxxtest/cxxtest_cpp_update.py
        -c ${CMAKE_SOURCE_DIR}/cxxtest/python
        -t ${CMAKE_SOURCE_DIR}/traverse/traverse-tests)

set(SOURCE_FILES runner.cpp)

add_executable(traverse_test ${SOURCE_FILES})
target_link_libraries(traverse_test traverse_lib)

#add_test (NAME Traverse_Unit_Tests COMMAND traverse_test)