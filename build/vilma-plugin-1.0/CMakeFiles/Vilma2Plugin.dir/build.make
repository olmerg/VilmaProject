# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/tiberio/catkin_ws/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/tiberio/catkin_ws/build

# Include any dependencies generated for this target.
include vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/depend.make

# Include the progress variables for this target.
include vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/progress.make

# Include the compile flags for this target's objects.
include vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/flags.make

vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o: vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/flags.make
vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o: /home/tiberio/catkin_ws/src/vilma-plugin-1.0/src/Vilma2/DRCVehiclePlugin.cc
	$(CMAKE_COMMAND) -E cmake_progress_report /home/tiberio/catkin_ws/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o"
	cd /home/tiberio/catkin_ws/build/vilma-plugin-1.0 && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o -c /home/tiberio/catkin_ws/src/vilma-plugin-1.0/src/Vilma2/DRCVehiclePlugin.cc

vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.i"
	cd /home/tiberio/catkin_ws/build/vilma-plugin-1.0 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/tiberio/catkin_ws/src/vilma-plugin-1.0/src/Vilma2/DRCVehiclePlugin.cc > CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.i

vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.s"
	cd /home/tiberio/catkin_ws/build/vilma-plugin-1.0 && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/tiberio/catkin_ws/src/vilma-plugin-1.0/src/Vilma2/DRCVehiclePlugin.cc -o CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.s

vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o.requires:
.PHONY : vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o.requires

vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o.provides: vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o.requires
	$(MAKE) -f vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/build.make vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o.provides.build
.PHONY : vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o.provides

vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o.provides.build: vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o

# Object files for target Vilma2Plugin
Vilma2Plugin_OBJECTS = \
"CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o"

# External object files for target Vilma2Plugin
Vilma2Plugin_EXTERNAL_OBJECTS =

/home/tiberio/catkin_ws/devel/lib/libVilma2Plugin.so: vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o
/home/tiberio/catkin_ws/devel/lib/libVilma2Plugin.so: vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/build.make
/home/tiberio/catkin_ws/devel/lib/libVilma2Plugin.so: vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX shared library /home/tiberio/catkin_ws/devel/lib/libVilma2Plugin.so"
	cd /home/tiberio/catkin_ws/build/vilma-plugin-1.0 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Vilma2Plugin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/build: /home/tiberio/catkin_ws/devel/lib/libVilma2Plugin.so
.PHONY : vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/build

vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/requires: vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/src/Vilma2/DRCVehiclePlugin.cc.o.requires
.PHONY : vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/requires

vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/clean:
	cd /home/tiberio/catkin_ws/build/vilma-plugin-1.0 && $(CMAKE_COMMAND) -P CMakeFiles/Vilma2Plugin.dir/cmake_clean.cmake
.PHONY : vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/clean

vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/depend:
	cd /home/tiberio/catkin_ws/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/tiberio/catkin_ws/src /home/tiberio/catkin_ws/src/vilma-plugin-1.0 /home/tiberio/catkin_ws/build /home/tiberio/catkin_ws/build/vilma-plugin-1.0 /home/tiberio/catkin_ws/build/vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : vilma-plugin-1.0/CMakeFiles/Vilma2Plugin.dir/depend

