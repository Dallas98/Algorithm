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
include CMakeFiles/BR.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/BR.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BR.dir/flags.make

CMakeFiles/BR.dir/src/HomeWork/RBTreeTest.cpp.obj: CMakeFiles/BR.dir/flags.make
CMakeFiles/BR.dir/src/HomeWork/RBTreeTest.cpp.obj: ../src/HomeWork/RBTreeTest.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Project\Algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BR.dir/src/HomeWork/RBTreeTest.cpp.obj"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BR.dir\src\HomeWork\RBTreeTest.cpp.obj -c F:\Project\Algorithm\src\HomeWork\RBTreeTest.cpp

CMakeFiles/BR.dir/src/HomeWork/RBTreeTest.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BR.dir/src/HomeWork/RBTreeTest.cpp.i"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Project\Algorithm\src\HomeWork\RBTreeTest.cpp > CMakeFiles\BR.dir\src\HomeWork\RBTreeTest.cpp.i

CMakeFiles/BR.dir/src/HomeWork/RBTreeTest.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BR.dir/src/HomeWork/RBTreeTest.cpp.s"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Project\Algorithm\src\HomeWork\RBTreeTest.cpp -o CMakeFiles\BR.dir\src\HomeWork\RBTreeTest.cpp.s

CMakeFiles/BR.dir/src/Lab7/Graph.cpp.obj: CMakeFiles/BR.dir/flags.make
CMakeFiles/BR.dir/src/Lab7/Graph.cpp.obj: ../src/Lab7/Graph.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Project\Algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/BR.dir/src/Lab7/Graph.cpp.obj"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\BR.dir\src\Lab7\Graph.cpp.obj -c F:\Project\Algorithm\src\Lab7\Graph.cpp

CMakeFiles/BR.dir/src/Lab7/Graph.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BR.dir/src/Lab7/Graph.cpp.i"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Project\Algorithm\src\Lab7\Graph.cpp > CMakeFiles\BR.dir\src\Lab7\Graph.cpp.i

CMakeFiles/BR.dir/src/Lab7/Graph.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BR.dir/src/Lab7/Graph.cpp.s"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Project\Algorithm\src\Lab7\Graph.cpp -o CMakeFiles\BR.dir\src\Lab7\Graph.cpp.s

# Object files for target BR
BR_OBJECTS = \
"CMakeFiles/BR.dir/src/HomeWork/RBTreeTest.cpp.obj" \
"CMakeFiles/BR.dir/src/Lab7/Graph.cpp.obj"

# External object files for target BR
BR_EXTERNAL_OBJECTS =

BR.exe: CMakeFiles/BR.dir/src/HomeWork/RBTreeTest.cpp.obj
BR.exe: CMakeFiles/BR.dir/src/Lab7/Graph.cpp.obj
BR.exe: CMakeFiles/BR.dir/build.make
BR.exe: CMakeFiles/BR.dir/linklibs.rsp
BR.exe: CMakeFiles/BR.dir/objects1.rsp
BR.exe: CMakeFiles/BR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Project\Algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable BR.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\BR.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BR.dir/build: BR.exe

.PHONY : CMakeFiles/BR.dir/build

CMakeFiles/BR.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\BR.dir\cmake_clean.cmake
.PHONY : CMakeFiles/BR.dir/clean

CMakeFiles/BR.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Project\Algorithm F:\Project\Algorithm F:\Project\Algorithm\cmake-build-debug F:\Project\Algorithm\cmake-build-debug F:\Project\Algorithm\cmake-build-debug\CMakeFiles\BR.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BR.dir/depend

