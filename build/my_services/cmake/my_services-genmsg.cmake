# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "my_services: 14 messages, 2 services")

set(MSG_I_FLAGS "-Imy_services:/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg;-Iactionlib_msgs:/opt/ros/noetic/share/actionlib_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/noetic/share/geometry_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/noetic/share/sensor_msgs/cmake/../msg;-Istd_msgs:/opt/ros/noetic/share/std_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(my_services_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg" "geometry_msgs/Quaternion:my_services/PickPlaceActionFeedback:my_services/PickPlaceFeedback:std_msgs/Header:geometry_msgs/Point:actionlib_msgs/GoalID:my_services/PickPlaceActionResult:my_services/PickPlaceResult:my_services/PickPlaceGoal:actionlib_msgs/GoalStatus:my_services/PickPlaceActionGoal:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg" "geometry_msgs/Quaternion:std_msgs/Header:geometry_msgs/Point:actionlib_msgs/GoalID:my_services/PickPlaceGoal:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg" "std_msgs/Header:my_services/PickPlaceResult:actionlib_msgs/GoalStatus:actionlib_msgs/GoalID"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg" "my_services/PickPlaceFeedback:std_msgs/Header:actionlib_msgs/GoalStatus:actionlib_msgs/GoalID"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg" "geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg" ""
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg" ""
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg" "my_services/PickPlace2ActionGoal:geometry_msgs/Quaternion:std_msgs/Header:geometry_msgs/Point:actionlib_msgs/GoalID:my_services/PickPlace2Result:my_services/PickPlace2ActionResult:my_services/PickPlace2Goal:my_services/PickPlace2Feedback:my_services/PickPlace2ActionFeedback:actionlib_msgs/GoalStatus:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg" "geometry_msgs/Quaternion:std_msgs/Header:geometry_msgs/Point:actionlib_msgs/GoalID:my_services/PickPlace2Goal:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg" "std_msgs/Header:actionlib_msgs/GoalStatus:actionlib_msgs/GoalID:my_services/PickPlace2Result"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg" "std_msgs/Header:actionlib_msgs/GoalStatus:actionlib_msgs/GoalID:my_services/PickPlace2Feedback"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg" "geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg" ""
)

get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg" ""
)

get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv" "geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Pose"
)

get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv" NAME_WE)
add_custom_target(_my_services_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "my_services" "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv" "geometry_msgs/Quaternion:geometry_msgs/Point:geometry_msgs/Pose"
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_msg_cpp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)

### Generating Services
_generate_srv_cpp(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)
_generate_srv_cpp(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
)

### Generating Module File
_generate_module_cpp(my_services
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(my_services_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(my_services_generate_messages my_services_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_cpp _my_services_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_services_gencpp)
add_dependencies(my_services_gencpp my_services_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_services_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_msg_eus(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)

### Generating Services
_generate_srv_eus(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)
_generate_srv_eus(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
)

### Generating Module File
_generate_module_eus(my_services
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(my_services_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(my_services_generate_messages my_services_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_eus _my_services_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_services_geneus)
add_dependencies(my_services_geneus my_services_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_services_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_msg_lisp(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)

### Generating Services
_generate_srv_lisp(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)
_generate_srv_lisp(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
)

### Generating Module File
_generate_module_lisp(my_services
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(my_services_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(my_services_generate_messages my_services_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_lisp _my_services_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_services_genlisp)
add_dependencies(my_services_genlisp my_services_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_services_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_msg_nodejs(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)

### Generating Services
_generate_srv_nodejs(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)
_generate_srv_nodejs(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
)

### Generating Module File
_generate_module_nodejs(my_services
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(my_services_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(my_services_generate_messages my_services_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_nodejs _my_services_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_services_gennodejs)
add_dependencies(my_services_gennodejs my_services_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_services_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg"
  "${MSG_I_FLAGS}"
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/std_msgs/cmake/../msg/Header.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalStatus.msg;/opt/ros/noetic/share/actionlib_msgs/cmake/../msg/GoalID.msg;/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_msg_py(my_services
  "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)

### Generating Services
_generate_srv_py(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)
_generate_srv_py(my_services
  "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv"
  "${MSG_I_FLAGS}"
  "/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Quaternion.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Point.msg;/opt/ros/noetic/share/geometry_msgs/cmake/../msg/Pose.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
)

### Generating Module File
_generate_module_py(my_services
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(my_services_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(my_services_generate_messages my_services_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceAction.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlaceFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Action.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionGoal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionResult.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2ActionFeedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Goal.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Result.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/devel/.private/my_services/share/my_services/msg/PickPlace2Feedback.msg" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/ObjectPositionService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/nikola/ws_moveit/src/my_services/srv/PoseFinderService.srv" NAME_WE)
add_dependencies(my_services_generate_messages_py _my_services_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(my_services_genpy)
add_dependencies(my_services_genpy my_services_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS my_services_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/my_services
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_cpp)
  add_dependencies(my_services_generate_messages_cpp actionlib_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(my_services_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET sensor_msgs_generate_messages_cpp)
  add_dependencies(my_services_generate_messages_cpp sensor_msgs_generate_messages_cpp)
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(my_services_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/my_services
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_eus)
  add_dependencies(my_services_generate_messages_eus actionlib_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(my_services_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET sensor_msgs_generate_messages_eus)
  add_dependencies(my_services_generate_messages_eus sensor_msgs_generate_messages_eus)
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(my_services_generate_messages_eus std_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/my_services
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_lisp)
  add_dependencies(my_services_generate_messages_lisp actionlib_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(my_services_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET sensor_msgs_generate_messages_lisp)
  add_dependencies(my_services_generate_messages_lisp sensor_msgs_generate_messages_lisp)
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(my_services_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/my_services
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_nodejs)
  add_dependencies(my_services_generate_messages_nodejs actionlib_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(my_services_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET sensor_msgs_generate_messages_nodejs)
  add_dependencies(my_services_generate_messages_nodejs sensor_msgs_generate_messages_nodejs)
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(my_services_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services)
  install(CODE "execute_process(COMMAND \"/usr/bin/python3\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/my_services
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET actionlib_msgs_generate_messages_py)
  add_dependencies(my_services_generate_messages_py actionlib_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(my_services_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET sensor_msgs_generate_messages_py)
  add_dependencies(my_services_generate_messages_py sensor_msgs_generate_messages_py)
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(my_services_generate_messages_py std_msgs_generate_messages_py)
endif()
