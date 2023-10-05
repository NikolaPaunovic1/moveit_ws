#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <std_msgs/Int8.h>
#include <std_msgs/String.h>

//define the essential parameters for a triplet to be detected
struct Triplet
{
    int activity_label; //which activity label corresponds to the triplet activity - i.e. cutting-motion corresponds to 1
    int tool_id; //which aruco_marker_id corresponds to the tool being used for the triplet
    int target_id; //which aruco_marker_id corresponds to the action target for the triplet
    float tool_distance; //how close does the hand need to be to the tool to count as "tool with id = "tool_id" is being used"
    float target_distance; //how close does the target need to be to the hand to count as "action being applied on target"
    std::string triplet_name; //name of the triplet

    //constructor for easy initialization
    Triplet(int al, int tid, int tid2, float td, float td2, std::string tn) : 
    activity_label(al), tool_id(tid), target_id(tid2), tool_distance(td), target_distance(td2), triplet_name(tn) {}
};

//define 
int activity;
geometry_msgs::Point hand_position;

//callback function for the hand_position_sub
void hand_cb(const geometry_msgs::Point::ConstPtr &msg)
{
    hand_position.x = msg->x;
    hand_position.y = msg->y;
    hand_position.z = msg->z;
}

//callback function for activity_label
void activity_cb(const std_msgs::Int8::ConstPtr& activity_msg)
{
    activity = activity_msg->data;
}

int main(int argc, char** argv)
{   
    //initilize node and create nodehandle
    ros::init(argc, argv, "triplet_detection");
    ros::NodeHandle nh;

    //define a subscriber to the handpose
    // ros::Subscriber hand_position_sub = nh.subscribe<geometry_msgs::Point>("/cartesian_impedance_controller/right_hand", 1, boost::bind(hand_cb, _1, hand_position));
    ros::Subscriber hand_position_sub = nh.subscribe<geometry_msgs::Point>("/cartesian_impedance_controller/right_hand", 1, hand_cb);

    //define a subscriber for the activity
    // ros::Subscriber activity_sub = nh.subscribe<std_msgs::Int8>("/activity_label", 1, boost::bind(activity_cb, _1, activity));
    ros::Subscriber activity_sub = nh.subscribe<std_msgs::Int8>("/activity_label", 1, activity_cb);

    //define a publisher to publish the detected triplet
    ros::Publisher triplet_pub = nh.advertise<std_msgs::String>("triplet", 1);

    //create planning_scene object to get information out of the planning_scene
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

    //------DEFINE YOUR TRIPLETS HERE---------------
    //define your triplets and store them in a vector to be able to iterate through them efficiently
    Triplet cutting(1, 2, 1, 0.3, 0.4, "cutting");
    Triplet whisking(2, 4, 3, 0.3, 0.4, "whisking");

    std::vector<Triplet> triplets;
    triplets.push_back(cutting);
    triplets.push_back(whisking);
    //---------------------------------------------

    //define a vector with all relevant object_ids and a map to store object_id and their respective poses
    std::vector<std::string> object_ids;
    for (int j = 0; j < 8; ++j) {object_ids.push_back("Bin" + std::to_string(j+1));}
    std::map<std::string, geometry_msgs::Pose> object_poses;

    //define helper variables
    std_msgs::String triplet_msg;
    int count_published_triplets = 0;
    ros::Rate loop_rate(2);

    //send a message to inform the user the ros node has started
    ROS_INFO("Triplet detection node has been initialized.");

    //start a loop which checks if activity labels, target inside planning scene are matching with one of the defined triplets
    while(ros::ok())
    {
        object_poses = planning_scene_interface.getObjectPoses(object_ids);
        // ros::spinOnce();
        // iterate through each triplet and check if triplet conditions are met - ONLY IF ACTIVITY IS != NONE
        // ROS_INFO("Hand_Pose: x=%f, y=%f, z=%f",hand_position.x, hand_position.y, hand_position.z);
        // ROS_INFO("Knife_pose: x=%f, y=%f, z=%f",object_poses[{"Bin" + std::to_string(triplets[0].tool_id)}].position.x,
        //  object_poses[{"Bin" + std::to_string(triplets[0].tool_id)}].position.y, object_poses[{"Bin" + std::to_string(triplets[0].tool_id)}].position.z);

        if(activity != 0)
        {
            //iterate through triplets
            for(int i = 0; i < triplets.size(); i++)
            {
                //check if activity label corresponds to triplet label
                if(triplets[i].activity_label == activity)
                {
                    //check if tool and target are inside planning_scene
                    if((object_poses.find("Bin" + std::to_string(triplets[i].tool_id)) != object_poses.end()) && (object_poses.find("Bin" + std::to_string(triplets[i].target_id)) != object_poses.end()))
                    {
                        float dx_tool = (hand_position.x - object_poses[{"Bin" + std::to_string(triplets[i].tool_id)}].position.x);
                        float dy_tool = (hand_position.y - object_poses[{"Bin" + std::to_string(triplets[i].tool_id)}].position.y);
                        float dz_tool = (hand_position.z - object_poses[{"Bin" + std::to_string(triplets[i].tool_id)}].position.z);
                        float dtot_tool = (dx_tool * dx_tool) + (dy_tool * dy_tool) + (dz_tool * dz_tool);
                        dtot_tool = sqrt(dtot_tool);

                        float dx_target = (hand_position.x - object_poses[{"Bin" + std::to_string(triplets[i].target_id)}].position.x);
                        float dy_target = (hand_position.y - object_poses[{"Bin" + std::to_string(triplets[i].target_id)}].position.y);
                        float dz_target = (hand_position.z - object_poses[{"Bin" + std::to_string(triplets[i].target_id)}].position.z);
                        float dtot_target = (dx_target * dx_target) + (dy_target * dy_target) + (dz_target * dz_target);
                        dtot_target = sqrt(dtot_target);

                        ROS_INFO("Tool distance :<<%f>> and Target distance: <<%f>>", dtot_tool, dtot_target);
                        //check if the distances are small enough
                        if((dtot_tool <= triplets[i].tool_distance) && (dtot_target <= triplets[i].target_distance))
                        {
                            triplet_msg.data = triplets[i].triplet_name;
                            triplet_pub.publish(triplet_msg);
                            count_published_triplets += 1;
                        }
                    }
                }
            }

            //send a warning if multiple triplets have been detected at the same time
            if(count_published_triplets > 1)
            {
                ROS_WARN("Caution! Multiple Triplets have been detected at the same time! Adjust your triplet parameters!");
            }

            count_published_triplets = 0;

        }
        ros::spinOnce();
        loop_rate.sleep();
    }

}