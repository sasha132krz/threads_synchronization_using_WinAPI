cmake_minimum_required(VERSION 3.9)
project(threads)

set(CMAKE_CXX_STANDARD 11)

add_executable(threads main.cpp threads.cpp threads.h)

target_link_libraries(threads)