# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/savouryspringtu/Tu/Projects/Overclock

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/savouryspringtu/Tu/Projects/Overclock/build

# Utility rule file for Overclock_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/Overclock_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Overclock_autogen.dir/progress.make

CMakeFiles/Overclock_autogen: Overclock_autogen/timestamp

Overclock_autogen/timestamp: /usr/lib/qt6/libexec/moc
Overclock_autogen/timestamp: /usr/lib/qt6/libexec/uic
Overclock_autogen/timestamp: CMakeFiles/Overclock_autogen.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/home/savouryspringtu/Tu/Projects/Overclock/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target Overclock"
	/usr/bin/cmake -E cmake_autogen /home/savouryspringtu/Tu/Projects/Overclock/build/CMakeFiles/Overclock_autogen.dir/AutogenInfo.json ""
	/usr/bin/cmake -E touch /home/savouryspringtu/Tu/Projects/Overclock/build/Overclock_autogen/timestamp

Overclock_autogen: CMakeFiles/Overclock_autogen
Overclock_autogen: Overclock_autogen/timestamp
Overclock_autogen: CMakeFiles/Overclock_autogen.dir/build.make
.PHONY : Overclock_autogen

# Rule to build all files generated by this target.
CMakeFiles/Overclock_autogen.dir/build: Overclock_autogen
.PHONY : CMakeFiles/Overclock_autogen.dir/build

CMakeFiles/Overclock_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Overclock_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Overclock_autogen.dir/clean

CMakeFiles/Overclock_autogen.dir/depend:
	cd /home/savouryspringtu/Tu/Projects/Overclock/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/savouryspringtu/Tu/Projects/Overclock /home/savouryspringtu/Tu/Projects/Overclock /home/savouryspringtu/Tu/Projects/Overclock/build /home/savouryspringtu/Tu/Projects/Overclock/build /home/savouryspringtu/Tu/Projects/Overclock/build/CMakeFiles/Overclock_autogen.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Overclock_autogen.dir/depend

