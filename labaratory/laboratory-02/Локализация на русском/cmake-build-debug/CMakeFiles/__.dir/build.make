# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.20

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Users/aleksejshevcenko/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Users/aleksejshevcenko/Desktop/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/__.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/__.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/__.dir/flags.make

CMakeFiles/__.dir/main.cpp.o: CMakeFiles/__.dir/flags.make
CMakeFiles/__.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/__.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/__.dir/main.cpp.o -c "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/main.cpp"

CMakeFiles/__.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/__.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/main.cpp" > CMakeFiles/__.dir/main.cpp.i

CMakeFiles/__.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/__.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/main.cpp" -o CMakeFiles/__.dir/main.cpp.s

# Object files for target __
___OBJECTS = \
"CMakeFiles/__.dir/main.cpp.o"

# External object files for target __
___EXTERNAL_OBJECTS =

__: CMakeFiles/__.dir/main.cpp.o
__: CMakeFiles/__.dir/build.make
__: CMakeFiles/__.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable __"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/__.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/__.dir/build: __
.PHONY : CMakeFiles/__.dir/build

CMakeFiles/__.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/__.dir/cmake_clean.cmake
.PHONY : CMakeFiles/__.dir/clean

CMakeFiles/__.dir/depend:
	cd "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском" "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском" "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/cmake-build-debug" "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/cmake-build-debug" "/Users/aleksejshevcenko/Desktop/Laboratory_2/Локализация на русском/cmake-build-debug/CMakeFiles/__.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/__.dir/depend

