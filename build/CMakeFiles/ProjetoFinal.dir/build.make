# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\Vinicius\Desktop\BANCO-LAED-II

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\Vinicius\Desktop\BANCO-LAED-II\build

# Include any dependencies generated for this target.
include CMakeFiles/ProjetoFinal.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/ProjetoFinal.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/ProjetoFinal.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ProjetoFinal.dir/flags.make

CMakeFiles/ProjetoFinal.dir/src/main.c.obj: CMakeFiles/ProjetoFinal.dir/flags.make
CMakeFiles/ProjetoFinal.dir/src/main.c.obj: C:/Users/Vinicius/Desktop/BANCO-LAED-II/src/main.c
CMakeFiles/ProjetoFinal.dir/src/main.c.obj: CMakeFiles/ProjetoFinal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Vinicius\Desktop\BANCO-LAED-II\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ProjetoFinal.dir/src/main.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ProjetoFinal.dir/src/main.c.obj -MF CMakeFiles\ProjetoFinal.dir\src\main.c.obj.d -o CMakeFiles\ProjetoFinal.dir\src\main.c.obj -c C:\Users\Vinicius\Desktop\BANCO-LAED-II\src\main.c

CMakeFiles/ProjetoFinal.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ProjetoFinal.dir/src/main.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Vinicius\Desktop\BANCO-LAED-II\src\main.c > CMakeFiles\ProjetoFinal.dir\src\main.c.i

CMakeFiles/ProjetoFinal.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ProjetoFinal.dir/src/main.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Vinicius\Desktop\BANCO-LAED-II\src\main.c -o CMakeFiles\ProjetoFinal.dir\src\main.c.s

CMakeFiles/ProjetoFinal.dir/lib/cliente.c.obj: CMakeFiles/ProjetoFinal.dir/flags.make
CMakeFiles/ProjetoFinal.dir/lib/cliente.c.obj: C:/Users/Vinicius/Desktop/BANCO-LAED-II/lib/cliente.c
CMakeFiles/ProjetoFinal.dir/lib/cliente.c.obj: CMakeFiles/ProjetoFinal.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\Vinicius\Desktop\BANCO-LAED-II\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ProjetoFinal.dir/lib/cliente.c.obj"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/ProjetoFinal.dir/lib/cliente.c.obj -MF CMakeFiles\ProjetoFinal.dir\lib\cliente.c.obj.d -o CMakeFiles\ProjetoFinal.dir\lib\cliente.c.obj -c C:\Users\Vinicius\Desktop\BANCO-LAED-II\lib\cliente.c

CMakeFiles/ProjetoFinal.dir/lib/cliente.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/ProjetoFinal.dir/lib/cliente.c.i"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\Vinicius\Desktop\BANCO-LAED-II\lib\cliente.c > CMakeFiles\ProjetoFinal.dir\lib\cliente.c.i

CMakeFiles/ProjetoFinal.dir/lib/cliente.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/ProjetoFinal.dir/lib/cliente.c.s"
	C:\MinGW\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\Vinicius\Desktop\BANCO-LAED-II\lib\cliente.c -o CMakeFiles\ProjetoFinal.dir\lib\cliente.c.s

# Object files for target ProjetoFinal
ProjetoFinal_OBJECTS = \
"CMakeFiles/ProjetoFinal.dir/src/main.c.obj" \
"CMakeFiles/ProjetoFinal.dir/lib/cliente.c.obj"

# External object files for target ProjetoFinal
ProjetoFinal_EXTERNAL_OBJECTS =

ProjetoFinal.exe: CMakeFiles/ProjetoFinal.dir/src/main.c.obj
ProjetoFinal.exe: CMakeFiles/ProjetoFinal.dir/lib/cliente.c.obj
ProjetoFinal.exe: CMakeFiles/ProjetoFinal.dir/build.make
ProjetoFinal.exe: CMakeFiles/ProjetoFinal.dir/linkLibs.rsp
ProjetoFinal.exe: CMakeFiles/ProjetoFinal.dir/objects1.rsp
ProjetoFinal.exe: CMakeFiles/ProjetoFinal.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\Vinicius\Desktop\BANCO-LAED-II\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable ProjetoFinal.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ProjetoFinal.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ProjetoFinal.dir/build: ProjetoFinal.exe
.PHONY : CMakeFiles/ProjetoFinal.dir/build

CMakeFiles/ProjetoFinal.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ProjetoFinal.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ProjetoFinal.dir/clean

CMakeFiles/ProjetoFinal.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\Vinicius\Desktop\BANCO-LAED-II C:\Users\Vinicius\Desktop\BANCO-LAED-II C:\Users\Vinicius\Desktop\BANCO-LAED-II\build C:\Users\Vinicius\Desktop\BANCO-LAED-II\build C:\Users\Vinicius\Desktop\BANCO-LAED-II\build\CMakeFiles\ProjetoFinal.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/ProjetoFinal.dir/depend

