# Install script for directory: /home/nikola/ws_moveit/src/moveit_task_constructor/visualization/motion_planning_tasks/src

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/nikola/ws_moveit/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so.0.1.3" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so.0.1.3")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so.0.1.3"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/nikola/ws_moveit/devel/.private/moveit_task_constructor_visualization/lib/libmotion_planning_tasks_rviz_plugin.so.0.1.3")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so.0.1.3" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so.0.1.3")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so.0.1.3"
         OLD_RPATH "/home/nikola/ws_moveit/devel/.private/moveit_task_constructor_visualization/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_visualization/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_planning_interface/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_warehouse/lib:/opt/ros/noetic/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_manipulation/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_move_group/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_robot_interaction/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_planning/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_occupancy_map_monitor/lib:/home/nikola/ws_moveit/devel/.private/moveit_task_constructor_core/lib:/home/nikola/ws_moveit/devel/.private/moveit_core/lib:/opt/ros/noetic/lib/x86_64-linux-gnu:/home/nikola/ws_moveit/devel/.private/geometric_shapes/lib:/home/nikola/ws_moveit/devel/.private/srdfdom/lib:/home/nikola/ws_moveit/devel/.private/rviz_marker_tools/lib:/opt/ros/noetic/share/rviz/cmake/../../../lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so.0.1.3")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so"
         RPATH "")
  endif()
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib" TYPE SHARED_LIBRARY FILES "/home/nikola/ws_moveit/devel/.private/moveit_task_constructor_visualization/lib/libmotion_planning_tasks_rviz_plugin.so")
  if(EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so")
    file(RPATH_CHANGE
         FILE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so"
         OLD_RPATH "/home/nikola/ws_moveit/devel/.private/moveit_task_constructor_visualization/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_visualization/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_planning_interface/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_warehouse/lib:/opt/ros/noetic/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_manipulation/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_move_group/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_robot_interaction/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_planning/lib:/home/nikola/ws_moveit/devel/.private/moveit_ros_occupancy_map_monitor/lib:/home/nikola/ws_moveit/devel/.private/moveit_task_constructor_core/lib:/home/nikola/ws_moveit/devel/.private/moveit_core/lib:/opt/ros/noetic/lib/x86_64-linux-gnu:/home/nikola/ws_moveit/devel/.private/geometric_shapes/lib:/home/nikola/ws_moveit/devel/.private/srdfdom/lib:/home/nikola/ws_moveit/devel/.private/rviz_marker_tools/lib:/opt/ros/noetic/share/rviz/cmake/../../../lib:"
         NEW_RPATH "")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/lib/libmotion_planning_tasks_rviz_plugin.so")
    endif()
  endif()
endif()

