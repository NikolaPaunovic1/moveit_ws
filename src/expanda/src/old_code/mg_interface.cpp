
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>


// The circle constant tau = 2*pi. One tau is one rotation in radians.
const double tau = 2 * M_PI;

int main(int argc, char** argv)
{

  // Initialize Node and start looking for callbacks
  ros::init(argc, argv, "mg_interface");
  ros::NodeHandle node_handle;
//
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

  move_group_interface.setPlanningTime(15.0);

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
  planning_scene_interface.addCollisionObjects(collision_objects);

  // Show text in RViz of status and wait for MoveGroup to receive and process the collision object message
  visual_tools.publishText(text_pose, "Add object", rvt::WHITE, rvt::XLARGE);
  visual_tools.trigger();
  visual_tools.prompt("End-effector should be in the same Orientation above the other box. Press 'next' to plan a path.");

  // Plan to the other box with the same orientation

  //Set the wanted position
  geometry_msgs::Pose target_pose1;

  geometry_msgs::Pose current_pose = move_group_interface.getCurrentPose().pose;

  // Get the current orientation as a quaternion
  geometry_msgs::Quaternion current_orientation = current_pose.orientation;


  // target_pose1.orientation.w = 0.0;
  // target_pose1.orientation.x = 0.92388;
  // target_pose1.orientation.y = sqrt(1 - (target_pose1.orientation.x*target_pose1.orientation.x));
  // target_pose1.orientation.z = 0.0;
  target_pose1.orientation = current_orientation;
  target_pose1.position.x = 0.5;
  target_pose1.position.y = 0.4;
  target_pose1.position.z = 0.6;

  // Set the current state as start state
  move_group_interface.setStartState(*move_group_interface.getCurrentState());

/*
//------- TRY WITH PATH CONSTRAINTS
  moveit_msgs::Constraints my_constraint;

  //TRY WITH GOAL CONSTRAINTS ONLY -- MOTION PLANNING PIPELINE

  // Set the orientation constraints tolerance
  moveit_msgs::OrientationConstraint oc;
  oc.header.frame_id = move_group_interface.getPlanningFrame();
  oc.link_name = move_group_interface.getEndeffectorLink();
  oc.orientation.w = 0.0;
  oc.orientation.x = 0.92388;
  oc.orientation.y = -0.3826;
  oc.orientation.z = 0.0;
  oc.absolute_x_axis_tolerance =  tau/8; // Tolerance for orientation in x-axis
  oc.absolute_y_axis_tolerance =  tau/8; // Tolerance for orientation in y-axis
  oc.absolute_z_axis_tolerance =  tau; // Tolerance for orientation in z-axis
  oc.weight = 1.0;
  my_constraint.orientation_constraints.push_back(oc);

  move_group_interface.setPathConstraints(my_constraint);

// -----------------
*/
  // Set tolerances because may not be achievable
  // std::vector<double> orientation_tolerance = {tau/8, tau/8, tau};
  double zero_tolerance = move_group_interface.getGoalOrientationTolerance();
  move_group_interface.setGoalOrientationTolerance(tau/16);
  //move_group_interface.setPositionTarget(target_pose1.position.x,target_pose1.position.y,target_pose1.position.z);
  move_group_interface.setPoseTarget(target_pose1);

  // Now, we call the planner to compute the plan and visualize it.
  // Note that we are just planning, not asking move_group_interface
  // to actually move the robot.
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;

  bool success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

  ROS_INFO_NAMED("tutorial", "Visualizing plan  %s", success ? "" : "FAILED");

  // Visualizing plans
  // ^^^^^^^^^^^^^^^^^
  // We can also visualize the plan as a line with markers in RViz.
  ROS_INFO_NAMED("tutorial", "Visualizing plan 1 as trajectory line");
  //visual_tools.publishAxisLabeled(target_pose1, "pose1");
  visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
  visual_tools.trigger();
 // move_group_interface.clearPathConstraints();
  visual_tools.prompt("Press 'next' to spawn an obstacle");
  
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
  visual_tools.prompt("Press ect to replan");

  //replan

  success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

  ROS_INFO_NAMED("tutorial", "Visualizing plan  %s", success ? "" : "FAILED");

  visual_tools.deleteAllMarkers();
  visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);  
  visual_tools.trigger();
  visual_tools.prompt("Press next to execute the plan");


  //execution
  move_group_interface.move();

  // Alternatively use:
  //move_group_innterface.execute(my_plan);

  //Plan back to the Initial State:
  visual_tools.prompt("Press 'next' to plan back to the initial state");
  visual_tools.deleteAllMarkers();
  visual_tools.trigger();

  // remove tolerances
  move_group_interface.setGoalOrientationTolerance(zero_tolerance);

  // Plan from new start state
  move_group_interface.setStartState(*move_group_interface.getCurrentState());

  //plan to old starting position
  move_group_interface.setJointValueTarget(joint_starting_position);

  success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

  ROS_INFO_NAMED("tutorial", "Visualizing plan  %s", success ? "" : "FAILED");
  ROS_INFO_NAMED("tutorial", "Visualizing plan 1 as trajectory line");

  visual_tools.prompt("Press 'next' to execute the motion");

  //execute
  move_group_interface.execute(my_plan);


  //
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
