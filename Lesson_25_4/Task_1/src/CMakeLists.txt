cmake_minimum_required(VERSION 3.5)

add_executable(Task_1 main.cpp ${MY_INC_DIR}/operation.h ${MY_INC_DIR}/input_coor.h operation.cpp input_coor.cpp)
target_include_directories(Task_1 PUBLIC ${MY_INC_DIR})
