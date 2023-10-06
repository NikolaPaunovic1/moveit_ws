#include <ros/ros.h>
#include <my_services/PickPlace2Action.h> 

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
#include <my_services/PoseFinderService.h> 


int main (int argc, char **argv)
{
    ros::init(argc, argv, "test_pickplace_server");
    ros::NodeHandle nh;
    
    // create the action client and the service_client
    // true causes the client to spin its own thread
    actionlib::SimpleActionClient<my_services::PickPlace2Action> ac("PickPlace_Action", true);
    ros::ServiceClient service_client = nh.serviceClient<my_services::PoseFinderService>("pose_finder_service");;
    
    ROS_INFO("Waiting for action server to start.");
    // wait for the action server to start
    ac.waitForServer(); //will wait for infinite time

    geometry_msgs::Pose new_pose;

    //Use Pose Finder Service to find new pose
    service_client.waitForExistence();

    //check if enough input arguments were provided
    if (argc < 3) {
    ROS_ERROR("You must provide an id and a location.");
    return 1;}

    my_services::PoseFinderService srv;

    srv.request.id = atoll(argv[1]);
    srv.request.location = argv[2];

    if (service_client.call(srv))
    {
    // Process the service response
    ROS_INFO("service call was successfull. The placepose is: %f, %f, %f", new_pose.position.x, new_pose.position.y, new_pose.position.z);
    new_pose = srv.response.place_pose;
    }
    else
    {
    ROS_ERROR("Failed to call service object_position_service");
    return 0;
    }
 
    ROS_INFO("Action server started, sending goal.");

    // send a goal to the action
    my_services::PickPlace2Goal goal;
    goal.id = atoll(argv[1]);
    goal.location = argv[2];
    goal.pose = new_pose;
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