
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
// TF2
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

// The circle constant tau = 2*pi. One tau is one rotation in radians.
const double tau = 2 * M_PI;

int main(int argc, char** argv)
{

  // Initialize Node and start looking for callbacks
  ros::init(argc, argv, "pick_place");
  ros::NodeHandle node_handle;

  ros::AsyncSpinner spinner(1);
  spinner.start();

  //-------------

  // Name of the planning Group
  static const std::string PLANNING_GROUP = "panda_arm";

  //Use MoveGroupInterface
  moveit::planning_interface::MoveGroupInterface move_group_interface(PLANNING_GROUP);

  // Interact with planning_scene through PlanningSceneInterface
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

  // Get JointModelGroup
  const moveit::core::JointModelGroup* joint_model_group =
      move_group_interface.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

  // Prolong Planning Time because we are working with constraints

  move_group_interface.setPlanningTime(20.0);

  // Visualization
  // ^^^^^^^^^^^^^
 
  //initialize Visual Tools
  namespace rvt = rviz_visual_tools;
  moveit_visual_tools::MoveItVisualTools visual_tools("panda_link0");
  visual_tools.deleteAllMarkers();

  // Remote control via buttons and keyboard shortcuts in RViz
  visual_tools.loadRemoteControl();

  // Use Text to describe what's happening
  Eigen::Isometry3d text_pose = Eigen::Isometry3d::Identity();
  text_pose.translation().z() = 1.0;
  visual_tools.publishText(text_pose, "Experimental Demo", rvt::WHITE, rvt::XLARGE);


  // Getting Basic Information
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  //
  // We can print the name of the reference frame for this robot.
  ROS_INFO_NAMED("tutorial", "Planning frame: %s", move_group_interface.getPlanningFrame().c_str());

  // We can also print the name of the end-effector link for this group.
  ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group_interface.getEndEffectorLink().c_str());

  // We can get a list of all the groups in the robot:
  ROS_INFO_NAMED("tutorial", "Available Planning Groups:");
  std::copy(move_group_interface.getJointModelGroupNames().begin(),
            move_group_interface.getJointModelGroupNames().end(), std::ostream_iterator<std::string>(std::cout, ", "));

  //-------------------------------------------------------------------------------------------


  // Start the demo
  // ^^^^^^^^^^^^^^^^^^^^^^^^^
  visual_tools.prompt("Press Next to spawn the environment!");

  
  // Get the current state so that you can return to it at the end of the demo!

  moveit::core::RobotStatePtr current_state = move_group_interface.getCurrentState();
  std::vector<double> joint_starting_position;
  current_state->copyJointGroupPositions(joint_model_group, joint_starting_position);

//--------------------------------------------------------
// ADD OBJECTS INTO THE WORLD


  // Define Collision Object
  moveit_msgs::CollisionObject collision_object;
  collision_object.header.frame_id = move_group_interface.getPlanningFrame();

  // The id of the object is used to identify it.
  collision_object.id = "box1";

  // Define a box to add to the world.
  shape_msgs::SolidPrimitive primitive;
  primitive.type = primitive.BOX;
  primitive.dimensions.resize(3);
  primitive.dimensions[primitive.BOX_X] = 0.5;
  primitive.dimensions[primitive.BOX_Y] = 0.2;
  primitive.dimensions[primitive.BOX_Z] = 0.4;

  // Define a pose for the box (specified relative to frame_id)
  geometry_msgs::Pose box_pose;
  box_pose.orientation.w = 1.0;
  box_pose.position.x = 0.5;
  box_pose.position.y = 0.0;
  box_pose.position.z = 0.2;

  collision_object.primitives.push_back(primitive);
  collision_object.primitive_poses.push_back(box_pose);
  collision_object.operation = collision_object.ADD;

  moveit_msgs::CollisionObject collision_object2;
  collision_object2.header.frame_id = move_group_interface.getPlanningFrame();

  // The id of the object is used to identify it.
  collision_object2.id = "box2";

  // Repeat for the second collision object
  geometry_msgs::Pose box2_pose;
  box2_pose.orientation.w = 1.0;
  box2_pose.position.x = 0.5;
  box2_pose.position.y = 0.4;
  box2_pose.position.z = 0.2;

  collision_object2.primitives.push_back(primitive);
  collision_object2.primitive_poses.push_back(box2_pose);
  collision_object2.operation = collision_object2.ADD;

  // add a third object to pick and place

  moveit_msgs::CollisionObject object3;
  object3.header.frame_id = move_group_interface.getPlanningFrame();
  object3.id = "object3";

  shape_msgs::SolidPrimitive primitive3;
  primitive3.type = primitive.BOX;
  primitive3.dimensions.resize(3);
  primitive3.dimensions[primitive.BOX_X] = 0.15;
  primitive3.dimensions[primitive.BOX_Y] = 0.02;
  primitive3.dimensions[primitive.BOX_Z] = 0.02;

  geometry_msgs::Pose object3_pose;
  object3_pose.orientation.w = 1.0;
  object3_pose.position.x = 0.5;
  object3_pose.position.y = 0.0;
  object3_pose.position.z = 0.01+0.4;

  object3.primitives.push_back(primitive3);
  object3.primitive_poses.push_back(object3_pose);
  object3.operation = object3.ADD;

  //add all the objects into one vector
  std::vector<moveit_msgs::CollisionObject> collision_objects;
  collision_objects.push_back(collision_object);
  collision_objects.push_back(collision_object2);
  collision_objects.push_back(object3);

  // Now, let's add the collision object into the world
  // (using a vector that could contain additional objects)
  ROS_INFO_NAMED("tutorial", "Add an object into the world");
  planning_scene_interface.applyCollisionObjects(collision_objects);

  // Show text in RViz of status and wait for MoveGroup to receive and process the collision object message
  visual_tools.publishText(text_pose, "Add object", rvt::WHITE, rvt::XLARGE);
  visual_tools.trigger();
  visual_tools.prompt("add wall or pick depending on demo version");

