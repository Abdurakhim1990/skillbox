cmake_minimum_required(VERSION 3.5)

project(Task_1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MY_INC_DIR ${CMAKE_SOURCE_DIR}/inc)

add_subdirectory(src)
