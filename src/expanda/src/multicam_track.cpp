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
tf::StampedTransform t1_bin1;
tf::StampedTransform t2_bin1;
tf::StampedTransform tf_bin1;
tf::StampedTransform t1_bin1_old;
tf::StampedTransform t2_bin1_old;

//helper variables
bool time1_check = false;
bool time2_check = false;
bool rot1_check = true;
bool rot2_check = true;
int counter;

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

//Initialize my transforms-----------
// tf::Quaternion quat(box_pose.orientation.x, box_pose.orientation.y, box_pose.orientation.z, box_pose.orientation.w);
// tf::Vector3 trans(box_pose.position.x, box_pose.position.y, box_pose.position.z);
// tf::Transform pose_transform(quat, trans);

// std::string parent_frame_id = "world";  // Replace with the appropriate frame ID
// std::string child_frame_id = "aruco_marker_frame_long";    // Replace with the appropriate frame ID
// ros::Time timestamp = ros::Time::now();             // Or provide a specific timestamp if needed

// t1_bin1.frame_id_ = parent_frame_id;
// t1_bin1.child_frame_id_ = child_frame_id;
// t1_bin1.stamp_ = timestamp;

// t1_bin1.setOrigin(pose_transform.getOrigin());
// t1_bin1.setRotation(pose_transform.getRotation());
// t2_bin1.setOrigin(pose_transform.getOrigin());
// t2_bin1.setRotation(pose_transform.getRotation());


//---------------------

bin.primitives.push_back(primitive);
bin.primitive_poses.push_back(box_pose);

bin.operation = bin.ADD; //add object to collitions 

bin.id =object_ids[0]; //rename object 
collision_objects.push_back(bin); //you can insert different objects using a vector of collition objects
ros::Duration(2.0).sleep();

planning_scene_interface.addCollisionObjects(collision_objects); //add objects to planning interface
ros::Duration(2.0).sleep();


// bin.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
// bin.operation = bin.MOVE;

bin.operation = bin.ADD; //change operation to MOVE


//check if both the frames get recognized-----------------------
//Substitute this part later with two published messages for each of the transforms
//--> publish tf message for each of the frames
// ros::Duration timeout(10.0); // Timeout after 5 seconds
// if (listener.waitForTransform("world", "aruco_marker_frame_long", ros::Time(0), timeout)) {
//     ROS_INFO("Transform between world and aruco_marker_frame is available.");
//     listener.lookupTransform("world", "aruco_marker_frame_short", ros::Time(0), t1_bin1);

// } else {
//     ROS_WARN("Timeout waiting for transform between world and aruco_marker_frame.");
//     return 1; // Exit if the transform is not available within the timeout duration
// }
// if (listener.waitForTransform("world", "aruco_marker_frame_short", ros::Time(0), timeout)) {
//     ROS_INFO("Transform between world and aruco_marker_frame is available.");
//     listener.lookupTransform("world", "aruco_marker_frame_long", ros::Time(0), t2_bin1);

// } else {
//     ROS_WARN("Timeout waiting for transform between world and aruco_marker_frame.");
//     return 1; // Exit if the transform is not available within the timeout duration
// }
//---------------------------------



double desired_frequency = 10.0; // 10 Hz
ros::Rate loop_rate(desired_frequency);

