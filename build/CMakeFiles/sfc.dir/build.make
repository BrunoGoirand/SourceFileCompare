# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.24.2/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.24.2/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/goirand/Personal/Dev/Tools/SourceFileCompare

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/goirand/Personal/Dev/Tools/SourceFileCompare/build

# Include any dependencies generated for this target.
include CMakeFiles/sfc.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/sfc.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/sfc.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sfc.dir/flags.make

CMakeFiles/sfc.dir/sfc.c.o: CMakeFiles/sfc.dir/flags.make
CMakeFiles/sfc.dir/sfc.c.o: /Users/goirand/Personal/Dev/Tools/SourceFileCompare/sfc.c
CMakeFiles/sfc.dir/sfc.c.o: CMakeFiles/sfc.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/goirand/Personal/Dev/Tools/SourceFileCompare/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/sfc.dir/sfc.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/sfc.dir/sfc.c.o -MF CMakeFiles/sfc.dir/sfc.c.o.d -o CMakeFiles/sfc.dir/sfc.c.o -c /Users/goirand/Personal/Dev/Tools/SourceFileCompare/sfc.c

CMakeFiles/sfc.dir/sfc.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/sfc.dir/sfc.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/goirand/Personal/Dev/Tools/SourceFileCompare/sfc.c > CMakeFiles/sfc.dir/sfc.c.i

CMakeFiles/sfc.dir/sfc.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/sfc.dir/sfc.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/goirand/Personal/Dev/Tools/SourceFileCompare/sfc.c -o CMakeFiles/sfc.dir/sfc.c.s

# Object files for target sfc
sfc_OBJECTS = \
"CMakeFiles/sfc.dir/sfc.c.o"

# External object files for target sfc
sfc_EXTERNAL_OBJECTS =

sfc: CMakeFiles/sfc.dir/sfc.c.o
sfc: CMakeFiles/sfc.dir/build.make
sfc: /usr/local/lib/NeatString/libNeatString.a
sfc: CMakeFiles/sfc.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/goirand/Personal/Dev/Tools/SourceFileCompare/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable sfc"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sfc.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sfc.dir/build: sfc
.PHONY : CMakeFiles/sfc.dir/build

CMakeFiles/sfc.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sfc.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sfc.dir/clean

CMakeFiles/sfc.dir/depend:
	cd /Users/goirand/Personal/Dev/Tools/SourceFileCompare/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/goirand/Personal/Dev/Tools/SourceFileCompare /Users/goirand/Personal/Dev/Tools/SourceFileCompare /Users/goirand/Personal/Dev/Tools/SourceFileCompare/build /Users/goirand/Personal/Dev/Tools/SourceFileCompare/build /Users/goirand/Personal/Dev/Tools/SourceFileCompare/build/CMakeFiles/sfc.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sfc.dir/depend

