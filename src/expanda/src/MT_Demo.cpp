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
#include <std_msgs/String.h>
#include <std_msgs/Bool.h>


struct triplet_action{
    int id;
    std::string info;

    // Constructor
    triplet_action(int _id, std::string _info)
        : id(_id), info(_info) {}
};

//callback function for triplet
std::string triplet;

void triplet_cb(const std_msgs::String::ConstPtr& msg){
    triplet = msg -> data;
}

//callback function for exit flag 
bool exit_flag = false;

void exitCallback(const std_msgs::Bool::ConstPtr& msg) {
    exit_flag = msg->data;
}

int main (int argc, char **argv)
{

    //Define Workflows here:------------------------------------------
    std::vector<triplet_action> porridge;

    //which triplets make up your workflow?
    //for robot actions specifiy (ID, LOCATION)
    //for human action specifiy (ID=0, TRIPLET NAME)
    porridge.push_back(triplet_action(1, "work_area"));
    porridge.push_back(triplet_action(2, "work_area"));
    porridge.push_back(triplet_action(0, "cutting"));
    porridge.push_back(triplet_action(4, "work_area"));
    porridge.push_back(triplet_action(5, "work_area"));
    porridge.push_back(triplet_action(0, "whisking"));
    porridge.push_back(triplet_action(6, "work_area"));
    porridge.push_back(triplet_action(1, "origin"));
    porridge.push_back(triplet_action(2, "origin"));

    //shorter porridge demo
    std::vector<triplet_action> porridge_short;

    //which triplets make up your workflow?
    //for robot actions specifiy (ID, LOCATION)
    //for human action specifiy (ID=0, TRIPLET NAME)
    porridge_short.push_back(triplet_action(2, "work_area"));
    porridge_short.push_back(triplet_action(0, "cutting"));
    porridge_short.push_back(triplet_action(4, "work_area"));
    porridge_short.push_back(triplet_action(0, "whisking"));
    porridge_short.push_back(triplet_action(6, "work_area"));
    porridge_short.push_back(triplet_action(2, "origin"));

    //shorter demo but starting in middle
    std::vector<triplet_action> porridge_short2;

    //which triplets make up your workflow?
    //for robot actions specifiy (ID, LOCATION)
    //for human action specifiy (ID=0, TRIPLET NAME)
    porridge_short2.push_back(triplet_action(0, "whisking"));
    porridge_short2.push_back(triplet_action(6, "work_area"));
    porridge_short2.push_back(triplet_action(2, "origin"));

    //define a vector containing all workflows
    std::vector<std::vector<triplet_action>> workflows;

    //store your workflows here:
    workflows.push_back(porridge);
    workflows.push_back(porridge_short);
    workflows.push_back(porridge_short2);

    //------------------------------------------------------------------


    //Initialize Node
    ros::init(argc, argv, "MT_Demo");
    ros::NodeHandle nh;
    ros::Subscriber triplet_sub = nh.subscribe<std_msgs::String>("triplet", 1, triplet_cb);
    ros::Subscriber exit_sub = nh.subscribe<std_msgs::Bool>("exit_topic", 1, exitCallback);

    
    // create the action client and the service_client
    actionlib::SimpleActionClient<my_services::PickPlace2Action> ac("PickPlace_Action", true);
    ros::ServiceClient service_client = nh.serviceClient<my_services::PoseFinderService>("pose_finder_service");;
    
    ROS_INFO("Waiting for action server to start.");
    // wait for the action server to start
    ac.waitForServer(); 

    //helper variables
    geometry_msgs::Pose new_pose;
    int pos;

    //Wait for the Pose_finder_Service to start --> Will be used to determine poses for action server
    service_client.waitForExistence();

    //check if enough input arguments were provided
    if (argc < 2) {
    ROS_ERROR("You must input a dish!");
    return 1;}

    //Check which dish was chosen --> every dish has 
    std::string dish_name = argv[1];
    if(dish_name == "porridge" || dish_name == "Porridge") {pos = 0;}
    else if(dish_name == "porridge2" || dish_name == "Porridge2") {pos = 1;}
    else if(dish_name == "porridge3" || dish_name == "Porridge3") {pos = 2;}
    else{
        ROS_INFO("No dish named: %s", argv[1]);
        return 1;
    }

    //go through each step of the workflow and trigger the corresponding actions 
    // OR listen for corresponding triplets
    //Shutdown node if Ctrl+C is pressed
    //Exit the loop if /exit_flag topic is set to "True" - Can be done via rostopic publish in case
    //of actions not getting recognised 
    //!! in Terminal type: rostopic pub /exit_loop std_msgs/Bool "data: true"

    ROS_INFO("Starting with dish");
    for(int i=0; i<workflows[pos].size()&& ros::ok() && !exit_flag;i++){

        //id ==0 --> listen for triplet
        if(workflows[pos][i].id==0){

            int counter = 0;

            ros::Rate loop_rate(1);

            //if the same triplet has been detected 2 times in a row, we are certain, that the human
            //is currently executing the corresponding action triplet!
            while (counter <2 && ros::ok())
            {
                if(workflows[pos][i].info == triplet){counter += 1;}
                else{counter =0;}
                loop_rate.sleep();
                ros::spinOnce();
            }
            
        }

        //id != 0 --> trigger Robot action
        else{
            my_services::PoseFinderService srv;

            //workflows[pos] = workflow containing all triplets necessary to get to a finished dish
            //i.e. workflow[0] = porridge - porridge[0] = triplet_action(1,"work_area")
            srv.request.id = workflows[pos][i].id;
            srv.request.location = workflows[pos][i].info;

            if (service_client.call(srv))
            {
            // Process the service response
            new_pose = srv.response.place_pose;
            ROS_INFO("service call was successfull. The placeposition is: %f, %f, %f", new_pose.position.x, new_pose.position.y, new_pose.position.z);
            }
            else
            {
            ROS_ERROR("Failed to call service object_position_service.. Maybe no free space is available?");
            continue;
            }
        
            ROS_INFO("Action server started, sending goal.");

            // send a goal to the action
            my_services::PickPlace2Goal goal;
            goal.id = workflows[pos][i].id;
            goal.location = workflows[pos][i].info;
            goal.pose = new_pose;
            ac.sendGoal(goal);
            
            // //wait for the action to return
            // bool finished_before_timeout = ac.waitForResult(ros::Duration(180.0));
            
            // //if the action server has been finished, check if the action was successfully executed or not!
            // //in case of succeed --> go to next step of the workflow
            // //in case of not succeeded --> retrigger!
            // if (finished_before_timeout)
            // {
            // actionlib::SimpleClientGoalState state = ac.getState();
            // ROS_INFO("Action finished: %s",state.toString().c_str());
            // }
            // else{
            //     ROS_INFO("Action did not finish before the time out.");
            // }

            // Duration to wait for each check
            ros::Duration check_interval(1.0); // 1 second, for instance

            while (ros::ok())
            {
                bool finished = ac.waitForResult(check_interval);

                if (finished)
                {
                    // Check if action has been completed and break out of the loop if true
                    actionlib::SimpleClientGoalState state = ac.getState();
                    ROS_INFO("Action finished: %s", state.toString().c_str());
                    break;
                }
            }

            if (!ros::ok())
            {
                ROS_WARN("Node shutdown detected. Cancelling the goal.");
                ac.cancelGoal();
            }
        }
    }

    //exit
    return 0;
}