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
CMAKE_SOURCE_DIR = C:\Users\yushc\CLionProjects\Komivojager

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yushc\CLionProjects\Komivojager\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Komivojager.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Komivojager.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Komivojager.dir/flags.make

CMakeFiles/Komivojager.dir/main.cpp.obj: CMakeFiles/Komivojager.dir/flags.make
CMakeFiles/Komivojager.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yushc\CLionProjects\Komivojager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Komivojager.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Komivojager.dir\main.cpp.obj -c C:\Users\yushc\CLionProjects\Komivojager\main.cpp

CMakeFiles/Komivojager.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Komivojager.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\yushc\CLionProjects\Komivojager\main.cpp > CMakeFiles\Komivojager.dir\main.cpp.i

CMakeFiles/Komivojager.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Komivojager.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\yushc\CLionProjects\Komivojager\main.cpp -o CMakeFiles\Komivojager.dir\main.cpp.s

# Object files for target Komivojager
Komivojager_OBJECTS = \
"CMakeFiles/Komivojager.dir/main.cpp.obj"

# External object files for target Komivojager
Komivojager_EXTERNAL_OBJECTS =

Komivojager.exe: CMakeFiles/Komivojager.dir/main.cpp.obj
Komivojager.exe: CMakeFiles/Komivojager.dir/build.make
Komivojager.exe: CMakeFiles/Komivojager.dir/linklibs.rsp
Komivojager.exe: CMakeFiles/Komivojager.dir/objects1.rsp
Komivojager.exe: CMakeFiles/Komivojager.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\yushc\CLionProjects\Komivojager\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Komivojager.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Komivojager.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Komivojager.dir/build: Komivojager.exe
.PHONY : CMakeFiles/Komivojager.dir/build

CMakeFiles/Komivojager.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Komivojager.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Komivojager.dir/clean

CMakeFiles/Komivojager.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yushc\CLionProjects\Komivojager C:\Users\yushc\CLionProjects\Komivojager C:\Users\yushc\CLionProjects\Komivojager\cmake-build-debug C:\Users\yushc\CLionProjects\Komivojager\cmake-build-debug C:\Users\yushc\CLionProjects\Komivojager\cmake-build-debug\CMakeFiles\Komivojager.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Komivojager.dir/depend

