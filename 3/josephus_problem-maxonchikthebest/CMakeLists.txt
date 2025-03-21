cmake_minimum_required(VERSION 3.10)
project(3dTask)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(src)

add_executable(test_basic
    src/library.cpp
    src/library.hpp
    tests/test_basic.cpp
)
