cmake_minimum_required(VERSION 3.14)
project(Socket_C__)

set(CMAKE_CXX_STANDARD 14)

add_executable(Socket_C__ main.cpp include/log.h include/socket.h src/socket.cpp include/data.h)