//--------------------------------------------------------------------------------

//ADDWALL-------------------------------------------------------------
  //add a wall as obstacle
  moveit_msgs::CollisionObject wall;
  wall.header.frame_id = move_group_interface.getPlanningFrame();

  // The id of the object is used to identify it.
  wall.id = "wall1";

  // Define a box to add to the world.
  shape_msgs::SolidPrimitive primitive2;
  primitive2.type = primitive.BOX;
  primitive2.dimensions.resize(3);
  primitive2.dimensions[primitive.BOX_X] = 1;
  primitive2.dimensions[primitive.BOX_Y] = 0.01;
  primitive2.dimensions[primitive.BOX_Z] = 1;

  // Define a pose for the box (specified relative to frame_id)
  geometry_msgs::Pose wall_pose;
  wall_pose.orientation.w = 1.0;
  wall_pose.position.x = 0.7;
  wall_pose.position.y = 0.2;
  wall_pose.position.z = 0.5;

  wall.primitives.push_back(primitive2);
  wall.primitive_poses.push_back(wall_pose);
  wall.operation = wall.ADD;

  ROS_INFO_NAMED("tutorial", "Add an obstacle into the world");
  planning_scene_interface.applyCollisionObject(wall);

  // set text so that user understands whats going on
  visual_tools.deleteAllMarkers();
  visual_tools.publishText(text_pose, "Add obstacle", rvt::WHITE, rvt::XLARGE);
  visual_tools.trigger();
  visual_tools.prompt("Press Next to place around the wall! or pick depending on demo version!");

