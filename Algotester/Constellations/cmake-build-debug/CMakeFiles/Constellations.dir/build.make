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
CMAKE_SOURCE_DIR = C:\Users\yushc\CLionProjects\Constellations

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yushc\CLionProjects\Constellations\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Constellations.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Constellations.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Constellations.dir/flags.make

CMakeFiles/Constellations.dir/main.cpp.obj: CMakeFiles/Constellations.dir/flags.make
CMakeFiles/Constellations.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yushc\CLionProjects\Constellations\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Constellations.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Constellations.dir\main.cpp.obj -c C:\Users\yushc\CLionProjects\Constellations\main.cpp

CMakeFiles/Constellations.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Constellations.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\yushc\CLionProjects\Constellations\main.cpp > CMakeFiles\Constellations.dir\main.cpp.i

CMakeFiles/Constellations.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Constellations.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\yushc\CLionProjects\Constellations\main.cpp -o CMakeFiles\Constellations.dir\main.cpp.s

# Object files for target Constellations
Constellations_OBJECTS = \
"CMakeFiles/Constellations.dir/main.cpp.obj"

# External object files for target Constellations
Constellations_EXTERNAL_OBJECTS =

Constellations.exe: CMakeFiles/Constellations.dir/main.cpp.obj
Constellations.exe: CMakeFiles/Constellations.dir/build.make
Constellations.exe: CMakeFiles/Constellations.dir/linklibs.rsp
Constellations.exe: CMakeFiles/Constellations.dir/objects1.rsp
Constellations.exe: CMakeFiles/Constellations.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\yushc\CLionProjects\Constellations\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Constellations.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Constellations.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Constellations.dir/build: Constellations.exe
.PHONY : CMakeFiles/Constellations.dir/build

CMakeFiles/Constellations.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Constellations.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Constellations.dir/clean

CMakeFiles/Constellations.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yushc\CLionProjects\Constellations C:\Users\yushc\CLionProjects\Constellations C:\Users\yushc\CLionProjects\Constellations\cmake-build-debug C:\Users\yushc\CLionProjects\Constellations\cmake-build-debug C:\Users\yushc\CLionProjects\Constellations\cmake-build-debug\CMakeFiles\Constellations.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Constellations.dir/depend

