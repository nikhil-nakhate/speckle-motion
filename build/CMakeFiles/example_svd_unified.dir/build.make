# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /usr/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nikhil/Downloads/examples

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikhil/Downloads/examples/build

# Include any dependencies generated for this target.
include CMakeFiles/example_svd_unified.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example_svd_unified.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_svd_unified.dir/flags.make

CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o: CMakeFiles/example_svd_unified.dir/flags.make
CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o: ../lin_algebra/svd.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nikhil/Downloads/examples/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o -c /home/nikhil/Downloads/examples/lin_algebra/svd.cpp

CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nikhil/Downloads/examples/lin_algebra/svd.cpp > CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.i

CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nikhil/Downloads/examples/lin_algebra/svd.cpp -o CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.s

CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o.requires:
.PHONY : CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o.requires

CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o.provides: CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o.requires
	$(MAKE) -f CMakeFiles/example_svd_unified.dir/build.make CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o.provides.build
.PHONY : CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o.provides

CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o.provides.build: CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o

# Object files for target example_svd_unified
example_svd_unified_OBJECTS = \
"CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o"

# External object files for target example_svd_unified
example_svd_unified_EXTERNAL_OBJECTS =

lin_algebra/svd_unified: CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o
lin_algebra/svd_unified: CMakeFiles/example_svd_unified.dir/build.make
lin_algebra/svd_unified: /usr/local/lib/libaf.so.3.4.1
lin_algebra/svd_unified: CMakeFiles/example_svd_unified.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable lin_algebra/svd_unified"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_svd_unified.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example_svd_unified.dir/build: lin_algebra/svd_unified
.PHONY : CMakeFiles/example_svd_unified.dir/build

CMakeFiles/example_svd_unified.dir/requires: CMakeFiles/example_svd_unified.dir/lin_algebra/svd.cpp.o.requires
.PHONY : CMakeFiles/example_svd_unified.dir/requires

CMakeFiles/example_svd_unified.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example_svd_unified.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example_svd_unified.dir/clean

CMakeFiles/example_svd_unified.dir/depend:
	cd /home/nikhil/Downloads/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikhil/Downloads/examples /home/nikhil/Downloads/examples /home/nikhil/Downloads/examples/build /home/nikhil/Downloads/examples/build /home/nikhil/Downloads/examples/build/CMakeFiles/example_svd_unified.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example_svd_unified.dir/depend

