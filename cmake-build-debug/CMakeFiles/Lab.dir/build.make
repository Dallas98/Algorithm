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
include CMakeFiles/Lab.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Lab.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Lab.dir/flags.make

CMakeFiles/Lab.dir/src/Lab4/LevelBiTree.cpp.obj: CMakeFiles/Lab.dir/flags.make
CMakeFiles/Lab.dir/src/Lab4/LevelBiTree.cpp.obj: ../src/Lab4/LevelBiTree.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=F:\Project\Algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Lab.dir/src/Lab4/LevelBiTree.cpp.obj"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Lab.dir\src\Lab4\LevelBiTree.cpp.obj -c F:\Project\Algorithm\src\Lab4\LevelBiTree.cpp

CMakeFiles/Lab.dir/src/Lab4/LevelBiTree.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Lab.dir/src/Lab4/LevelBiTree.cpp.i"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E F:\Project\Algorithm\src\Lab4\LevelBiTree.cpp > CMakeFiles\Lab.dir\src\Lab4\LevelBiTree.cpp.i

CMakeFiles/Lab.dir/src/Lab4/LevelBiTree.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Lab.dir/src/Lab4/LevelBiTree.cpp.s"
	E:\EnvironmentSettings\MinGW\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S F:\Project\Algorithm\src\Lab4\LevelBiTree.cpp -o CMakeFiles\Lab.dir\src\Lab4\LevelBiTree.cpp.s

# Object files for target Lab
Lab_OBJECTS = \
"CMakeFiles/Lab.dir/src/Lab4/LevelBiTree.cpp.obj"

# External object files for target Lab
Lab_EXTERNAL_OBJECTS =

Lab.exe: CMakeFiles/Lab.dir/src/Lab4/LevelBiTree.cpp.obj
Lab.exe: CMakeFiles/Lab.dir/build.make
Lab.exe: CMakeFiles/Lab.dir/linklibs.rsp
Lab.exe: CMakeFiles/Lab.dir/objects1.rsp
Lab.exe: CMakeFiles/Lab.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=F:\Project\Algorithm\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Lab.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Lab.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Lab.dir/build: Lab.exe

.PHONY : CMakeFiles/Lab.dir/build

CMakeFiles/Lab.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Lab.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Lab.dir/clean

CMakeFiles/Lab.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" F:\Project\Algorithm F:\Project\Algorithm F:\Project\Algorithm\cmake-build-debug F:\Project\Algorithm\cmake-build-debug F:\Project\Algorithm\cmake-build-debug\CMakeFiles\Lab.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Lab.dir/depend

