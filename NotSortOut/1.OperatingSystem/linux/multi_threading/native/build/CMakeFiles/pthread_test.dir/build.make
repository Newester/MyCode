# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.11

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
CMAKE_SOURCE_DIR = /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/build

# Include any dependencies generated for this target.
include CMakeFiles/pthread_test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/pthread_test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/pthread_test.dir/flags.make

CMakeFiles/pthread_test.dir/pthread_main.cpp.o: CMakeFiles/pthread_test.dir/flags.make
CMakeFiles/pthread_test.dir/pthread_main.cpp.o: ../pthread_main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/pthread_test.dir/pthread_main.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pthread_test.dir/pthread_main.cpp.o -c /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/pthread_main.cpp

CMakeFiles/pthread_test.dir/pthread_main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pthread_test.dir/pthread_main.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/pthread_main.cpp > CMakeFiles/pthread_test.dir/pthread_main.cpp.i

CMakeFiles/pthread_test.dir/pthread_main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pthread_test.dir/pthread_main.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/pthread_main.cpp -o CMakeFiles/pthread_test.dir/pthread_main.cpp.s

CMakeFiles/pthread_test.dir/pthread_module.cpp.o: CMakeFiles/pthread_test.dir/flags.make
CMakeFiles/pthread_test.dir/pthread_module.cpp.o: ../pthread_module.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/pthread_test.dir/pthread_module.cpp.o"
	/usr/bin/g++-7  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/pthread_test.dir/pthread_module.cpp.o -c /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/pthread_module.cpp

CMakeFiles/pthread_test.dir/pthread_module.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pthread_test.dir/pthread_module.cpp.i"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/pthread_module.cpp > CMakeFiles/pthread_test.dir/pthread_module.cpp.i

CMakeFiles/pthread_test.dir/pthread_module.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pthread_test.dir/pthread_module.cpp.s"
	/usr/bin/g++-7 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/pthread_module.cpp -o CMakeFiles/pthread_test.dir/pthread_module.cpp.s

# Object files for target pthread_test
pthread_test_OBJECTS = \
"CMakeFiles/pthread_test.dir/pthread_main.cpp.o" \
"CMakeFiles/pthread_test.dir/pthread_module.cpp.o"

# External object files for target pthread_test
pthread_test_EXTERNAL_OBJECTS =

pthread_test: CMakeFiles/pthread_test.dir/pthread_main.cpp.o
pthread_test: CMakeFiles/pthread_test.dir/pthread_module.cpp.o
pthread_test: CMakeFiles/pthread_test.dir/build.make
pthread_test: CMakeFiles/pthread_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable pthread_test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pthread_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/pthread_test.dir/build: pthread_test

.PHONY : CMakeFiles/pthread_test.dir/build

CMakeFiles/pthread_test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/pthread_test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/pthread_test.dir/clean

CMakeFiles/pthread_test.dir/depend:
	cd /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/build /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/build /home/sepro/mygithub/MyCode/NotSortOut/1.OperatingSystem/linux/multi_threading/native/build/CMakeFiles/pthread_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/pthread_test.dir/depend

