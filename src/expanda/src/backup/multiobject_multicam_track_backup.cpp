#include "geometric_shapes/shapes.h"
#include "geometric_shapes/mesh_operations.h"
#include "geometric_shapes/shape_operations.h"

#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <std_msgs/Bool.h>


#include <tf/transform_listener.h>

tf::StampedTransform poseToStampedTransform(const geometry_msgs::Pose& pose, const std::string& frame_id, const std::string& child_frame_id)
{
    tf::Transform tf;
    tf::poseMsgToTF(pose, tf);
    tf::StampedTransform stamped_tf(tf, ros::Time::now(), frame_id, child_frame_id);
    return stamped_tf;
}

struct Marker {
    std::string id;
    std::string aruco_frame_long;
    std::string aruco_frame_short;
    tf::StampedTransform tf1;
    tf::StampedTransform tf2;
    tf::StampedTransform old_tf1;
    tf::StampedTransform old_tf2;
    tf::StampedTransform tf_final;
    moveit_msgs::CollisionObject object;
    int counter;
};

bool det1;
bool det2;
bool det3;
bool det4;
bool det5;
// This is your callback function that gets called when a new message arrives on the "detected1" topic
void detected1_cb(const std_msgs::Bool::ConstPtr& msg)
{
  // Set your boolean variable to the data from the message
  det1 = msg->data;
}
void detected2_cb(const std_msgs::Bool::ConstPtr& msg)
{
  // Set your boolean variable to the data from the message
  det2 = msg->data;
}
void detected3_cb(const std_msgs::Bool::ConstPtr& msg)
{
  // Set your boolean variable to the data from the message
  det3 = msg->data;
}
void detected4_cb(const std_msgs::Bool::ConstPtr& msg)
{
  // Set your boolean variable to the data from the message
  det4 = msg->data;
}
void detected5_cb(const std_msgs::Bool::ConstPtr& msg)
{
  // Set your boolean variable to the data from the message
  det5 = msg->data;
}


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

std::vector<moveit_msgs::CollisionObject> collision_objects; //vector of objects
std::vector<std::string> object_ids; //vector of strings (names of objects)
// object_ids.push_back("Bin1");
moveit::planning_interface::PlanningSceneInterface planning_scene_interface; //planning interface

ros::Subscriber sub_detect1 = node.subscribe("detected1", 1, detected1_cb);

ros::Duration(2.0).sleep();

moveit_msgs::CollisionObject bin; //Create an object msg

bin.header.frame_id = move_group_interface.getPlanningFrame();

// bin.header.frame_id = "zed2i_left_camera_optical_frame"; //"father frame" 
shape_msgs::SolidPrimitive primitive;
primitive.type = primitive.BOX;
primitive.dimensions.resize(3);
primitive.dimensions[0] = 0.03;
primitive.dimensions[1] = 0.03;
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

// bin.id =object_ids[0]; //rename object 

bool time1_check =false;
bool time2_check =false;
bool rot1_check =true;
bool rot2_check =true;
bool detected = false;
std::vector<std::string> single_object_id;

std::vector<Marker> markers;
ROS_INFO("Start with marker init");
//Initialize markers!
for (int i = 0; i < 5; ++i) {
    Marker marker;
    marker.id = "Bin" + std::to_string(i+1);
    marker.aruco_frame_long = "aruco_frame_long" + std::to_string(i+1);
    marker.aruco_frame_short = "aruco_frame_short" + std::to_string(i+1);
    object_ids.push_back(marker.id);
    bin.id = object_ids[i];
    bin.primitive_poses[0].position.y = (0.04*i);
    marker.object = bin;
    collision_objects.push_back(bin);
    marker.counter = 0;
    marker.tf1 = poseToStampedTransform(box_pose, "world", marker.aruco_frame_long);
    marker.tf2 = poseToStampedTransform(box_pose, "world", marker.aruco_frame_short);
    marker.tf_final=marker.tf1;
    marker.old_tf1=marker.tf1;
    marker.old_tf2=marker.tf2;
    markers.push_back(marker);
    ros::Duration(0.5).sleep();
}

// collision_objects.push_back(bin); //you can insert different objects using a vector of collition objects
ROS_INFO("Start with adding objects");
planning_scene_interface.addCollisionObjects(collision_objects); //add objects to planning interface
ros::Duration(2.0).sleep();


// bin.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
// bin.operation = bin.MOVE;

bin.operation = bin.ADD; //change operation to MOVE

double desired_frequency = 10.0; // 10 Hz
ros::Rate loop_rate(desired_frequency);

