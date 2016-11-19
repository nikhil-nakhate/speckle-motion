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
include CMakeFiles/example_binary_thresholding_cuda.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/example_binary_thresholding_cuda.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/example_binary_thresholding_cuda.dir/flags.make

CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o: CMakeFiles/example_binary_thresholding_cuda.dir/flags.make
CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o: ../image_processing/binary_thresholding.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/nikhil/Downloads/examples/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o -c /home/nikhil/Downloads/examples/image_processing/binary_thresholding.cpp

CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/nikhil/Downloads/examples/image_processing/binary_thresholding.cpp > CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.i

CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/nikhil/Downloads/examples/image_processing/binary_thresholding.cpp -o CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.s

CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o.requires:
.PHONY : CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o.requires

CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o.provides: CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o.requires
	$(MAKE) -f CMakeFiles/example_binary_thresholding_cuda.dir/build.make CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o.provides.build
.PHONY : CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o.provides

CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o.provides.build: CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o

# Object files for target example_binary_thresholding_cuda
example_binary_thresholding_cuda_OBJECTS = \
"CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o"

# External object files for target example_binary_thresholding_cuda
example_binary_thresholding_cuda_EXTERNAL_OBJECTS =

image_processing/binary_thresholding_cuda: CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o
image_processing/binary_thresholding_cuda: CMakeFiles/example_binary_thresholding_cuda.dir/build.make
image_processing/binary_thresholding_cuda: /usr/local/lib/libafcuda.so.3.4.1
image_processing/binary_thresholding_cuda: /usr/local/cuda-8.0/lib64/libcublas.so
image_processing/binary_thresholding_cuda: /usr/local/cuda-8.0/lib64/libcudart.so
image_processing/binary_thresholding_cuda: /usr/local/cuda-8.0/lib64/libcusparse.so
image_processing/binary_thresholding_cuda: /usr/local/cuda-8.0/lib64/libcufft.so
image_processing/binary_thresholding_cuda: /usr/local/cuda-8.0/nvvm/lib64/libnvvm.so
image_processing/binary_thresholding_cuda: /usr/lib/x86_64-linux-gnu/libcuda.so
image_processing/binary_thresholding_cuda: CMakeFiles/example_binary_thresholding_cuda.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable image_processing/binary_thresholding_cuda"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_binary_thresholding_cuda.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/example_binary_thresholding_cuda.dir/build: image_processing/binary_thresholding_cuda
.PHONY : CMakeFiles/example_binary_thresholding_cuda.dir/build

CMakeFiles/example_binary_thresholding_cuda.dir/requires: CMakeFiles/example_binary_thresholding_cuda.dir/image_processing/binary_thresholding.cpp.o.requires
.PHONY : CMakeFiles/example_binary_thresholding_cuda.dir/requires

CMakeFiles/example_binary_thresholding_cuda.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/example_binary_thresholding_cuda.dir/cmake_clean.cmake
.PHONY : CMakeFiles/example_binary_thresholding_cuda.dir/clean

CMakeFiles/example_binary_thresholding_cuda.dir/depend:
	cd /home/nikhil/Downloads/examples/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikhil/Downloads/examples /home/nikhil/Downloads/examples /home/nikhil/Downloads/examples/build /home/nikhil/Downloads/examples/build /home/nikhil/Downloads/examples/build/CMakeFiles/example_binary_thresholding_cuda.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/example_binary_thresholding_cuda.dir/depend

