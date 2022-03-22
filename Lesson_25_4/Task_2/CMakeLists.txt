cmake_minimum_required(VERSION 3.5)

project(Task_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(My_Inc_Dir ${CMAKE_SOURCE_DIR}/inc)

add_subdirectory(src)
