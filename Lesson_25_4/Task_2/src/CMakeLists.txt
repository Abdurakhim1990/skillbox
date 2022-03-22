cmake_minimum_required(VERSION 3.5)

add_executable(Task_2 main.cpp cpu.cpp disk.cpp gpu.cpp kbd.cpp ram.cpp ${My_Inc_Dir}/main.h
    ${My_Inc_Dir}/cpu.h ${My_Inc_Dir}/disk.h ${My_Inc_Dir}/gpu.h ${My_Inc_Dir}/kbd.h ${My_Inc_Dir}/ram.h)
target_include_directories(Task_2 PUBLIC ${My_Inc_Dir})
