# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\JetBrains\CLion\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\JetBrains\CLion\CLion 2018.3.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = F:\Project\Algorithm

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = F:\Project\Algorithm\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Algorithm.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Algorithm.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Algorithm.dir/flags.make

CMakeFiles/Algorithm.dir/main.cpp.obj: CMakeFiles/Algorithm.dir/flags.make
CMakeFiles/Algorithm.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Project\Algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Algorithm.dir/main.cpp.obj"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Algorithm.dir\main.cpp.obj -c F:\Project\Algorithm\main.cpp

CMakeFiles/Algorithm.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Algorithm.dir/main.cpp.i"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Project\Algorithm\main.cpp > CMakeFiles\Algorithm.dir\main.cpp.i

CMakeFiles/Algorithm.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Algorithm.dir/main.cpp.s"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Project\Algorithm\main.cpp -o CMakeFiles\Algorithm.dir\main.cpp.s

# Object files for target Algorithm
Algorithm_OBJECTS = \
"CMakeFiles/Algorithm.dir/main.cpp.obj"

# External object files for target Algorithm
Algorithm_EXTERNAL_OBJECTS =

Algorithm.exe: CMakeFiles/Algorithm.dir/main.cpp.obj
Algorithm.exe: CMakeFiles/Algorithm.dir/build.make
Algorithm.exe: CMakeFiles/Algorithm.dir/linklibs.rsp
Algorithm.exe: CMakeFiles/Algorithm.dir/objects1.rsp
Algorithm.exe: CMakeFiles/Algorithm.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Project\Algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Algorithm.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Algorithm.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Algorithm.dir/build: Algorithm.exe

.PHONY : CMakeFiles/Algorithm.dir/build

CMakeFiles/Algorithm.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Algorithm.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Algorithm.dir/clean

CMakeFiles/Algorithm.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Project\Algorithm F:\Project\Algorithm F:\Project\Algorithm\cmake-build-debug F:\Project\Algorithm\cmake-build-debug F:\Project\Algorithm\cmake-build-debug\CMakeFiles\Algorithm.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Algorithm.dir/depend

