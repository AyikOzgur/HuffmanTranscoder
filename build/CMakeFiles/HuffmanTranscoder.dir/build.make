# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Projects/HuffmanTranscoder/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Projects/HuffmanTranscoder/build

# Include any dependencies generated for this target.
include CMakeFiles/HuffmanTranscoder.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/HuffmanTranscoder.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/HuffmanTranscoder.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HuffmanTranscoder.dir/flags.make

CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.o: CMakeFiles/HuffmanTranscoder.dir/flags.make
CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.o: /home/pi/Projects/HuffmanTranscoder/src/Huffman/Huffman.c
CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.o: CMakeFiles/HuffmanTranscoder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Projects/HuffmanTranscoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.o -MF CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.o.d -o CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.o -c /home/pi/Projects/HuffmanTranscoder/src/Huffman/Huffman.c

CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Projects/HuffmanTranscoder/src/Huffman/Huffman.c > CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.i

CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Projects/HuffmanTranscoder/src/Huffman/Huffman.c -o CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.s

CMakeFiles/HuffmanTranscoder.dir/main.c.o: CMakeFiles/HuffmanTranscoder.dir/flags.make
CMakeFiles/HuffmanTranscoder.dir/main.c.o: /home/pi/Projects/HuffmanTranscoder/src/main.c
CMakeFiles/HuffmanTranscoder.dir/main.c.o: CMakeFiles/HuffmanTranscoder.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Projects/HuffmanTranscoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/HuffmanTranscoder.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/HuffmanTranscoder.dir/main.c.o -MF CMakeFiles/HuffmanTranscoder.dir/main.c.o.d -o CMakeFiles/HuffmanTranscoder.dir/main.c.o -c /home/pi/Projects/HuffmanTranscoder/src/main.c

CMakeFiles/HuffmanTranscoder.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/HuffmanTranscoder.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/Projects/HuffmanTranscoder/src/main.c > CMakeFiles/HuffmanTranscoder.dir/main.c.i

CMakeFiles/HuffmanTranscoder.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/HuffmanTranscoder.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/Projects/HuffmanTranscoder/src/main.c -o CMakeFiles/HuffmanTranscoder.dir/main.c.s

# Object files for target HuffmanTranscoder
HuffmanTranscoder_OBJECTS = \
"CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.o" \
"CMakeFiles/HuffmanTranscoder.dir/main.c.o"

# External object files for target HuffmanTranscoder
HuffmanTranscoder_EXTERNAL_OBJECTS =

HuffmanTranscoder: CMakeFiles/HuffmanTranscoder.dir/Huffman/Huffman.c.o
HuffmanTranscoder: CMakeFiles/HuffmanTranscoder.dir/main.c.o
HuffmanTranscoder: CMakeFiles/HuffmanTranscoder.dir/build.make
HuffmanTranscoder: CMakeFiles/HuffmanTranscoder.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Projects/HuffmanTranscoder/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable HuffmanTranscoder"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HuffmanTranscoder.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HuffmanTranscoder.dir/build: HuffmanTranscoder
.PHONY : CMakeFiles/HuffmanTranscoder.dir/build

CMakeFiles/HuffmanTranscoder.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HuffmanTranscoder.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HuffmanTranscoder.dir/clean

CMakeFiles/HuffmanTranscoder.dir/depend:
	cd /home/pi/Projects/HuffmanTranscoder/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Projects/HuffmanTranscoder/src /home/pi/Projects/HuffmanTranscoder/src /home/pi/Projects/HuffmanTranscoder/build /home/pi/Projects/HuffmanTranscoder/build /home/pi/Projects/HuffmanTranscoder/build/CMakeFiles/HuffmanTranscoder.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HuffmanTranscoder.dir/depend
