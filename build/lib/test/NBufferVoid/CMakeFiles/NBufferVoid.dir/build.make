# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.15.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.15.2/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/simonqi/Documents/c++/rpc

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/simonqi/Documents/c++/rpc/build

# Include any dependencies generated for this target.
include lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/depend.make

# Include the progress variables for this target.
include lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/progress.make

# Include the compile flags for this target's objects.
include lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/flags.make

lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.o: lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/flags.make
lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.o: ../lib/test/NBufferVoid/NBufferVoid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.o"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/NBufferVoid && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.o -c /Users/simonqi/Documents/c++/rpc/lib/test/NBufferVoid/NBufferVoid.cpp

lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.i"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/NBufferVoid && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonqi/Documents/c++/rpc/lib/test/NBufferVoid/NBufferVoid.cpp > CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.i

lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.s"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/NBufferVoid && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonqi/Documents/c++/rpc/lib/test/NBufferVoid/NBufferVoid.cpp -o CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.s

# Object files for target NBufferVoid
NBufferVoid_OBJECTS = \
"CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.o"

# External object files for target NBufferVoid
NBufferVoid_EXTERNAL_OBJECTS =

lib/test/NBufferVoid/NBufferVoid: lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/NBufferVoid.cpp.o
lib/test/NBufferVoid/NBufferVoid: lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/build.make
lib/test/NBufferVoid/NBufferVoid: lib/src/transport/libtransport.a
lib/test/NBufferVoid/NBufferVoid: /usr/local/lib/liblogging.a
lib/test/NBufferVoid/NBufferVoid: /usr/local/lib/libfmt.a
lib/test/NBufferVoid/NBufferVoid: lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NBufferVoid"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/NBufferVoid && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NBufferVoid.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/build: lib/test/NBufferVoid/NBufferVoid

.PHONY : lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/build

lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/clean:
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/NBufferVoid && $(CMAKE_COMMAND) -P CMakeFiles/NBufferVoid.dir/cmake_clean.cmake
.PHONY : lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/clean

lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/depend:
	cd /Users/simonqi/Documents/c++/rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/simonqi/Documents/c++/rpc /Users/simonqi/Documents/c++/rpc/lib/test/NBufferVoid /Users/simonqi/Documents/c++/rpc/build /Users/simonqi/Documents/c++/rpc/build/lib/test/NBufferVoid /Users/simonqi/Documents/c++/rpc/build/lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/test/NBufferVoid/CMakeFiles/NBufferVoid.dir/depend
