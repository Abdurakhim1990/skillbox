cmake_minimum_required(VERSION 3.5)

project(Test_3 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Boost_INCLUDE_DIR "D:\\boost_1_84_0")
set(Boost_LIBRARY_DIR "D:\\boost_1_84_0\\stage\\lib")
find_package(Boost COMPONENTS REQUIRED)

include_directories(${Boost_INCLUDE_DIR})
link_directories(${Boost_LIBRARY_DIR})

add_executable(Test_3 main.cpp)
target_link_libraries(Test_3 ${Boost_LIBRARIES})

if(MINGW)
    target_link_libraries(Test_3 ws2_32)
endif()
