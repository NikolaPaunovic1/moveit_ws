cmake_minimum_required(VERSION 3.1.3)
project(expanda)

find_package(catkin REQUIRED
  COMPONENTS
    interactive_markers
    moveit_core
    moveit_ros_planning
    moveit_ros_planning_interface
    moveit_ros_perception
    rviz_visual_tools
    moveit_visual_tools
    pluginlib
    geometric_shapes
    pcl_ros
    pcl_conversions
    rosbag
    tf2_ros
    tf2_eigen
    tf2_geometry_msgs
    franka_gripper
    my_services
    message_filters
    #control_msgs
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
    moveit_core
    moveit_visual_tools
    moveit_ros_planning_interface
    interactive_markers
    tf2_geometry_msgs
    franka_gripper
    my_services
    rosbag
    message_filters
    #control_msgs
  DEPENDS
    EIGEN3
)

###########
## Build ##
###########

include_directories(${THIS_PACKAGE_INCLUDE_DIRS})
include_directories(SYSTEM ${catkin_INCLUDE_DIRS} ${Boost_INCLUDE_DIR} ${EIGEN3_INCLUDE_DIRS})

add_executable(mg_interface src/mg_interface.cpp)
target_link_libraries(mg_interface ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS mg_interface DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(gazebo_pick src/gazebo_pick.cpp)
target_link_libraries(gazebo_pick ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS gazebo_pick DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(pick_place src/pick_place.cpp)
target_link_libraries(pick_place ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS pick_place DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(depthcam_demo src/depthcam_demo.cpp)
target_link_libraries(depthcam_demo ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS depthcam_demo DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(object_detection_demo src/object_detection_demo.cpp)
target_link_libraries(object_detection_demo ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS object_detection_demo DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(icp_node src/icp_node.cpp)
target_link_libraries(icp_node ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS icp_node DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(icp2_node src/icp2_node.cpp)
target_link_libraries(icp2_node ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS icp2_node DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(cloud_merger src/cloud_merger.cpp)
target_link_libraries(cloud_merger ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS cloud_merger DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(cloud_merger_worldframe src/cloud_merger_worldframe.cpp)
target_link_libraries(cloud_merger_worldframe ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS cloud_merger_worldframe DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(track_object src/track_object.cpp)
target_link_libraries(track_object ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS track_object DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(multicam_track src/multicam_track.cpp)
target_link_libraries(multicam_track ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS multicam_track DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(multiobject_multicam_track src/multiobject_multicam_track.cpp)
target_link_libraries(multiobject_multicam_track ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS multiobject_multicam_track DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(testing_pickplace_server src/testing_pickplace_server.cpp)
target_link_libraries(testing_pickplace_server ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS testing_pickplace_server DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(triplet_detection src/triplet_detection.cpp)
target_link_libraries(triplet_detection ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS triplet_detection DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(pcl_bagpublisher src/pcl_bagpublisher.cpp)
target_link_libraries(pcl_bagpublisher ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS pcl_bagpublisher DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(cam_tripod_spawner src/cam_tripod_spawner.cpp)
target_link_libraries(cam_tripod_spawner ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS cam_tripod_spawner DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(multimesh_spawner src/multimesh_spawner.cpp)
target_link_libraries(multimesh_spawner ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS multimesh_spawner DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(eight_mesh_spawner src/eight_mesh_spawner.cpp)
target_link_libraries(eight_mesh_spawner ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS eight_mesh_spawner DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(test_smart_pickplace src/test_smart_pickplace.cpp)
target_link_libraries(test_smart_pickplace ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS test_smart_pickplace DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

add_executable(MT_Demo src/MT_Demo.cpp)
target_link_libraries(MT_Demo ${catkin_LIBRARIES} ${Boost_LIBRARIES})
install(TARGETS MT_Demo DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION})

install(DIRECTORY launch DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION})

