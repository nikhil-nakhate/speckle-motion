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
CMAKE_SOURCE_DIR = /home/nikhil/Code/ComputerVision

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikhil/Code/ComputerVision/build

# Include any dependencies generated for this target.
include CMakeFiles/example_fft_scale_cuda_new_cpu.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example_fft_scale_cuda_new_cpu.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_fft_scale_cuda_new_cpu.dir/flags.make

CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o: CMakeFiles/example_fft_scale_cuda_new_cpu.dir/flags.make
CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o: ../computer_vision/fft_scale_cuda_new.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nikhil/Code/ComputerVision/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o -c /home/nikhil/Code/ComputerVision/computer_vision/fft_scale_cuda_new.cpp

CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nikhil/Code/ComputerVision/computer_vision/fft_scale_cuda_new.cpp > CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.i

CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nikhil/Code/ComputerVision/computer_vision/fft_scale_cuda_new.cpp -o CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.s

CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o.requires:
.PHONY : CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o.requires

CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o.provides: CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o.requires
	$(MAKE) -f CMakeFiles/example_fft_scale_cuda_new_cpu.dir/build.make CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o.provides.build
.PHONY : CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o.provides

CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o.provides.build: CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o

# Object files for target example_fft_scale_cuda_new_cpu
example_fft_scale_cuda_new_cpu_OBJECTS = \
"CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o"

# External object files for target example_fft_scale_cuda_new_cpu
example_fft_scale_cuda_new_cpu_EXTERNAL_OBJECTS =

computer_vision/fft_scale_cuda_new_cpu: CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o
computer_vision/fft_scale_cuda_new_cpu: CMakeFiles/example_fft_scale_cuda_new_cpu.dir/build.make
computer_vision/fft_scale_cuda_new_cpu: /usr/local/lib/libafcpu.so.3.4.1
computer_vision/fft_scale_cuda_new_cpu: CMakeFiles/example_fft_scale_cuda_new_cpu.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable computer_vision/fft_scale_cuda_new_cpu"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_fft_scale_cuda_new_cpu.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example_fft_scale_cuda_new_cpu.dir/build: computer_vision/fft_scale_cuda_new_cpu
.PHONY : CMakeFiles/example_fft_scale_cuda_new_cpu.dir/build

CMakeFiles/example_fft_scale_cuda_new_cpu.dir/requires: CMakeFiles/example_fft_scale_cuda_new_cpu.dir/computer_vision/fft_scale_cuda_new.cpp.o.requires
.PHONY : CMakeFiles/example_fft_scale_cuda_new_cpu.dir/requires

CMakeFiles/example_fft_scale_cuda_new_cpu.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example_fft_scale_cuda_new_cpu.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example_fft_scale_cuda_new_cpu.dir/clean

CMakeFiles/example_fft_scale_cuda_new_cpu.dir/depend:
	cd /home/nikhil/Code/ComputerVision/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikhil/Code/ComputerVision /home/nikhil/Code/ComputerVision /home/nikhil/Code/ComputerVision/build /home/nikhil/Code/ComputerVision/build /home/nikhil/Code/ComputerVision/build/CMakeFiles/example_fft_scale_cuda_new_cpu.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example_fft_scale_cuda_new_cpu.dir/depend

