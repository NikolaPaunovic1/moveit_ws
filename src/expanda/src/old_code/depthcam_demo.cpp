
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>

#include <moveit_msgs/DisplayRobotState.h>
#include <moveit_msgs/DisplayTrajectory.h>

#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

#include <moveit_visual_tools/moveit_visual_tools.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>

#include <actionlib/client/simple_action_client.h>
#include <franka_gripper/GraspAction.h>
//#include <control_msgs/GripperCommandAction.h>

// The circle constant tau = 2*pi. One tau is one rotation in radians.
const double tau = 2 * M_PI;


void doneCallback(const actionlib::SimpleClientGoalState& state,
                  const franka_gripper::GraspResultConstPtr& result) {
  if (result->success) {
    ROS_INFO("Grasping command completed successfully.");
  } else {
    ROS_WARN("Grasping command failed with error code %s.", result->error.c_str());
  }
}
int main(int argc, char** argv)
{

//SETUP
//^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  // Initialize Node and start looking for callbacks
  ros::init(argc, argv, "pick_2");
  ros::NodeHandle node_handle;

  ros::AsyncSpinner spinner(1);
  spinner.start();

  // Name of the planning Groups
  static const std::string PLANNING_GROUP = "panda_arm";
  static const std::string PLANNING_GRIPPER = "panda_hand";

  //Use MoveGroupInterface
  moveit::planning_interface::MoveGroupInterface move_group_interface(PLANNING_GROUP);
  moveit::planning_interface::MoveGroupInterface gripper_group(PLANNING_GRIPPER);

  // Interact with planning_scene through PlanningSceneInterface
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

  // Get JointModelGroup
  const moveit::core::JointModelGroup* joint_model_group =
      move_group_interface.getCurrentState()->getJointModelGroup(PLANNING_GROUP);

  // Prolong Planning Time because we are working with constraints

  move_group_interface.setPlanningTime(15.0);


  // Visualization
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
 
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

  // print the name of the reference frame for this robot.
  ROS_INFO_NAMED("tutorial", "Planning frame: %s", move_group_interface.getPlanningFrame().c_str());

  // print the name of the end-effector link for this group.
  ROS_INFO_NAMED("tutorial", "End effector link: %s", move_group_interface.getEndEffectorLink().c_str());

  //list of all the groups in the robot:
  ROS_INFO_NAMED("tutorial", "Available Planning Groups:");
  std::copy(move_group_interface.getJointModelGroupNames().begin(),
            move_group_interface.getJointModelGroupNames().end(), std::ostream_iterator<std::string>(std::cout, ", "));

  //-------------------------------------------------------------------------------------------


  //ADD ALL OBJECTS INOT THE WORLD
  //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  visual_tools.prompt("Press Next to spawn the environment!");

  
  // Get the current state so that you can return to it at the end of the demo!

  moveit::core::RobotStatePtr current_state = move_group_interface.getCurrentState();
  std::vector<double> joint_starting_position;
  current_state->copyJointGroupPositions(joint_model_group, joint_starting_position);


  //ADD OBJECT 3 ---------------------------------------------------------------
  moveit_msgs::AttachedCollisionObject object3;
  object3.object.header.frame_id = move_group_interface.getPlanningFrame();
  object3.link_name = "panda_hand";
  object3.touch_links = std::vector<std::string>{ "panda_hand", "panda_leftfinger", "panda_rightfinger" };
  object3.object.id = "object3";

  shape_msgs::SolidPrimitive primitive3;
  primitive3.type = primitive3.BOX;
  primitive3.dimensions.resize(3);
  // primitive3.dimensions[primitive.BOX_X] = 0.15;
  // primitive3.dimensions[primitive.BOX_Y] = 0.02;
  // primitive3.dimensions[primitive.BOX_Z] = 0.02;
//++++++++++++++++++++++++++++++++
  primitive3.dimensions[primitive3.BOX_X] = 0.02;
  primitive3.dimensions[primitive3.BOX_Y] = 0.032;
  primitive3.dimensions[primitive3.BOX_Z] = 0.064;

  geometry_msgs::Pose object3_pose;
  object3_pose.orientation.w = 1.0;
  object3_pose.position.x = 0.5;
  object3_pose.position.y = 0.0;
  //++++++++++++++++++++++++++++
  // object3_pose.position.z = 0.01+0.4;
  object3_pose.position.z = 0.432;

  object3.object.primitives.push_back(primitive3);
  object3.object.primitive_poses.push_back(object3_pose);
  object3.object.operation = object3.object.ADD;


  //ADD ALL OBJECTS VIA A VECTOR INTO THE WORLD---------------------------------
  std::vector<moveit_msgs::CollisionObject> collision_objects;
  collision_objects.push_back(object3.object);

  ROS_INFO_NAMED("tutorial", "Add OBJECTS into the world");
  planning_scene_interface.addCollisionObjects(collision_objects);

  // Show text in RViz of status and wait for MoveGroup to receive and process the collision object message
  visual_tools.publishText(text_pose, "Add object", rvt::WHITE, rvt::XLARGE);
  visual_tools.trigger();
  visual_tools.prompt("Press Next to open the gripper");

  //PICKING PIPELINE
  //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

  //OPEN GRIPPER--------------------
  gripper_group.setStartState(*gripper_group.getCurrentState());

  std::vector<double> gripper_joints = {0.04, 0.04};
  gripper_group.setJointValueTarget(gripper_joints);
  gripper_group.move();

  //PLAN TO OBJECT -------------------------------
  visual_tools.prompt("Press Next to Plan path to object");

  //Set the wanted position
  geometry_msgs::Pose target_pose1;
  geometry_msgs::Pose current_pose = move_group_interface.getCurrentPose().pose;

  // Get the current orientation as a quaternion
  geometry_msgs::Quaternion current_orientation = current_pose.orientation;
  tf2::Quaternion orientation;
  orientation.setRPY(0, -tau / 2, tau *3/ 8);
  target_pose1.orientation = tf2::toMsg(orientation);;
  // target_pose1.position.x = 0.5;
  // target_pose1.position.y = 0.0;
  // target_pose1.position.z = 0.515;
  //+++++++++++++++++++++++++++++++
  target_pose1.position.x = 0.51;
  target_pose1.position.y = 0.0;
  target_pose1.position.z = 0.515+0.022;

  
  // SET THE START AND END POSES -- PLAN TO GRASP LOCATION
  move_group_interface.setStartState(*move_group_interface.getCurrentState());
  move_group_interface.setPoseTarget(target_pose1);

  //PLAN
  moveit::planning_interface::MoveGroupInterface::Plan my_plan;
  bool success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
  ROS_INFO_NAMED("tutorial", "Visualizing plan  %s", success ? "" : "FAILED");

  // VISUALIZE PLAN
  ROS_INFO_NAMED("tutorial", "Visualizing plan 1 as trajectory line");
  visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
  visual_tools.trigger();
  visual_tools.prompt("Press 'next' to move to the desired location");

  //EXECUTE THE PLAN
  move_group_interface.move();
  visual_tools.prompt("Press 'next' to close the gripper");
  visual_tools.deleteAllMarkers();
  visual_tools.trigger();

  //INITIALIZE THE ACTION CLIENT FOR GRIPPING-------------
  actionlib::SimpleActionClient<franka_gripper::GraspAction> client("/franka_gripper/grasp", true);
  ROS_INFO("Waiting for action server to start.");
  client.waitForServer();

  gripper_joints = {0.018, 0.018};
  //+++++++++++++++++++++++++++++++
  // gripper_joints = {0.011, 0.011};
  gripper_group.setJointValueTarget(gripper_joints);
  gripper_group.move();
  ros::Duration(1.0).sleep();

  // Creates a goal to send to the action server.
  franka_gripper::GraspGoal goal;
  // goal.width = 0.018;
  // goal.epsilon.inner = 0.005;
  // goal.epsilon.outer = 0.005;
  // goal.speed = 0.1;
  // goal.force = 20;
  //++++++++++++++++++++++++++++++++++
  goal.width = 0.03;
  goal.epsilon.inner = 0.005;
  goal.epsilon.outer = 0.005;
  goal.speed = 0.1;
  goal.force = 20;

  //-------------------------------------------------------------------------------------------------
  // ---->>GRIPPERCOMMANDACTION EXAMPLE<<-------------
  //
  // actionlib::SimpleActionClient<control_msgs::GripperCommandAction> client("/franka_gripper/gripper_action", true);
  // client.waitForServer();

  // // Creates a goal to send to the action server.
  // control_msgs::GripperCommandGoal goal;
  // goal.command.position = 0.02;
  // goal.command.max_effort = 1000;
  //---------------------------------------------------------------------------------------------------------


  // CLOSE THE GRIPPER AND ATTACH THE OBJECT TO THE PANDA ARM------------------------------
  ROS_INFO("Sending goal.");
  client.sendGoal(goal, &doneCallback);
  planning_scene_interface.applyAttachedCollisionObject(object3);
  visual_tools.prompt("object should be attached");

  // PLAN AROUND THE WALL---------------------------------------------------------------

  //DEFINE THE GOAL POSE
  geometry_msgs::Pose target_pose2;
  target_pose2.orientation = target_pose1.orientation;
  target_pose2.position.x = 0.5;
  target_pose2.position.y = 0.4;
  target_pose2.position.z = 0.515+0.025;
  //++++++++++++++++++++++++++++++++++++++++++++++
  // target_pose2.position.z = 0.515+0.005;

  //PLAN AND MOVE TO THE GOAL POSE
  move_group_interface.setStartState(*move_group_interface.getCurrentState());
  move_group_interface.setPoseTarget(target_pose2);
  success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
  ROS_INFO_NAMED("tutorial", "Visualizing plan  %s", success ? "" : "FAILED");

  // VISUALIZE PLAN
  ROS_INFO_NAMED("tutorial", "Visualizing plan 1 as trajectory line");
  visual_tools.publishTrajectoryLine(my_plan.trajectory_, joint_model_group);
  visual_tools.trigger();
  visual_tools.prompt("Press 'next' to move to the desired location");

  //EXECUTE THE PLAN
  // move_group_interface.move();
  move_group_interface.execute(my_plan);
  visual_tools.prompt("Press 'next' to go back to the starting position");
  //stop grasp
  client.cancelGoal();
  visual_tools.deleteAllMarkers();
  visual_tools.trigger();

  //OPEN GRIPPER---------------------------
  gripper_joints = {0.04, 0.04};
  gripper_group.setJointValueTarget(gripper_joints);
  gripper_group.move();

  //DETACH OBJECT-------
  move_group_interface.detachObject(object3.object.id);


  move_group_interface.setStartState(*move_group_interface.getCurrentState());
  move_group_interface.setJointValueTarget(joint_starting_position);

  success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

  ROS_INFO_NAMED("tutorial", "Visualizing plan  %s", success ? "" : "FAILED");
  ROS_INFO_NAMED("tutorial", "Visualizing plan 1 as trajectory line");

  visual_tools.prompt("Press 'next' to execute the motion");
  move_group_interface.execute(my_plan);

  
  // Removing Objects
  // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
  visual_tools.prompt("Press 'next' Remove the objects from the world");
  ROS_INFO_NAMED("tutorial", "Remove the objects from the world");
  
  std::vector<std::string> object_ids;
  object_ids.push_back(object3.object.id);
  planning_scene_interface.removeCollisionObjects(object_ids);

  // Show text in RViz of status
  visual_tools.publishText(text_pose, "Objects removed", rvt::WHITE, rvt::XLARGE);
  visual_tools.trigger();

  // Wait for MoveGroup to receive and process the attached collision object message 
  visual_tools.prompt("Press 'next' once the collision objects disappear");

  // SHUTDOWN
  ros::shutdown();
  return 0;
  }
