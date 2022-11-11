cmake_minimum_required(VERSION 3.20)
project(SortAssignment C)

set(CMAKE_C_STANDARD 90)

add_executable(program main.c sort.c util.c)

target_include_directories(program PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
