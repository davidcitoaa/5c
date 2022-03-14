cmake_minimum_required(VERSION 3.20)
project(4c C)

set(CMAKE_C_STANDARD 99)

add_executable(4c main.c)

add_subdirectory(sorting)

target_link_libraries(4c sorting)

