# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\QtCreator\skillbox\Lesson_29_4\Test1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\QtCreator\skillbox\Lesson_29_4\build-Test1-Desktop_Qt_5_12_12_MinGW_32_bit-Debug

# Include any dependencies generated for this target.
include CMakeFiles/Test1.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Test1.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Test1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test1.dir/flags.make

CMakeFiles/Test1.dir/main.cpp.obj: CMakeFiles/Test1.dir/flags.make
CMakeFiles/Test1.dir/main.cpp.obj: D:/QtCreator/skillbox/Lesson_29_4/Test1/main.cpp
CMakeFiles/Test1.dir/main.cpp.obj: CMakeFiles/Test1.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\QtCreator\skillbox\Lesson_29_4\build-Test1-Desktop_Qt_5_12_12_MinGW_32_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test1.dir/main.cpp.obj"
	C:\Qt\Qt5.12.12\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Test1.dir/main.cpp.obj -MF CMakeFiles\Test1.dir\main.cpp.obj.d -o CMakeFiles\Test1.dir\main.cpp.obj -c D:\QtCreator\skillbox\Lesson_29_4\Test1\main.cpp

CMakeFiles/Test1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test1.dir/main.cpp.i"
	C:\Qt\Qt5.12.12\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\QtCreator\skillbox\Lesson_29_4\Test1\main.cpp > CMakeFiles\Test1.dir\main.cpp.i

CMakeFiles/Test1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test1.dir/main.cpp.s"
	C:\Qt\Qt5.12.12\Tools\mingw730_32\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\QtCreator\skillbox\Lesson_29_4\Test1\main.cpp -o CMakeFiles\Test1.dir\main.cpp.s

# Object files for target Test1
Test1_OBJECTS = \
"CMakeFiles/Test1.dir/main.cpp.obj"

# External object files for target Test1
Test1_EXTERNAL_OBJECTS =

Test1.exe: CMakeFiles/Test1.dir/main.cpp.obj
Test1.exe: CMakeFiles/Test1.dir/build.make
Test1.exe: CMakeFiles/Test1.dir/linklibs.rsp
Test1.exe: CMakeFiles/Test1.dir/objects1.rsp
Test1.exe: CMakeFiles/Test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\QtCreator\skillbox\Lesson_29_4\build-Test1-Desktop_Qt_5_12_12_MinGW_32_bit-Debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Test1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test1.dir/build: Test1.exe
.PHONY : CMakeFiles/Test1.dir/build

CMakeFiles/Test1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Test1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Test1.dir/clean

CMakeFiles/Test1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\QtCreator\skillbox\Lesson_29_4\Test1 D:\QtCreator\skillbox\Lesson_29_4\Test1 D:\QtCreator\skillbox\Lesson_29_4\build-Test1-Desktop_Qt_5_12_12_MinGW_32_bit-Debug D:\QtCreator\skillbox\Lesson_29_4\build-Test1-Desktop_Qt_5_12_12_MinGW_32_bit-Debug D:\QtCreator\skillbox\Lesson_29_4\build-Test1-Desktop_Qt_5_12_12_MinGW_32_bit-Debug\CMakeFiles\Test1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test1.dir/depend

