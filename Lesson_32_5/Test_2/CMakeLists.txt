cmake_minimum_required(VERSION 3.5)

project(Test_2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(JSON_BuildTests OFF CACHE INTERNAL "")

add_subdirectory(nlohmann_json)

add_executable(Test_2 main.cpp record.proto record.pb.cc record.pb.h)

target_link_libraries(Test_2 PRIVATE nlohmann_json::nlohmann_json)
