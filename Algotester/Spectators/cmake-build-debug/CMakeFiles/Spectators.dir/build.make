# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.2.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\yushc\CLionProjects\University\Algotester\Spectators

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yushc\CLionProjects\University\Algotester\Spectators\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Spectators.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Spectators.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Spectators.dir/flags.make

CMakeFiles/Spectators.dir/main.cpp.obj: CMakeFiles/Spectators.dir/flags.make
CMakeFiles/Spectators.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yushc\CLionProjects\University\Algotester\Spectators\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Spectators.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Spectators.dir\main.cpp.obj -c C:\Users\yushc\CLionProjects\University\Algotester\Spectators\main.cpp

CMakeFiles/Spectators.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Spectators.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\yushc\CLionProjects\University\Algotester\Spectators\main.cpp > CMakeFiles\Spectators.dir\main.cpp.i

CMakeFiles/Spectators.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Spectators.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\yushc\CLionProjects\University\Algotester\Spectators\main.cpp -o CMakeFiles\Spectators.dir\main.cpp.s

# Object files for target Spectators
Spectators_OBJECTS = \
"CMakeFiles/Spectators.dir/main.cpp.obj"

# External object files for target Spectators
Spectators_EXTERNAL_OBJECTS =

Spectators.exe: CMakeFiles/Spectators.dir/main.cpp.obj
Spectators.exe: CMakeFiles/Spectators.dir/build.make
Spectators.exe: CMakeFiles/Spectators.dir/linklibs.rsp
Spectators.exe: CMakeFiles/Spectators.dir/objects1.rsp
Spectators.exe: CMakeFiles/Spectators.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\yushc\CLionProjects\University\Algotester\Spectators\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Spectators.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Spectators.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Spectators.dir/build: Spectators.exe
.PHONY : CMakeFiles/Spectators.dir/build

CMakeFiles/Spectators.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Spectators.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Spectators.dir/clean

CMakeFiles/Spectators.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yushc\CLionProjects\University\Algotester\Spectators C:\Users\yushc\CLionProjects\University\Algotester\Spectators C:\Users\yushc\CLionProjects\University\Algotester\Spectators\cmake-build-debug C:\Users\yushc\CLionProjects\University\Algotester\Spectators\cmake-build-debug C:\Users\yushc\CLionProjects\University\Algotester\Spectators\cmake-build-debug\CMakeFiles\Spectators.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Spectators.dir/depend

