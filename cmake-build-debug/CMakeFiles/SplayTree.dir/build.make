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
include CMakeFiles/SplayTree.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SplayTree.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SplayTree.dir/flags.make

CMakeFiles/SplayTree.dir/src/HomeWork/SplayTreeTest.cpp.obj: CMakeFiles/SplayTree.dir/flags.make
CMakeFiles/SplayTree.dir/src/HomeWork/SplayTreeTest.cpp.obj: ../src/HomeWork/SplayTreeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Project\Algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SplayTree.dir/src/HomeWork/SplayTreeTest.cpp.obj"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SplayTree.dir\src\HomeWork\SplayTreeTest.cpp.obj -c F:\Project\Algorithm\src\HomeWork\SplayTreeTest.cpp

CMakeFiles/SplayTree.dir/src/HomeWork/SplayTreeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SplayTree.dir/src/HomeWork/SplayTreeTest.cpp.i"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Project\Algorithm\src\HomeWork\SplayTreeTest.cpp > CMakeFiles\SplayTree.dir\src\HomeWork\SplayTreeTest.cpp.i

CMakeFiles/SplayTree.dir/src/HomeWork/SplayTreeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SplayTree.dir/src/HomeWork/SplayTreeTest.cpp.s"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Project\Algorithm\src\HomeWork\SplayTreeTest.cpp -o CMakeFiles\SplayTree.dir\src\HomeWork\SplayTreeTest.cpp.s

# Object files for target SplayTree
SplayTree_OBJECTS = \
"CMakeFiles/SplayTree.dir/src/HomeWork/SplayTreeTest.cpp.obj"

# External object files for target SplayTree
SplayTree_EXTERNAL_OBJECTS =

SplayTree.exe: CMakeFiles/SplayTree.dir/src/HomeWork/SplayTreeTest.cpp.obj
SplayTree.exe: CMakeFiles/SplayTree.dir/build.make
SplayTree.exe: CMakeFiles/SplayTree.dir/linklibs.rsp
SplayTree.exe: CMakeFiles/SplayTree.dir/objects1.rsp
SplayTree.exe: CMakeFiles/SplayTree.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Project\Algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SplayTree.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SplayTree.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SplayTree.dir/build: SplayTree.exe

.PHONY : CMakeFiles/SplayTree.dir/build

CMakeFiles/SplayTree.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SplayTree.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SplayTree.dir/clean

CMakeFiles/SplayTree.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Project\Algorithm F:\Project\Algorithm F:\Project\Algorithm\cmake-build-debug F:\Project\Algorithm\cmake-build-debug F:\Project\Algorithm\cmake-build-debug\CMakeFiles\SplayTree.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SplayTree.dir/depend

