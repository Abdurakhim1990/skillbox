cmake_minimum_required(VERSION 3.5)

project(Task_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(Task_2 main.cpp)

target_link_libraries(Task_2 PRIVATE nlohmann_json::nlohmann_json)
