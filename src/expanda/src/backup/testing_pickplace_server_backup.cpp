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

  // //initialize environment when working with real world
  // moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

  // // Define Object to be spawned
  // moveit_msgs::CollisionObject collision_object;
  // collision_object.header.frame_id = "world";
  // collision_object.id = "table";

  // //set shape of the object
  // shape_msgs::SolidPrimitive primitive;
  // primitive.type = primitive.BOX;
  // primitive.dimensions.resize(3);
  // primitive.dimensions[primitive.BOX_X] = 0.9;
  // primitive.dimensions[primitive.BOX_Y] = 1.6;
  // primitive.dimensions[primitive.BOX_Z] = 0.02;

  // //define pose of the object
  // geometry_msgs::Pose box_pose;
  // box_pose.orientation.w = 1.0;
  // box_pose.position.x = 0.27;
  // box_pose.position.y = 0.0;
  // box_pose.position.z = -0.02;

  // //add the definitions to the collisionobject
  // collision_object.primitives.push_back(primitive);
  // collision_object.primitive_poses.push_back(box_pose);
  // collision_object.operation = collision_object.ADD;

  // //define cones for camera objects
  // moveit_msgs::CollisionObject cone;
  // cone.header.frame_id = "world";
  // cone.id = "cone";
  // shapes::Mesh* m = shapes::createMeshFromResource("package://expanda/meshes/cone_500_110.stl"); //find mesh
  // double scale_factor = 0.001; // convert millimeters to meters

  // for (unsigned int i = 0; i < m->vertex_count; ++i)
  // {
  //   m->vertices[i * 3] *= scale_factor;
  //   m->vertices[i * 3 + 1] *= scale_factor;
  //   m->vertices[i * 3 + 2] *= scale_factor;
  // }
  // shape_msgs::Mesh mesh; //create a mesh msg
  // shapes::ShapeMsg mesh_msg; //create a shape msg
  // shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
  // ros::Duration(0.5).sleep();
  // mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg

  
  // // Set the object's pose (specified relative to frame_id)
  // geometry_msgs::Pose mesh_pose;
  // mesh_pose.orientation.w = 1.0;
  // mesh_pose.position.x = 0.045;
  // mesh_pose.position.y = -0.367;
  // mesh_pose.position.z = 0.0;

  // // Add the mesh to the CollisionObject
  // cone.meshes.push_back(mesh);
  // cone.mesh_poses.push_back(mesh_pose);
  // cone.operation = collision_object.ADD;

  // //define second cone
  // //define cones for camera objects
  // moveit_msgs::CollisionObject cone_2;
  // cone_2.header.frame_id = "world";
  // cone_2.id = "cone_2";

  // //ONLY IF YOU WANT ANOTHER MESH FOR CONE_2---------------
  // // m = shapes::createMeshFromResource("package://expanda/meshes/cone_530_210.stl"); //find mesh

  // // //scale your mesh
  // // for (unsigned int i = 0; i < m->vertex_count; ++i)
  // // {
  // //   m->vertices[i * 3] *= scale_factor;
  // //   m->vertices[i * 3 + 1] *= scale_factor;
  // //   m->vertices[i * 3 + 2] *= scale_factor;
  // // }

  // // shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
  // // ros::Duration(0.5).sleep();
  // // mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg
  // //-------------------------------------------------------------------
  
  // // Set the object's pose (specified relative to frame_id)
  // geometry_msgs::Pose mesh_pose_2;
  // mesh_pose_2.orientation.w = 1.0;
  // mesh_pose_2.position.x = -0.284;
  // mesh_pose_2.position.y = 0.437;
  // mesh_pose_2.position.z = 0.0;

  // // Add the mesh to the CollisionObject
  // cone_2.meshes.push_back(mesh);
  // cone_2.mesh_poses.push_back(mesh_pose_2);
  // cone_2.operation = collision_object.ADD;

  // //add all the objects into one vector
  // std::vector<moveit_msgs::CollisionObject> collision_objects;
  // collision_objects.push_back(collision_object);
  // collision_objects.push_back(cone);
  // collision_objects.push_back(cone_2);
  // ros::Duration(1.0).sleep();

  // //add the collision object into the world
  // ROS_INFO("Add table and camera holders!");
  // planning_scene_interface.addCollisionObjects(collision_objects);
  // ros::Duration(1.0).sleep();
  // ros::spinOnce();

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