while (node.ok()){
    //Listen to tfs
    t1_bin1_old = t1_bin1;
    t2_bin1_old = t2_bin1;
    try{
// Wait for the "world" frame to become available

        listener.lookupTransform("world", "aruco_marker_frame_long", ros::Time(0), t1_bin1);
        listener.lookupTransform("world", "aruco_marker_frame_short", ros::Time(0), t2_bin1);

        // ROS_INFO("here is the pose %f", t1_bin1.getOrigin().x());
    }

        catch (tf::TransformException ex){
        ROS_WARN("%s",ex.what());
    }

    collision_objects.clear(); //clear previous data in the vector

//store Transformation params cam 1
    float t1_px = t1_bin1.getOrigin().x(); //set pose
    float t1_py = t1_bin1.getOrigin().y();
    float t1_pz = t1_bin1.getOrigin().z();
    float t1_ow= t1_bin1.getRotation().w();
    float t1_ox= t1_bin1.getRotation().x();
    float t1_oy= t1_bin1.getRotation().y();
    float t1_oz= t1_bin1.getRotation().z();

//store Transformation params cam 2
    float t2_px = t2_bin1.getOrigin().x(); //set pose
    float t2_py = t2_bin1.getOrigin().y();
    float t2_pz = t2_bin1.getOrigin().z();
    float t2_ow= t2_bin1.getRotation().w();
    float t2_ox= t2_bin1.getRotation().x();
    float t2_oy= t2_bin1.getRotation().y();
    float t2_oz= t2_bin1.getRotation().z();

//compute distance
    float dist_diff = (t1_px*t1_px)+(t1_py*t1_py)+(t1_pz*t1_pz)-(t2_px*t2_px)-(t2_py*t2_py)-(t2_pz*t2_pz);

//check if marker was detected
    float dx1 = (t1_px - t1_bin1_old.getOrigin().x());
    float dy1 = (t1_py - t1_bin1_old.getOrigin().y());
    float dz1 = (t1_pz - t1_bin1_old.getOrigin().z());
    float dx2 = (t2_px - t2_bin1_old.getOrigin().x());
    float dy2 = (t2_py - t2_bin1_old.getOrigin().y());
    float dz2 = (t2_pz - t2_bin1_old.getOrigin().z());


    if(((dx1*dx1) + (dy1*dy1) + (dz1*dz1))<=0.00001){
        time1_check = false;
    }
    else{
        time1_check = true;
    }

    if(((dx2*dx2) + (dy2*dy2) + (dz2*dz2))<=0.00001){
        time2_check = false;
    }
    else{
        time2_check = true;
    }

// check orientation
    rot1_check=true;
    rot2_check=true;

//Logic: check in which frames the aruco marker gets detected
// and publish it in the frame nearer to the camera if detected 2 times
    if(time1_check){
        if(time2_check){

            //publish transform nearer to camera if aruco marker is detected in both frames
            if(dist_diff<=0){
                tf_bin1 = t1_bin1;
                ROS_INFO("Publish LONG_both");

            }
            else{
                tf_bin1 = t2_bin1;
                ROS_INFO("Publish SHORT_both");

            }
        }
        else{
            tf_bin1 = t1_bin1;
            ROS_INFO("Publish LONG");
        }
    }
    else{
        if(time2_check){
            tf_bin1 = t2_bin1;
            ROS_INFO("Publish SHORT");

        }
        else{
            //don't pubish if not detected at all
            //set a counter here and remove the object if it wasnt detected for 50 iterarions (=5sec)
            counter += 1;
            if (counter == 81){
                planning_scene_interface.removeCollisionObjects(object_ids); //delete objects from planning interface*/
                ROS_INFO("REMOVE OBJECT NOW!");
            }
            
            loop_rate.sleep(); 
            continue;
        }
    }

    counter = 0;
    
    bin.id = object_ids[0]; //bin 1 
    bin.primitive_poses[0].position.x = tf_bin1.getOrigin().x(); //set pose
    bin.primitive_poses[0].position.y = tf_bin1.getOrigin().y();
    bin.primitive_poses[0].position.z = tf_bin1.getOrigin().z();
    bin.primitive_poses[0].orientation.w= tf_bin1.getRotation().w();
    bin.primitive_poses[0].orientation.x= tf_bin1.getRotation().x();
    bin.primitive_poses[0].orientation.y= tf_bin1.getRotation().y();
    bin.primitive_poses[0].orientation.z= tf_bin1.getRotation().z();

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