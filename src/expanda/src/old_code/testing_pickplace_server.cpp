#include <ros/ros.h>
#include <my_services/PickPlaceAction.h> 

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
#include <geometric_shapes/shapes.h>
#include <geometric_shapes/mesh_operations.h>
#include "geometric_shapes/shape_operations.h"

int main (int argc, char **argv)
{
  ros::init(argc, argv, "test_pickplace_server");
 
  // create the action client
  // true causes the client to spin its own thread
  actionlib::SimpleActionClient<my_services::PickPlaceAction> ac("PickPlace_Action", true);
 
  ROS_INFO("Waiting for action server to start.");
  // wait for the action server to start
  ac.waitForServer(); //will wait for infinite time
 
  ROS_INFO("Action server started, sending goal.");

  // send a goal to the action
  my_services::PickPlaceGoal goal;
  goal.id = atoll(argv[1]);
  goal.pose.position.x = atof(argv[2]);
  goal.pose.position.y = atof(argv[3]);
  goal.pose.position.z = atof(argv[4]);
  goal.pose.orientation.x = atof(argv[5]);
  goal.pose.orientation.y = atof(argv[6]);
  goal.pose.orientation.z = atof(argv[7]);
  goal.pose.orientation.w = atof(argv[8]);
  ac.sendGoal(goal);
 
  //wait for the action to return
  bool finished_before_timeout = ac.waitForResult(ros::Duration(180.0));
 
  if (finished_before_timeout)
  {
    actionlib::SimpleClientGoalState state = ac.getState();
    ROS_INFO("Action finished: %s",state.toString().c_str());
  }
  else
    ROS_INFO("Action did not finish before the time out.");
 
  //exit
  return 0;
}