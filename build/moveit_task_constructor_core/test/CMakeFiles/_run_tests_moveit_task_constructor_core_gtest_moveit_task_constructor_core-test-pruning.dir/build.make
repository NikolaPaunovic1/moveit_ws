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
CMAKE_SOURCE_DIR = /home/nikola/ws_moveit/src/moveit_task_constructor/core

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nikola/ws_moveit/build/moveit_task_constructor_core

# Utility rule file for _run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.

# Include the progress variables for this target.
include test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/progress.make

test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning:
	cd /home/nikola/ws_moveit/build/moveit_task_constructor_core/test && ../catkin_generated/env_cached.sh /usr/bin/python3 /opt/ros/noetic/share/catkin/cmake/test/run_tests.py /home/nikola/ws_moveit/build/moveit_task_constructor_core/test_results/moveit_task_constructor_core/gtest-moveit_task_constructor_core-test-pruning.xml "/home/nikola/ws_moveit/devel/.private/moveit_task_constructor_core/lib/moveit_task_constructor_core/moveit_task_constructor_core-test-pruning --gtest_output=xml:/home/nikola/ws_moveit/build/moveit_task_constructor_core/test_results/moveit_task_constructor_core/gtest-moveit_task_constructor_core-test-pruning.xml"

_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning: test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning
_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning: test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/build.make

.PHONY : _run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning

# Rule to build all files generated by this target.
test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/build: _run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning

.PHONY : test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/build

test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/clean:
	cd /home/nikola/ws_moveit/build/moveit_task_constructor_core/test && $(CMAKE_COMMAND) -P CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/cmake_clean.cmake
.PHONY : test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/clean

test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/depend:
	cd /home/nikola/ws_moveit/build/moveit_task_constructor_core && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nikola/ws_moveit/src/moveit_task_constructor/core /home/nikola/ws_moveit/src/moveit_task_constructor/core/test /home/nikola/ws_moveit/build/moveit_task_constructor_core /home/nikola/ws_moveit/build/moveit_task_constructor_core/test /home/nikola/ws_moveit/build/moveit_task_constructor_core/test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : test/CMakeFiles/_run_tests_moveit_task_constructor_core_gtest_moveit_task_constructor_core-test-pruning.dir/depend
