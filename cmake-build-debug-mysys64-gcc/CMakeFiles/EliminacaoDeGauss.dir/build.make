# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.19

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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss\cmake-build-debug-mysys64-gcc

# Include any dependencies generated for this target.
include CMakeFiles/EliminacaoDeGauss.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EliminacaoDeGauss.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EliminacaoDeGauss.dir/flags.make

CMakeFiles/EliminacaoDeGauss.dir/EliminacaoGauss.cpp.obj: CMakeFiles/EliminacaoDeGauss.dir/flags.make
CMakeFiles/EliminacaoDeGauss.dir/EliminacaoGauss.cpp.obj: ../EliminacaoGauss.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss\cmake-build-debug-mysys64-gcc\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/EliminacaoDeGauss.dir/EliminacaoGauss.cpp.obj"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\EliminacaoDeGauss.dir\EliminacaoGauss.cpp.obj -c S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss\EliminacaoGauss.cpp

CMakeFiles/EliminacaoDeGauss.dir/EliminacaoGauss.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EliminacaoDeGauss.dir/EliminacaoGauss.cpp.i"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss\EliminacaoGauss.cpp > CMakeFiles\EliminacaoDeGauss.dir\EliminacaoGauss.cpp.i

CMakeFiles/EliminacaoDeGauss.dir/EliminacaoGauss.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EliminacaoDeGauss.dir/EliminacaoGauss.cpp.s"
	C:\msys64\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss\EliminacaoGauss.cpp -o CMakeFiles\EliminacaoDeGauss.dir\EliminacaoGauss.cpp.s

# Object files for target EliminacaoDeGauss
EliminacaoDeGauss_OBJECTS = \
"CMakeFiles/EliminacaoDeGauss.dir/EliminacaoGauss.cpp.obj"

# External object files for target EliminacaoDeGauss
EliminacaoDeGauss_EXTERNAL_OBJECTS =

EliminacaoDeGauss.exe: CMakeFiles/EliminacaoDeGauss.dir/EliminacaoGauss.cpp.obj
EliminacaoDeGauss.exe: CMakeFiles/EliminacaoDeGauss.dir/build.make
EliminacaoDeGauss.exe: CMakeFiles/EliminacaoDeGauss.dir/linklibs.rsp
EliminacaoDeGauss.exe: CMakeFiles/EliminacaoDeGauss.dir/objects1.rsp
EliminacaoDeGauss.exe: CMakeFiles/EliminacaoDeGauss.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss\cmake-build-debug-mysys64-gcc\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable EliminacaoDeGauss.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\EliminacaoDeGauss.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EliminacaoDeGauss.dir/build: EliminacaoDeGauss.exe

.PHONY : CMakeFiles/EliminacaoDeGauss.dir/build

CMakeFiles/EliminacaoDeGauss.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\EliminacaoDeGauss.dir\cmake_clean.cmake
.PHONY : CMakeFiles/EliminacaoDeGauss.dir/clean

CMakeFiles/EliminacaoDeGauss.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss\cmake-build-debug-mysys64-gcc S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss\cmake-build-debug-mysys64-gcc S:\Programacao\CParalelaUfrgs2020_2\EliminacaoDeGauss\cmake-build-debug-mysys64-gcc\CMakeFiles\EliminacaoDeGauss.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EliminacaoDeGauss.dir/depend