while (node.ok()){

    collision_objects.clear(); //clear previous data in the vector

    //loop over all the 5 markers!
    for (int i = 0; i<5; ++i){
        //Listen to tfs
        markers[i].old_tf1=markers[i].tf1;
        markers[i].old_tf2=markers[i].tf2;
        try{
    // Wait for the "world" frame to become available

            listener.lookupTransform("world", markers[i].aruco_frame_long, ros::Time(0), markers[i].tf1);
            listener.lookupTransform("world", markers[i].aruco_frame_short, ros::Time(0), markers[i].tf2);

            // ROS_INFO("here is the pose %f", t1_bin1.getOrigin().x());
        }

            catch (tf::TransformException ex){
            // ROS_WARN("%s",ex.what());
        }

    //store Transformation params cam 1
        float t1_px = markers[i].tf1.getOrigin().x(); //set pose
        float t1_py = markers[i].tf1.getOrigin().y();
        float t1_pz = markers[i].tf1.getOrigin().z();

    //store Transformation params cam 2
        float t2_px = markers[i].tf2.getOrigin().x(); //set pose
        float t2_py = markers[i].tf2.getOrigin().y();
        float t2_pz = markers[i].tf2.getOrigin().z();

    //compute distance
        float dist_diff = (t1_px*t1_px)+(t1_py*t1_py)+(t1_pz*t1_pz)-(t2_px*t2_px)-(t2_py*t2_py)-(t2_pz*t2_pz);

    //check if marker was detected
        float dx1 = (t1_px - markers[i].old_tf1.getOrigin().x());
        float dy1 = (t1_py - markers[i].old_tf1.getOrigin().y());
        float dz1 = (t1_pz - markers[i].old_tf1.getOrigin().z());
        float dx2 = (t2_px - markers[i].old_tf2.getOrigin().x());
        float dy2 = (t2_py - markers[i].old_tf2.getOrigin().y());
        float dz2 = (t2_pz - markers[i].old_tf2.getOrigin().z());


        if((abs(dx1) + abs(dy1) + abs(dz1))<=0.00001){
            time1_check = false;
            // ROS_INFO("distance1_false %f",(abs(dx1) + abs(dy1) + abs(dz1)) );
        }
        else{
            time1_check = true;
            detected = true;
            // ROS_INFO("distance1_true %f",(abs(dx1) + abs(dy1) + abs(dz1)) );

        }

        if((abs(dx2) + abs(dy2) + abs(dz2))<=0.00001){
            time2_check = false;
            // ROS_INFO("distance2_false %f",(abs(dx2) + abs(dy2) + abs(dz2)) );
        }
        else{
            time2_check = true;
            // ROS_INFO("distance2_true %f",(abs(dx2) + abs(dy2) + abs(dz2)) );
            detected = true;
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
                    markers[i].tf_final = markers[i].tf1;
                    // ROS_INFO("Publish LONG_both");

                }
                else{
                    markers[i].tf_final = markers[i].tf2;
                    // ROS_INFO("Publish SHORT_both");

                }
            }
            else{
                markers[i].tf_final = markers[i].tf1;
                // ROS_INFO("Publish LONG");
            }
        }
        else{
            if(time2_check){
                markers[i].tf_final = markers[i].tf2;
                // ROS_INFO("Publish SHORT");
            }
            else{
                //don't pubish if not detected at all
                //set a counter here and remove the object if it wasnt detected for 50 iterarions (=5sec)
                markers[i].counter += 1;
                detected = false;
            }
        }

        if(!detected){
            if(markers[i].counter == 81){
                single_object_id.clear();
                single_object_id.push_back(object_ids[i]);
                planning_scene_interface.removeCollisionObjects(single_object_id); //delete objects from planning interface*/
                ROS_INFO("OBJECT WAS REMOVED!");
            }
        }
        else{
        markers[i].counter = 0;
        markers[i].object.primitive_poses[0].position.x = markers[i].tf_final.getOrigin().x(); //set pose
        markers[i].object.primitive_poses[0].position.y = markers[i].tf_final.getOrigin().y();
        markers[i].object.primitive_poses[0].position.z = markers[i].tf_final.getOrigin().z();
        markers[i].object.primitive_poses[0].orientation.w= markers[i].tf_final.getRotation().w();
        markers[i].object.primitive_poses[0].orientation.x= markers[i].tf_final.getRotation().x();
        markers[i].object.primitive_poses[0].orientation.y= markers[i].tf_final.getRotation().y();
        markers[i].object.primitive_poses[0].orientation.z= markers[i].tf_final.getRotation().z();

        collision_objects.push_back(markers[i].object); // add to vector
        }
    }

    planning_scene_interface.applyCollisionObjects(collision_objects); //apply changes to planning interface

    loop_rate.sleep(); 
}
planning_scene_interface.removeCollisionObjects(object_ids); //delete objects from planning interface*/

ros::shutdown(); //turn off
return 0;
}