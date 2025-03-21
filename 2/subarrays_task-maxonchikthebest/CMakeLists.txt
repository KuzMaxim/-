cmake_minimum_required(VERSION 3.10)
project(2ndTask)

# Указываем стандарт C++
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Добавляем папку с классами
include_directories(stc)

# Добавляем исполняемый файл, включающий оба cpp файла
add_executable(test_basic
    src/library.cpp
    src/library.hpp
    tests/test_basic.cpp
)
