# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/adi/Desktop/learnopengl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/adi/Desktop/learnopengl/build

# Include any dependencies generated for this target.
include CMakeFiles/learn_open_gl.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/learn_open_gl.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/learn_open_gl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/learn_open_gl.dir/flags.make

CMakeFiles/learn_open_gl.dir/src/glad.c.o: CMakeFiles/learn_open_gl.dir/flags.make
CMakeFiles/learn_open_gl.dir/src/glad.c.o: ../src/glad.c
CMakeFiles/learn_open_gl.dir/src/glad.c.o: CMakeFiles/learn_open_gl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/Desktop/learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/learn_open_gl.dir/src/glad.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/learn_open_gl.dir/src/glad.c.o -MF CMakeFiles/learn_open_gl.dir/src/glad.c.o.d -o CMakeFiles/learn_open_gl.dir/src/glad.c.o -c /home/adi/Desktop/learnopengl/src/glad.c

CMakeFiles/learn_open_gl.dir/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/learn_open_gl.dir/src/glad.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/adi/Desktop/learnopengl/src/glad.c > CMakeFiles/learn_open_gl.dir/src/glad.c.i

CMakeFiles/learn_open_gl.dir/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/learn_open_gl.dir/src/glad.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/adi/Desktop/learnopengl/src/glad.c -o CMakeFiles/learn_open_gl.dir/src/glad.c.s

CMakeFiles/learn_open_gl.dir/src/main.cpp.o: CMakeFiles/learn_open_gl.dir/flags.make
CMakeFiles/learn_open_gl.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/learn_open_gl.dir/src/main.cpp.o: CMakeFiles/learn_open_gl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/Desktop/learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/learn_open_gl.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/learn_open_gl.dir/src/main.cpp.o -MF CMakeFiles/learn_open_gl.dir/src/main.cpp.o.d -o CMakeFiles/learn_open_gl.dir/src/main.cpp.o -c /home/adi/Desktop/learnopengl/src/main.cpp

CMakeFiles/learn_open_gl.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn_open_gl.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/Desktop/learnopengl/src/main.cpp > CMakeFiles/learn_open_gl.dir/src/main.cpp.i

CMakeFiles/learn_open_gl.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn_open_gl.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/Desktop/learnopengl/src/main.cpp -o CMakeFiles/learn_open_gl.dir/src/main.cpp.s

CMakeFiles/learn_open_gl.dir/src/EBO.cpp.o: CMakeFiles/learn_open_gl.dir/flags.make
CMakeFiles/learn_open_gl.dir/src/EBO.cpp.o: ../src/EBO.cpp
CMakeFiles/learn_open_gl.dir/src/EBO.cpp.o: CMakeFiles/learn_open_gl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/Desktop/learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/learn_open_gl.dir/src/EBO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/learn_open_gl.dir/src/EBO.cpp.o -MF CMakeFiles/learn_open_gl.dir/src/EBO.cpp.o.d -o CMakeFiles/learn_open_gl.dir/src/EBO.cpp.o -c /home/adi/Desktop/learnopengl/src/EBO.cpp

CMakeFiles/learn_open_gl.dir/src/EBO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn_open_gl.dir/src/EBO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/Desktop/learnopengl/src/EBO.cpp > CMakeFiles/learn_open_gl.dir/src/EBO.cpp.i

CMakeFiles/learn_open_gl.dir/src/EBO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn_open_gl.dir/src/EBO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/Desktop/learnopengl/src/EBO.cpp -o CMakeFiles/learn_open_gl.dir/src/EBO.cpp.s

CMakeFiles/learn_open_gl.dir/src/VBO.cpp.o: CMakeFiles/learn_open_gl.dir/flags.make
CMakeFiles/learn_open_gl.dir/src/VBO.cpp.o: ../src/VBO.cpp
CMakeFiles/learn_open_gl.dir/src/VBO.cpp.o: CMakeFiles/learn_open_gl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/Desktop/learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/learn_open_gl.dir/src/VBO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/learn_open_gl.dir/src/VBO.cpp.o -MF CMakeFiles/learn_open_gl.dir/src/VBO.cpp.o.d -o CMakeFiles/learn_open_gl.dir/src/VBO.cpp.o -c /home/adi/Desktop/learnopengl/src/VBO.cpp

