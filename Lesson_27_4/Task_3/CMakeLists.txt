﻿cmake_minimum_required(VERSION 3.5)

project(Task_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Task_3 main.cpp team.h team.cpp company.h company.cpp)
