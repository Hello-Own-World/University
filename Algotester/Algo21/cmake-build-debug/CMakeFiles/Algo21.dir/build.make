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
CMAKE_SOURCE_DIR = C:\Users\yushc\CLionProjects\Algo21

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\yushc\CLionProjects\Algo21\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Algo21.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/Algo21.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Algo21.dir/flags.make

CMakeFiles/Algo21.dir/main.cpp.obj: CMakeFiles/Algo21.dir/flags.make
CMakeFiles/Algo21.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\yushc\CLionProjects\Algo21\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Algo21.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Algo21.dir\main.cpp.obj -c C:\Users\yushc\CLionProjects\Algo21\main.cpp

CMakeFiles/Algo21.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Algo21.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\yushc\CLionProjects\Algo21\main.cpp > CMakeFiles\Algo21.dir\main.cpp.i

CMakeFiles/Algo21.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Algo21.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-W\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\yushc\CLionProjects\Algo21\main.cpp -o CMakeFiles\Algo21.dir\main.cpp.s

# Object files for target Algo21
Algo21_OBJECTS = \
"CMakeFiles/Algo21.dir/main.cpp.obj"

# External object files for target Algo21
Algo21_EXTERNAL_OBJECTS =

Algo21.exe: CMakeFiles/Algo21.dir/main.cpp.obj
Algo21.exe: CMakeFiles/Algo21.dir/build.make
Algo21.exe: CMakeFiles/Algo21.dir/linklibs.rsp
Algo21.exe: CMakeFiles/Algo21.dir/objects1.rsp
Algo21.exe: CMakeFiles/Algo21.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\yushc\CLionProjects\Algo21\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Algo21.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Algo21.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Algo21.dir/build: Algo21.exe
.PHONY : CMakeFiles/Algo21.dir/build

CMakeFiles/Algo21.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Algo21.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Algo21.dir/clean

CMakeFiles/Algo21.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\yushc\CLionProjects\Algo21 C:\Users\yushc\CLionProjects\Algo21 C:\Users\yushc\CLionProjects\Algo21\cmake-build-debug C:\Users\yushc\CLionProjects\Algo21\cmake-build-debug C:\Users\yushc\CLionProjects\Algo21\cmake-build-debug\CMakeFiles\Algo21.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Algo21.dir/depend

