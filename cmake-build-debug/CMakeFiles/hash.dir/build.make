# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.2.3\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\C\hash

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\C\hash\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/hash.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/hash.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/hash.dir/flags.make

CMakeFiles/hash.dir/src/hash_table.c.obj: CMakeFiles/hash.dir/flags.make
CMakeFiles/hash.dir/src/hash_table.c.obj: ../src/hash_table.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C\hash\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/hash.dir/src/hash_table.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\hash.dir\src\hash_table.c.obj   -c D:\C\hash\src\hash_table.c

CMakeFiles/hash.dir/src/hash_table.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hash.dir/src/hash_table.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C\hash\src\hash_table.c > CMakeFiles\hash.dir\src\hash_table.c.i

CMakeFiles/hash.dir/src/hash_table.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hash.dir/src/hash_table.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C\hash\src\hash_table.c -o CMakeFiles\hash.dir\src\hash_table.c.s

CMakeFiles/hash.dir/src/main.c.obj: CMakeFiles/hash.dir/flags.make
CMakeFiles/hash.dir/src/main.c.obj: ../src/main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\C\hash\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/hash.dir/src/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\hash.dir\src\main.c.obj   -c D:\C\hash\src\main.c

CMakeFiles/hash.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/hash.dir/src/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\C\hash\src\main.c > CMakeFiles\hash.dir\src\main.c.i

CMakeFiles/hash.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/hash.dir/src/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\C\hash\src\main.c -o CMakeFiles\hash.dir\src\main.c.s

# Object files for target hash
hash_OBJECTS = \
"CMakeFiles/hash.dir/src/hash_table.c.obj" \
"CMakeFiles/hash.dir/src/main.c.obj"

# External object files for target hash
hash_EXTERNAL_OBJECTS =

hash.exe: CMakeFiles/hash.dir/src/hash_table.c.obj
hash.exe: CMakeFiles/hash.dir/src/main.c.obj
hash.exe: CMakeFiles/hash.dir/build.make
hash.exe: CMakeFiles/hash.dir/linklibs.rsp
hash.exe: CMakeFiles/hash.dir/objects1.rsp
hash.exe: CMakeFiles/hash.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\C\hash\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable hash.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\hash.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/hash.dir/build: hash.exe

.PHONY : CMakeFiles/hash.dir/build

CMakeFiles/hash.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\hash.dir\cmake_clean.cmake
.PHONY : CMakeFiles/hash.dir/clean

CMakeFiles/hash.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\C\hash D:\C\hash D:\C\hash\cmake-build-debug D:\C\hash\cmake-build-debug D:\C\hash\cmake-build-debug\CMakeFiles\hash.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/hash.dir/depend
