# CMake generated Testfile for 
# Source directory: /home/nikola/ws_moveit/src/moveit_task_constructor/core/python
# Build directory: /home/nikola/ws_moveit/build/moveit_task_constructor_core/python
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(_ctest_moveit_task_constructor_core_nosetests_test "/home/nikola/ws_moveit/build/moveit_task_constructor_core/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/nikola/ws_moveit/build/moveit_task_constructor_core/test_results/moveit_task_constructor_core/nosetests-test.xml" "--return-code" "\"/usr/bin/cmake\" -E make_directory /home/nikola/ws_moveit/build/moveit_task_constructor_core/test_results/moveit_task_constructor_core" "/usr/bin/nosetests3 -P --process-timeout=60 --where=/home/nikola/ws_moveit/src/moveit_task_constructor/core/python/test --with-xunit --xunit-file=/home/nikola/ws_moveit/build/moveit_task_constructor_core/test_results/moveit_task_constructor_core/nosetests-test.xml")
set_tests_properties(_ctest_moveit_task_constructor_core_nosetests_test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/catkin/cmake/test/nosetests.cmake;83;catkin_run_tests_target;/home/nikola/ws_moveit/src/moveit_task_constructor/core/python/CMakeLists.txt;40;catkin_add_nosetests;/home/nikola/ws_moveit/src/moveit_task_constructor/core/python/CMakeLists.txt;0;")
add_test(_ctest_moveit_task_constructor_core_rostest_python_test_rostest_mtc.test "/home/nikola/ws_moveit/build/moveit_task_constructor_core/catkin_generated/env_cached.sh" "/usr/bin/python3" "/opt/ros/noetic/share/catkin/cmake/test/run_tests.py" "/home/nikola/ws_moveit/build/moveit_task_constructor_core/test_results/moveit_task_constructor_core/rostest-python_test_rostest_mtc.xml" "--return-code" "/usr/bin/python3 /opt/ros/noetic/share/rostest/cmake/../../../bin/rostest --pkgdir=/home/nikola/ws_moveit/src/moveit_task_constructor/core --package=moveit_task_constructor_core --results-filename python_test_rostest_mtc.xml --results-base-dir \"/home/nikola/ws_moveit/build/moveit_task_constructor_core/test_results\" /home/nikola/ws_moveit/src/moveit_task_constructor/core/python/test/rostest_mtc.test ")
set_tests_properties(_ctest_moveit_task_constructor_core_rostest_python_test_rostest_mtc.test PROPERTIES  _BACKTRACE_TRIPLES "/opt/ros/noetic/share/catkin/cmake/test/tests.cmake;160;add_test;/opt/ros/noetic/share/rostest/cmake/rostest-extras.cmake;52;catkin_run_tests_target;/home/nikola/ws_moveit/src/moveit_task_constructor/core/python/CMakeLists.txt;43;add_rostest;/home/nikola/ws_moveit/src/moveit_task_constructor/core/python/CMakeLists.txt;0;")
subdirs("pybind11")
subdirs("bindings")
