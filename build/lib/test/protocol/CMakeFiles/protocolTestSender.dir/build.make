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
include lib/test/protocol/CMakeFiles/protocolTestSender.dir/depend.make

# Include the progress variables for this target.
include lib/test/protocol/CMakeFiles/protocolTestSender.dir/progress.make

# Include the compile flags for this target's objects.
include lib/test/protocol/CMakeFiles/protocolTestSender.dir/flags.make

lib/test/protocol/CMakeFiles/protocolTestSender.dir/protocolSender.cpp.o: lib/test/protocol/CMakeFiles/protocolTestSender.dir/flags.make
lib/test/protocol/CMakeFiles/protocolTestSender.dir/protocolSender.cpp.o: ../lib/test/protocol/protocolSender.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/test/protocol/CMakeFiles/protocolTestSender.dir/protocolSender.cpp.o"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/protocol && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/protocolTestSender.dir/protocolSender.cpp.o -c /Users/simonqi/Documents/c++/rpc/lib/test/protocol/protocolSender.cpp

lib/test/protocol/CMakeFiles/protocolTestSender.dir/protocolSender.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/protocolTestSender.dir/protocolSender.cpp.i"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/protocol && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonqi/Documents/c++/rpc/lib/test/protocol/protocolSender.cpp > CMakeFiles/protocolTestSender.dir/protocolSender.cpp.i

lib/test/protocol/CMakeFiles/protocolTestSender.dir/protocolSender.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/protocolTestSender.dir/protocolSender.cpp.s"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/protocol && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonqi/Documents/c++/rpc/lib/test/protocol/protocolSender.cpp -o CMakeFiles/protocolTestSender.dir/protocolSender.cpp.s

# Object files for target protocolTestSender
protocolTestSender_OBJECTS = \
"CMakeFiles/protocolTestSender.dir/protocolSender.cpp.o"

# External object files for target protocolTestSender
protocolTestSender_EXTERNAL_OBJECTS =

lib/test/protocol/protocolTestSender: lib/test/protocol/CMakeFiles/protocolTestSender.dir/protocolSender.cpp.o
lib/test/protocol/protocolTestSender: lib/test/protocol/CMakeFiles/protocolTestSender.dir/build.make
lib/test/protocol/protocolTestSender: lib/src/protocol/libprotocol.a
lib/test/protocol/protocolTestSender: lib/src/transport/libtransport.a
lib/test/protocol/protocolTestSender: /usr/local/lib/liblogging.a
lib/test/protocol/protocolTestSender: /usr/local/lib/libfmt.a
lib/test/protocol/protocolTestSender: lib/test/protocol/CMakeFiles/protocolTestSender.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable protocolTestSender"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/protocol && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/protocolTestSender.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/test/protocol/CMakeFiles/protocolTestSender.dir/build: lib/test/protocol/protocolTestSender

.PHONY : lib/test/protocol/CMakeFiles/protocolTestSender.dir/build

lib/test/protocol/CMakeFiles/protocolTestSender.dir/clean:
	cd /Users/simonqi/Documents/c++/rpc/build/lib/test/protocol && $(CMAKE_COMMAND) -P CMakeFiles/protocolTestSender.dir/cmake_clean.cmake
.PHONY : lib/test/protocol/CMakeFiles/protocolTestSender.dir/clean

lib/test/protocol/CMakeFiles/protocolTestSender.dir/depend:
	cd /Users/simonqi/Documents/c++/rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/simonqi/Documents/c++/rpc /Users/simonqi/Documents/c++/rpc/lib/test/protocol /Users/simonqi/Documents/c++/rpc/build /Users/simonqi/Documents/c++/rpc/build/lib/test/protocol /Users/simonqi/Documents/c++/rpc/build/lib/test/protocol/CMakeFiles/protocolTestSender.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/test/protocol/CMakeFiles/protocolTestSender.dir/depend
