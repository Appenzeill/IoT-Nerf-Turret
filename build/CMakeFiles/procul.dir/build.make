# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/build

# Include any dependencies generated for this target.
include CMakeFiles/procul.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/procul.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/procul.dir/flags.make

CMakeFiles/procul.dir/src/PracticalSocket.cpp.o: CMakeFiles/procul.dir/flags.make
CMakeFiles/procul.dir/src/PracticalSocket.cpp.o: ../src/PracticalSocket.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/procul.dir/src/PracticalSocket.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/procul.dir/src/PracticalSocket.cpp.o -c /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/src/PracticalSocket.cpp

CMakeFiles/procul.dir/src/PracticalSocket.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/procul.dir/src/PracticalSocket.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/src/PracticalSocket.cpp > CMakeFiles/procul.dir/src/PracticalSocket.cpp.i

CMakeFiles/procul.dir/src/PracticalSocket.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/procul.dir/src/PracticalSocket.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/src/PracticalSocket.cpp -o CMakeFiles/procul.dir/src/PracticalSocket.cpp.s

CMakeFiles/procul.dir/src/main.cpp.o: CMakeFiles/procul.dir/flags.make
CMakeFiles/procul.dir/src/main.cpp.o: ../src/main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/procul.dir/src/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/procul.dir/src/main.cpp.o -c /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/src/main.cpp

CMakeFiles/procul.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/procul.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/src/main.cpp > CMakeFiles/procul.dir/src/main.cpp.i

CMakeFiles/procul.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/procul.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/src/main.cpp -o CMakeFiles/procul.dir/src/main.cpp.s

# Object files for target procul
procul_OBJECTS = \
"CMakeFiles/procul.dir/src/PracticalSocket.cpp.o" \
"CMakeFiles/procul.dir/src/main.cpp.o"

# External object files for target procul
procul_EXTERNAL_OBJECTS =

procul: CMakeFiles/procul.dir/src/PracticalSocket.cpp.o
procul: CMakeFiles/procul.dir/src/main.cpp.o
procul: CMakeFiles/procul.dir/build.make
procul: /usr/lib/libwiringPi.so
procul: CMakeFiles/procul.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable procul"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/procul.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/procul.dir/build: procul

.PHONY : CMakeFiles/procul.dir/build

CMakeFiles/procul.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/procul.dir/cmake_clean.cmake
.PHONY : CMakeFiles/procul.dir/clean

CMakeFiles/procul.dir/depend:
	cd /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/build /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/build /home/pi/Development/C++/PeriodeC/IoT-Nerf-Turret/build/CMakeFiles/procul.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/procul.dir/depend

