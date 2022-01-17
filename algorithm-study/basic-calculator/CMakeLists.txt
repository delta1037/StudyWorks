cmake_minimum_required(VERSION 3.7)
project(basic_calculator)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c)
add_executable(basic_calculator ${SOURCE_FILES})