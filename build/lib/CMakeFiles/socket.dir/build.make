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
include lib/CMakeFiles/socket.dir/depend.make

# Include the progress variables for this target.
include lib/CMakeFiles/socket.dir/progress.make

# Include the compile flags for this target's objects.
include lib/CMakeFiles/socket.dir/flags.make

lib/CMakeFiles/socket.dir/src/transport/csocket.cpp.o: lib/CMakeFiles/socket.dir/flags.make
lib/CMakeFiles/socket.dir/src/transport/csocket.cpp.o: ../lib/src/transport/csocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object lib/CMakeFiles/socket.dir/src/transport/csocket.cpp.o"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/socket.dir/src/transport/csocket.cpp.o -c /Users/simonqi/Documents/c++/rpc/lib/src/transport/csocket.cpp

lib/CMakeFiles/socket.dir/src/transport/csocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket.dir/src/transport/csocket.cpp.i"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonqi/Documents/c++/rpc/lib/src/transport/csocket.cpp > CMakeFiles/socket.dir/src/transport/csocket.cpp.i

lib/CMakeFiles/socket.dir/src/transport/csocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket.dir/src/transport/csocket.cpp.s"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonqi/Documents/c++/rpc/lib/src/transport/csocket.cpp -o CMakeFiles/socket.dir/src/transport/csocket.cpp.s

lib/CMakeFiles/socket.dir/src/transport/socketBase.cpp.o: lib/CMakeFiles/socket.dir/flags.make
lib/CMakeFiles/socket.dir/src/transport/socketBase.cpp.o: ../lib/src/transport/socketBase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object lib/CMakeFiles/socket.dir/src/transport/socketBase.cpp.o"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/socket.dir/src/transport/socketBase.cpp.o -c /Users/simonqi/Documents/c++/rpc/lib/src/transport/socketBase.cpp

lib/CMakeFiles/socket.dir/src/transport/socketBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket.dir/src/transport/socketBase.cpp.i"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonqi/Documents/c++/rpc/lib/src/transport/socketBase.cpp > CMakeFiles/socket.dir/src/transport/socketBase.cpp.i

lib/CMakeFiles/socket.dir/src/transport/socketBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket.dir/src/transport/socketBase.cpp.s"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonqi/Documents/c++/rpc/lib/src/transport/socketBase.cpp -o CMakeFiles/socket.dir/src/transport/socketBase.cpp.s

lib/CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.o: lib/CMakeFiles/socket.dir/flags.make
lib/CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.o: ../lib/src/transport/bufferTransport.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object lib/CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.o"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.o -c /Users/simonqi/Documents/c++/rpc/lib/src/transport/bufferTransport.cpp

lib/CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.i"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonqi/Documents/c++/rpc/lib/src/transport/bufferTransport.cpp > CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.i

lib/CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.s"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonqi/Documents/c++/rpc/lib/src/transport/bufferTransport.cpp -o CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.s

lib/CMakeFiles/socket.dir/src/transport/NioBase.cpp.o: lib/CMakeFiles/socket.dir/flags.make
lib/CMakeFiles/socket.dir/src/transport/NioBase.cpp.o: ../lib/src/transport/NioBase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object lib/CMakeFiles/socket.dir/src/transport/NioBase.cpp.o"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/socket.dir/src/transport/NioBase.cpp.o -c /Users/simonqi/Documents/c++/rpc/lib/src/transport/NioBase.cpp

lib/CMakeFiles/socket.dir/src/transport/NioBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket.dir/src/transport/NioBase.cpp.i"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonqi/Documents/c++/rpc/lib/src/transport/NioBase.cpp > CMakeFiles/socket.dir/src/transport/NioBase.cpp.i

lib/CMakeFiles/socket.dir/src/transport/NioBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket.dir/src/transport/NioBase.cpp.s"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonqi/Documents/c++/rpc/lib/src/transport/NioBase.cpp -o CMakeFiles/socket.dir/src/transport/NioBase.cpp.s

lib/CMakeFiles/socket.dir/src/transport/NioVoid.cpp.o: lib/CMakeFiles/socket.dir/flags.make
lib/CMakeFiles/socket.dir/src/transport/NioVoid.cpp.o: ../lib/src/transport/NioVoid.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object lib/CMakeFiles/socket.dir/src/transport/NioVoid.cpp.o"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/socket.dir/src/transport/NioVoid.cpp.o -c /Users/simonqi/Documents/c++/rpc/lib/src/transport/NioVoid.cpp

lib/CMakeFiles/socket.dir/src/transport/NioVoid.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/socket.dir/src/transport/NioVoid.cpp.i"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/simonqi/Documents/c++/rpc/lib/src/transport/NioVoid.cpp > CMakeFiles/socket.dir/src/transport/NioVoid.cpp.i

lib/CMakeFiles/socket.dir/src/transport/NioVoid.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/socket.dir/src/transport/NioVoid.cpp.s"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/simonqi/Documents/c++/rpc/lib/src/transport/NioVoid.cpp -o CMakeFiles/socket.dir/src/transport/NioVoid.cpp.s

# Object files for target socket
socket_OBJECTS = \
"CMakeFiles/socket.dir/src/transport/csocket.cpp.o" \
"CMakeFiles/socket.dir/src/transport/socketBase.cpp.o" \
"CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.o" \
"CMakeFiles/socket.dir/src/transport/NioBase.cpp.o" \
"CMakeFiles/socket.dir/src/transport/NioVoid.cpp.o"

# External object files for target socket
socket_EXTERNAL_OBJECTS =

lib/libsocket.a: lib/CMakeFiles/socket.dir/src/transport/csocket.cpp.o
lib/libsocket.a: lib/CMakeFiles/socket.dir/src/transport/socketBase.cpp.o
lib/libsocket.a: lib/CMakeFiles/socket.dir/src/transport/bufferTransport.cpp.o
lib/libsocket.a: lib/CMakeFiles/socket.dir/src/transport/NioBase.cpp.o
lib/libsocket.a: lib/CMakeFiles/socket.dir/src/transport/NioVoid.cpp.o
lib/libsocket.a: lib/CMakeFiles/socket.dir/build.make
lib/libsocket.a: lib/CMakeFiles/socket.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/simonqi/Documents/c++/rpc/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX static library libsocket.a"
	cd /Users/simonqi/Documents/c++/rpc/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/socket.dir/cmake_clean_target.cmake
	cd /Users/simonqi/Documents/c++/rpc/build/lib && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/socket.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
lib/CMakeFiles/socket.dir/build: lib/libsocket.a

.PHONY : lib/CMakeFiles/socket.dir/build

lib/CMakeFiles/socket.dir/clean:
	cd /Users/simonqi/Documents/c++/rpc/build/lib && $(CMAKE_COMMAND) -P CMakeFiles/socket.dir/cmake_clean.cmake
.PHONY : lib/CMakeFiles/socket.dir/clean

lib/CMakeFiles/socket.dir/depend:
	cd /Users/simonqi/Documents/c++/rpc/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/simonqi/Documents/c++/rpc /Users/simonqi/Documents/c++/rpc/lib /Users/simonqi/Documents/c++/rpc/build /Users/simonqi/Documents/c++/rpc/build/lib /Users/simonqi/Documents/c++/rpc/build/lib/CMakeFiles/socket.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/CMakeFiles/socket.dir/depend

