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
include lib/src/protocol/CMakeFiles/protocol.dir/depend.make

# Include the progress variables for this target.
include lib/src/protocol/CMakeFiles/protocol.dir/progress.make

# Include the compile flags for this target's objects.
include lib/src/protocol/CMakeFiles/protocol.dir/flags.make

lib/src/protocol/CMakeFiles/protocol.dir/jsonProtocol.cpp.o: lib/src/protocol/CMakeFiles/protocol.dir/flags.make
lib/src/protocol/CMakeFiles/protocol.dir/jsonProtocol.cpp.o: ../lib/src/protocol/jsonProtocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/src/protocol/CMakeFiles/protocol.dir/jsonProtocol.cpp.o"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/protocol.dir/jsonProtocol.cpp.o -c /Users/simonqi/Documents/c++/rpc/lib/src/protocol/jsonProtocol.cpp

lib/src/protocol/CMakeFiles/protocol.dir/jsonProtocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/protocol.dir/jsonProtocol.cpp.i"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonqi/Documents/c++/rpc/lib/src/protocol/jsonProtocol.cpp > CMakeFiles/protocol.dir/jsonProtocol.cpp.i

lib/src/protocol/CMakeFiles/protocol.dir/jsonProtocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/protocol.dir/jsonProtocol.cpp.s"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonqi/Documents/c++/rpc/lib/src/protocol/jsonProtocol.cpp -o CMakeFiles/protocol.dir/jsonProtocol.cpp.s

lib/src/protocol/CMakeFiles/protocol.dir/protocol.cpp.o: lib/src/protocol/CMakeFiles/protocol.dir/flags.make
lib/src/protocol/CMakeFiles/protocol.dir/protocol.cpp.o: ../lib/src/protocol/protocol.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/src/protocol/CMakeFiles/protocol.dir/protocol.cpp.o"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/protocol.dir/protocol.cpp.o -c /Users/simonqi/Documents/c++/rpc/lib/src/protocol/protocol.cpp

lib/src/protocol/CMakeFiles/protocol.dir/protocol.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/protocol.dir/protocol.cpp.i"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonqi/Documents/c++/rpc/lib/src/protocol/protocol.cpp > CMakeFiles/protocol.dir/protocol.cpp.i

lib/src/protocol/CMakeFiles/protocol.dir/protocol.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/protocol.dir/protocol.cpp.s"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonqi/Documents/c++/rpc/lib/src/protocol/protocol.cpp -o CMakeFiles/protocol.dir/protocol.cpp.s

# Object files for target protocol
protocol_OBJECTS = \
"CMakeFiles/protocol.dir/jsonProtocol.cpp.o" \
"CMakeFiles/protocol.dir/protocol.cpp.o"

# External object files for target protocol
protocol_EXTERNAL_OBJECTS =

lib/src/protocol/libprotocol.a: lib/src/protocol/CMakeFiles/protocol.dir/jsonProtocol.cpp.o
lib/src/protocol/libprotocol.a: lib/src/protocol/CMakeFiles/protocol.dir/protocol.cpp.o
lib/src/protocol/libprotocol.a: lib/src/protocol/CMakeFiles/protocol.dir/build.make
lib/src/protocol/libprotocol.a: lib/src/protocol/CMakeFiles/protocol.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX static library libprotocol.a"
	cd /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol && $(CMAKE_COMMAND) -P CMakeFiles/protocol.dir/cmake_clean_target.cmake
	cd /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/protocol.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/src/protocol/CMakeFiles/protocol.dir/build: lib/src/protocol/libprotocol.a

.PHONY : lib/src/protocol/CMakeFiles/protocol.dir/build

lib/src/protocol/CMakeFiles/protocol.dir/clean:
	cd /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol && $(CMAKE_COMMAND) -P CMakeFiles/protocol.dir/cmake_clean.cmake
.PHONY : lib/src/protocol/CMakeFiles/protocol.dir/clean

lib/src/protocol/CMakeFiles/protocol.dir/depend:
	cd /Users/simonqi/Documents/c++/rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/simonqi/Documents/c++/rpc /Users/simonqi/Documents/c++/rpc/lib/src/protocol /Users/simonqi/Documents/c++/rpc/build /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol /Users/simonqi/Documents/c++/rpc/build/lib/src/protocol/CMakeFiles/protocol.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/src/protocol/CMakeFiles/protocol.dir/depend