CMakeFiles/learn_open_gl.dir/src/VBO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn_open_gl.dir/src/VBO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/Desktop/learnopengl/src/VBO.cpp > CMakeFiles/learn_open_gl.dir/src/VBO.cpp.i

CMakeFiles/learn_open_gl.dir/src/VBO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn_open_gl.dir/src/VBO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/Desktop/learnopengl/src/VBO.cpp -o CMakeFiles/learn_open_gl.dir/src/VBO.cpp.s

CMakeFiles/learn_open_gl.dir/src/VAO.cpp.o: CMakeFiles/learn_open_gl.dir/flags.make
CMakeFiles/learn_open_gl.dir/src/VAO.cpp.o: ../src/VAO.cpp
CMakeFiles/learn_open_gl.dir/src/VAO.cpp.o: CMakeFiles/learn_open_gl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/Desktop/learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/learn_open_gl.dir/src/VAO.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/learn_open_gl.dir/src/VAO.cpp.o -MF CMakeFiles/learn_open_gl.dir/src/VAO.cpp.o.d -o CMakeFiles/learn_open_gl.dir/src/VAO.cpp.o -c /home/adi/Desktop/learnopengl/src/VAO.cpp

CMakeFiles/learn_open_gl.dir/src/VAO.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn_open_gl.dir/src/VAO.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/Desktop/learnopengl/src/VAO.cpp > CMakeFiles/learn_open_gl.dir/src/VAO.cpp.i

CMakeFiles/learn_open_gl.dir/src/VAO.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn_open_gl.dir/src/VAO.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/Desktop/learnopengl/src/VAO.cpp -o CMakeFiles/learn_open_gl.dir/src/VAO.cpp.s

CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.o: CMakeFiles/learn_open_gl.dir/flags.make
CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.o: ../src/shaderClass.cpp
CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.o: CMakeFiles/learn_open_gl.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/adi/Desktop/learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.o -MF CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.o.d -o CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.o -c /home/adi/Desktop/learnopengl/src/shaderClass.cpp

CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/adi/Desktop/learnopengl/src/shaderClass.cpp > CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.i

CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/adi/Desktop/learnopengl/src/shaderClass.cpp -o CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.s

# Object files for target learn_open_gl
learn_open_gl_OBJECTS = \
"CMakeFiles/learn_open_gl.dir/src/glad.c.o" \
"CMakeFiles/learn_open_gl.dir/src/main.cpp.o" \
"CMakeFiles/learn_open_gl.dir/src/EBO.cpp.o" \
"CMakeFiles/learn_open_gl.dir/src/VBO.cpp.o" \
"CMakeFiles/learn_open_gl.dir/src/VAO.cpp.o" \
"CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.o"

# External object files for target learn_open_gl
learn_open_gl_EXTERNAL_OBJECTS =

learn_open_gl: CMakeFiles/learn_open_gl.dir/src/glad.c.o
learn_open_gl: CMakeFiles/learn_open_gl.dir/src/main.cpp.o
learn_open_gl: CMakeFiles/learn_open_gl.dir/src/EBO.cpp.o
learn_open_gl: CMakeFiles/learn_open_gl.dir/src/VBO.cpp.o
learn_open_gl: CMakeFiles/learn_open_gl.dir/src/VAO.cpp.o
learn_open_gl: CMakeFiles/learn_open_gl.dir/src/shaderClass.cpp.o
learn_open_gl: CMakeFiles/learn_open_gl.dir/build.make
learn_open_gl: CMakeFiles/learn_open_gl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/adi/Desktop/learnopengl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX executable learn_open_gl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/learn_open_gl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/learn_open_gl.dir/build: learn_open_gl
.PHONY : CMakeFiles/learn_open_gl.dir/build

CMakeFiles/learn_open_gl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/learn_open_gl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/learn_open_gl.dir/clean

CMakeFiles/learn_open_gl.dir/depend:
	cd /home/adi/Desktop/learnopengl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/adi/Desktop/learnopengl /home/adi/Desktop/learnopengl /home/adi/Desktop/learnopengl/build /home/adi/Desktop/learnopengl/build /home/adi/Desktop/learnopengl/build/CMakeFiles/learn_open_gl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/learn_open_gl.dir/depend
