# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/lavalse/STCoreLibrary/STCoreLibrary

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/lavalse/STCoreLibrary/STCoreLibrary/build

# Include any dependencies generated for this target.
include reader/CMakeFiles/stap_reader.dir/depend.make

# Include the progress variables for this target.
include reader/CMakeFiles/stap_reader.dir/progress.make

# Include the compile flags for this target's objects.
include reader/CMakeFiles/stap_reader.dir/flags.make

reader/CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.o: reader/CMakeFiles/stap_reader.dir/flags.make
reader/CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.o: ../reader/showtap_file_reader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lavalse/STCoreLibrary/STCoreLibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object reader/CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.o"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.o -c /Users/lavalse/STCoreLibrary/STCoreLibrary/reader/showtap_file_reader.cpp

reader/CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.i"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lavalse/STCoreLibrary/STCoreLibrary/reader/showtap_file_reader.cpp > CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.i

reader/CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.s"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lavalse/STCoreLibrary/STCoreLibrary/reader/showtap_file_reader.cpp -o CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.s

reader/CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.o: reader/CMakeFiles/stap_reader.dir/flags.make
reader/CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.o: ../reader/dto/showtap_object.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lavalse/STCoreLibrary/STCoreLibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object reader/CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.o"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.o -c /Users/lavalse/STCoreLibrary/STCoreLibrary/reader/dto/showtap_object.cpp

reader/CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.i"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lavalse/STCoreLibrary/STCoreLibrary/reader/dto/showtap_object.cpp > CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.i

reader/CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.s"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lavalse/STCoreLibrary/STCoreLibrary/reader/dto/showtap_object.cpp -o CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.s

reader/CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.o: reader/CMakeFiles/stap_reader.dir/flags.make
reader/CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.o: ../reader/dto/thumbnail_info.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/lavalse/STCoreLibrary/STCoreLibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object reader/CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.o"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && /Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.o -c /Users/lavalse/STCoreLibrary/STCoreLibrary/reader/dto/thumbnail_info.cpp

reader/CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.i"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/lavalse/STCoreLibrary/STCoreLibrary/reader/dto/thumbnail_info.cpp > CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.i

reader/CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.s"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && /Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/lavalse/STCoreLibrary/STCoreLibrary/reader/dto/thumbnail_info.cpp -o CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.s

# Object files for target stap_reader
stap_reader_OBJECTS = \
"CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.o" \
"CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.o" \
"CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.o"

# External object files for target stap_reader
stap_reader_EXTERNAL_OBJECTS =

reader/libstap_reader.dylib: reader/CMakeFiles/stap_reader.dir/showtap_file_reader.cpp.o
reader/libstap_reader.dylib: reader/CMakeFiles/stap_reader.dir/dto/showtap_object.cpp.o
reader/libstap_reader.dylib: reader/CMakeFiles/stap_reader.dir/dto/thumbnail_info.cpp.o
reader/libstap_reader.dylib: reader/CMakeFiles/stap_reader.dir/build.make
reader/libstap_reader.dylib: reader/CMakeFiles/stap_reader.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/lavalse/STCoreLibrary/STCoreLibrary/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX shared library libstap_reader.dylib"
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/stap_reader.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
reader/CMakeFiles/stap_reader.dir/build: reader/libstap_reader.dylib

.PHONY : reader/CMakeFiles/stap_reader.dir/build

reader/CMakeFiles/stap_reader.dir/clean:
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader && $(CMAKE_COMMAND) -P CMakeFiles/stap_reader.dir/cmake_clean.cmake
.PHONY : reader/CMakeFiles/stap_reader.dir/clean

reader/CMakeFiles/stap_reader.dir/depend:
	cd /Users/lavalse/STCoreLibrary/STCoreLibrary/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/lavalse/STCoreLibrary/STCoreLibrary /Users/lavalse/STCoreLibrary/STCoreLibrary/reader /Users/lavalse/STCoreLibrary/STCoreLibrary/build /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader /Users/lavalse/STCoreLibrary/STCoreLibrary/build/reader/CMakeFiles/stap_reader.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : reader/CMakeFiles/stap_reader.dir/depend
