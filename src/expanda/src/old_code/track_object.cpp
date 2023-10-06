#include "geometric_shapes/shapes.h"
#include "geometric_shapes/mesh_operations.h"
#include "geometric_shapes/shape_operations.h"

#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit/move_group_interface/move_group_interface.h>


#include <tf/transform_listener.h>

int main(int argc, char** argv){

ros::init(argc, argv, "bins_tracker");
ros::NodeHandle node; 
ros::AsyncSpinner spinner(1);
spinner.start();

// Name of the planning Group
static const std::string PLANNING_GROUP = "panda_arm";

//Use MoveGroupInterface
moveit::planning_interface::MoveGroupInterface move_group_interface(PLANNING_GROUP);

tf::TransformListener listener; //tf listener & transformations
tf::StampedTransform t_bin1;

std::vector<moveit_msgs::CollisionObject> collision_objects; //vector of objects
std::vector<std::string> object_ids; //vector of strings (names of objects)
object_ids.push_back("Bin1");
moveit::planning_interface::PlanningSceneInterface planning_scene_interface; //planning interface
ros::Duration(2.0).sleep();

moveit_msgs::CollisionObject bin; //Create an object msg

bin.header.frame_id = move_group_interface.getPlanningFrame();

// bin.header.frame_id = "zed2i_left_camera_optical_frame"; //"father frame" 
shape_msgs::SolidPrimitive primitive;
primitive.type = primitive.BOX;
primitive.dimensions.resize(3);
primitive.dimensions[0] = 0.1;
primitive.dimensions[1] = 0.05;
primitive.dimensions[2] = 0.03;  

geometry_msgs::Pose box_pose;
box_pose.orientation.w = 1.0;
box_pose.orientation.x= 0;
box_pose.orientation.y= 0;
box_pose.orientation.z= 0;
box_pose.position.x = 0.0;
box_pose.position.y = 0.0;
box_pose.position.z = 1.1;

bin.primitives.push_back(primitive);
bin.primitive_poses.push_back(box_pose);

bin.operation = bin.ADD; //add object to collitions 

bin.id =object_ids[0]; //rename object 
collision_objects.push_back(bin); //you can insert different objects using a vector of collition objects
ros::Duration(2.0).sleep();

planning_scene_interface.addCollisionObjects(collision_objects); //add objects to planning interface
ros::Duration(2.0).sleep();


// bin.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
bin.operation = bin.ADD; //change operation to MOVE

ros::Duration timeout(5.0); // Timeout after 5 seconds
if (listener.waitForTransform("world", "aruco_marker_frame", ros::Time(0), timeout)) {
    ROS_INFO("Transform between world and aruco_marker_frame is available.");
} else {
    ROS_WARN("Timeout waiting for transform between world and aruco_marker_frame.");
    return 1; // Exit if the transform is not available within the timeout duration
}

double desired_frequency = 10.0; // 10 Hz
ros::Rate loop_rate(desired_frequency);

while (node.ok()){
    //Listen to tfs
    try{
// Wait for the "world" frame to become available

        listener.lookupTransform("world", "aruco_marker_frame", ros::Time(0), t_bin1);
        ROS_INFO("here is the pose %f", t_bin1.getOrigin().x());
    }

        catch (tf::TransformException ex){
        ROS_WARN("%s",ex.what());
    }

    collision_objects.clear(); //clear previous data in the vector

    bin.id = object_ids[0]; //bin 1 
    bin.primitive_poses[0].position.x = t_bin1.getOrigin().x(); //set pose
    bin.primitive_poses[0].position.y = t_bin1.getOrigin().y();
    bin.primitive_poses[0].position.z = t_bin1.getOrigin().z();
    bin.primitive_poses[0].orientation.w= t_bin1.getRotation().w();
    bin.primitive_poses[0].orientation.x= t_bin1.getRotation().x();
    bin.primitive_poses[0].orientation.y= t_bin1.getRotation().y();
    bin.primitive_poses[0].orientation.z= t_bin1.getRotation().z();

    collision_objects.push_back(bin); // add to vector
    // ros::Duration(0.5).sleep(); //ZzZzZ
    planning_scene_interface.applyCollisionObjects(collision_objects); //apply changes to planning interface
    // ros::Duration(0.1).sleep(); //ZzZzZ
    loop_rate.sleep(); 
}
planning_scene_interface.removeCollisionObjects(object_ids); //delete objects from planning interface*/

ros::shutdown(); //turn off
return 0;
}