//-------------------------------------------------------------------------------


  //PICK OBJECT


  std::vector<moveit_msgs::Grasp> grasps;
  grasps.resize(1);

  //Setting the Grasp_pose
  grasps[0].grasp_pose.header.frame_id = "panda_link0";
  grasps[0].max_contact_force = 10;
  tf2::Quaternion orientation;
  orientation.setRPY(0, -tau / 2, tau *3/ 8);
  grasps[0].grasp_pose.pose.orientation = tf2::toMsg(orientation);
  grasps[0].grasp_pose.pose.position.x = 0.5;
  grasps[0].grasp_pose.pose.position.y = 0.0;
  grasps[0].grasp_pose.pose.position.z = 0.52;

  // Setting pre-grasp approach
  grasps[0].pre_grasp_approach.direction.header.frame_id = move_group_interface.getPlanningFrame();
  /* Direction is set as positive z axis */
  grasps[0].pre_grasp_approach.direction.vector.z = -1.0;
  grasps[0].pre_grasp_approach.min_distance = 0.05;
  grasps[0].pre_grasp_approach.desired_distance = 0.12;

  // Setting post-grasp retreat
  // ++++++++++++++++++++++++++
  /* Defined with respect to frame_id */
  grasps[0].post_grasp_retreat.direction.header.frame_id = move_group_interface.getPlanningFrame();
  /* Direction is set as positive z axis */
  grasps[0].post_grasp_retreat.direction.vector.z = 1.0;
  grasps[0].post_grasp_retreat.min_distance = 0.05;
  grasps[0].post_grasp_retreat.desired_distance = 0.12;


  // Set pre_grasp Posture

  trajectory_msgs::JointTrajectory& posture_pre = grasps[0].pre_grasp_posture; 
  posture_pre.joint_names.resize(2);
  posture_pre.joint_names[0] = "panda_finger_joint1";
  posture_pre.joint_names[1] = "panda_finger_joint2";

  /* Set them as open, wide enough for the object to fit. */
  posture_pre.points.resize(1);
  posture_pre.points[0].positions.resize(2);
  posture_pre.points[0].positions[0] = 0.04;
  posture_pre.points[0].positions[1] = 0.04;
  posture_pre.points[0].time_from_start = ros::Duration(0.5);

  //Set grasp_posture
  trajectory_msgs::JointTrajectory& posture = grasps[0].grasp_posture;
  posture.joint_names.resize(2);
  posture.joint_names[0] = "panda_finger_joint1";
  posture.joint_names[1] = "panda_finger_joint2";

  /* Set them as closed. */
  posture.points.resize(1);
  posture.points[0].positions.resize(2);
  posture.points[0].positions[0] = 0.009;
  posture.points[0].positions[1] = 0.009;
  posture.points[0].time_from_start = ros::Duration(0.5);




  //what is the structure youre going to pick the object from
  move_group_interface.setSupportSurfaceName("box1");
  // Call pick to pick up the object using the grasps given
  move_group_interface.pick("object3", grasps);

  visual_tools.prompt("Press Next to spawn an obstacle");

  // //PLACE OBJECT
  // //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  std::vector<moveit_msgs::PlaceLocation> place_location;
  place_location.resize(1);

  // Setting place location pose
  // +++++++++++++++++++++++++++
  place_location[0].place_pose.header.frame_id = "panda_link0";
  tf2::Quaternion orientation2;
  orientation2.setRPY(0, 0, 0);  // don't change the orientation
  place_location[0].place_pose.pose.orientation = tf2::toMsg(orientation2);
  place_location[0].place_pose.pose.position.x = 0.5;
  place_location[0].place_pose.pose.position.y = 0.4;
  place_location[0].place_pose.pose.position.z = 0.41;

  place_location[0].pre_place_approach.direction.header.frame_id = move_group_interface.getPlanningFrame();
  /* Direction is set as negative z axis */
  place_location[0].pre_place_approach.direction.vector.z = -1.0;
  place_location[0].pre_place_approach.min_distance = 0.05;
  place_location[0].pre_place_approach.desired_distance = 0.12;

  // Setting post-grasp retreat
  // ++++++++++++++++++++++++++
  /* Defined with respect to frame_id */
  place_location[0].post_place_retreat.direction.header.frame_id = move_group_interface.getPlanningFrame();
  /* Direction is set as negative y axis */
  place_location[0].post_place_retreat.direction.vector.z = 1.0;
  place_location[0].post_place_retreat.min_distance = 0.05;
  place_location[0].post_place_retreat.desired_distance = 0.12;

  trajectory_msgs::JointTrajectory& post_posture = place_location[0].post_place_posture;
  post_posture.joint_names.resize(2);
  post_posture.joint_names[0] = "panda_finger_joint1";
  post_posture.joint_names[1] = "panda_finger_joint2";

  /* Set them as open, wide enough for the object to fit. */
  post_posture.points.resize(1);
  post_posture.points[0].positions.resize(2);
  post_posture.points[0].positions[0] = 0.04;
  post_posture.points[0].positions[1] = 0.04;
  post_posture.points[0].time_from_start = ros::Duration(0.5);

  // Set object which pyou place on
  move_group_interface.setSupportSurfaceName("box2");
  // Call place to place the object using the place locations given.
  move_group_interface.place("object3", place_location);

  // Removing Objects
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  // Now, let's remove the objects from the world.
  visual_tools.prompt("Press 'next' Remove the objects from the world");

  ROS_INFO_NAMED("tutorial", "Remove the objects from the world");
  std::vector<std::string> object_ids;
  object_ids.push_back(collision_object.id);
  object_ids.push_back(collision_object2.id);
  object_ids.push_back(wall.id);
  object_ids.push_back(object3.id);
  planning_scene_interface.removeCollisionObjects(object_ids);

  // Show text in RViz of status
  visual_tools.publishText(text_pose, "Objects removed", rvt::WHITE, rvt::XLARGE);
  visual_tools.trigger();

  /* Wait for MoveGroup to receive and process the attached collision object message */
  visual_tools.prompt("Press 'next' once the collision objects disappear");
//------------------------------------



  // END_TUTORIAL

  ros::shutdown();
  return 0;
  }
