cmake_minimum_required(VERSION 3.0.2)
project(vision_pkg)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
  rospy
  roscpp
  std_msgs
  pcl_ros
  pcl_conversions
  rosbag
  tf2_ros
  tf2_eigen
  tf2_geometry_msgs
  message_filters
)

find_package(Eigen3 REQUIRED)
find_package(Boost REQUIRED system filesystem date_time thread)

set(THIS_PACKAGE_INCLUDE_DIRS
doc/interactivity/include
)

catkin_package(
LIBRARIES
INCLUDE_DIRS
CATKIN_DEPENDS
  tf2_geometry_msgs
  message_filters
DEPENDS
  EIGEN3
)

###########
## Build ##
###########

include_directories(${THIS_PACKAGE_INCLUDE_DIRS})
include_directories(SYSTEM ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIRS})

add_executable(cloud_merger src/cloud_merger.cpp)
target_link_libraries(cloud_merger ${catkin_LIBRARIES} ${Boost_LIBRARIES})