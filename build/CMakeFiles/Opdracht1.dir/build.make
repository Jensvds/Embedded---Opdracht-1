# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_SOURCE_DIR = /home/pi/les/Opdracht1/Source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/les/Opdracht1/build

# Include any dependencies generated for this target.
include CMakeFiles/Opdracht1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Opdracht1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Opdracht1.dir/flags.make

CMakeFiles/Opdracht1.dir/main.c.o: CMakeFiles/Opdracht1.dir/flags.make
CMakeFiles/Opdracht1.dir/main.c.o: /home/pi/les/Opdracht1/Source/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/les/Opdracht1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Opdracht1.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/Opdracht1.dir/main.c.o -c /home/pi/les/Opdracht1/Source/main.c

CMakeFiles/Opdracht1.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/Opdracht1.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/pi/les/Opdracht1/Source/main.c > CMakeFiles/Opdracht1.dir/main.c.i

CMakeFiles/Opdracht1.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/Opdracht1.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/pi/les/Opdracht1/Source/main.c -o CMakeFiles/Opdracht1.dir/main.c.s

# Object files for target Opdracht1
Opdracht1_OBJECTS = \
"CMakeFiles/Opdracht1.dir/main.c.o"

# External object files for target Opdracht1
Opdracht1_EXTERNAL_OBJECTS =

Opdracht1: CMakeFiles/Opdracht1.dir/main.c.o
Opdracht1: CMakeFiles/Opdracht1.dir/build.make
Opdracht1: CMakeFiles/Opdracht1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/les/Opdracht1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable Opdracht1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Opdracht1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Opdracht1.dir/build: Opdracht1

.PHONY : CMakeFiles/Opdracht1.dir/build

CMakeFiles/Opdracht1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Opdracht1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Opdracht1.dir/clean

CMakeFiles/Opdracht1.dir/depend:
	cd /home/pi/les/Opdracht1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/les/Opdracht1/Source /home/pi/les/Opdracht1/Source /home/pi/les/Opdracht1/build /home/pi/les/Opdracht1/build /home/pi/les/Opdracht1/build/CMakeFiles/Opdracht1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Opdracht1.dir/depend

