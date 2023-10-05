#include "geometric_shapes/shapes.h"
#include "geometric_shapes/mesh_operations.h"
#include "geometric_shapes/shape_operations.h"

#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <std_msgs/Bool.h>
// #include <tf2/LinearMath/Quaternion.h>
// #include <tf2/LinearMath/Matrix3x3.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <my_services/PickPlaceAction.h> 


#include <tf/transform_listener.h>

tf::StampedTransform poseToStampedTransform(const geometry_msgs::Pose& pose, const std::string& frame_id, const std::string& child_frame_id)
{
    tf::Transform tf;
    tf::poseMsgToTF(pose, tf);
    tf::StampedTransform stamped_tf(tf, ros::Time::now(), frame_id, child_frame_id);
    return stamped_tf;
}

//define a struct so that you can efficiently iterate through all the markers
struct Marker {
    std::string id;
    std::string aruco_frame_long;
    std::string aruco_frame_short;
    tf::StampedTransform tf1;
    tf::StampedTransform tf2;
    tf::StampedTransform tf_final;
    moveit_msgs::CollisionObject object;
    int counter;
};

//Define a vector of type bool to store all detceted messages - one field for each marker id for every cam (2 cams and 5 ids ->10 fields)
std::vector<bool> det_vector(10, false);

//define a ba helper variable called "object_to_pick"
//Idea: wehenever a Pick and place action gets triggered -> stop spawning the object you want to pick
//Reason: buggy behaviour if object was attached to the robot arm and the cams still detect the object and try to spawn it again
//Logic: write 2 subscribers - one for Action/goal and one for Action/result...
// if action goal was triggered -> set "object_to_pick" to Marker_id and stop spawning the object with the id of concern
// if action/result was received -> set "object_to_pick" to Marker_id and object can be spawned again
int object_to_pick = 5;
ros::Subscriber ActionGoalSub;
ros::Subscriber ActionResultSub;
//callback for subscribers to action_feedback
void action_callback(my_services::PickPlaceActionGoal::ConstPtr goal_ptr){
    object_to_pick = (goal_ptr->goal.id)-1;
}

void action_result_callback(my_services::PickPlaceActionResult::ConstPtr res){
    object_to_pick = 5;
}


// define a variable callback function - each subscriber should assign its value to another vector entry
void detected_cb(const std_msgs::Bool::ConstPtr& msg, int index)
{
    det_vector[index] = msg->data;
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

//Initialize subscriber for each topic
std::vector<ros::Subscriber> subscribers;
for (int i = 0; i < 5; ++i) {
    // Use boost::bind() to attach the index to the callback function
    subscribers.push_back(node.subscribe<std_msgs::Bool>("/zed2i_long/aruco_quintuple/detected" + std::to_string(i+1), 1, boost::bind(detected_cb, _1, i)));
    subscribers.push_back(node.subscribe<std_msgs::Bool>("/zed2i_short/aruco_quintuple/detected" + std::to_string(i+1), 1, boost::bind(detected_cb, _1, i+5)));
}

ActionGoalSub = node.subscribe<my_services::PickPlaceActionGoal>("/PickPlace_Action/goal",1, action_callback);
ActionResultSub = node.subscribe<my_services::PickPlaceActionResult>("/PickPlace_Action/result", 1,action_result_callback);

//wait for initialization
ros::Duration(3.0).sleep();

moveit_msgs::CollisionObject bin; //Create an object msg

bin.header.frame_id = move_group_interface.getPlanningFrame();

// bin.header.frame_id = "zed2i_left_camera_optical_frame"; //"father frame" 
shape_msgs::SolidPrimitive primitive;
primitive.type = primitive.BOX;
primitive.dimensions.resize(3);
primitive.dimensions[0] = 0.05;
primitive.dimensions[1] = 0.05;
primitive.dimensions[2] = 0.04;  

geometry_msgs::Pose box_pose;
box_pose.orientation.w = 1.0;
box_pose.orientation.x= 0;
box_pose.orientation.y= 0;
box_pose.orientation.z= 0;
box_pose.position.x = 0.0;
box_pose.position.y = 0.0;
box_pose.position.z = 3.0;

bin.primitives.push_back(primitive);
bin.primitive_poses.push_back(box_pose);

bin.operation = bin.ADD; //add object to collitions 

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
    bin.primitive_poses[0].position.y = (0.06*i);
    marker.object = bin;
    collision_objects.push_back(bin);
    marker.counter = 0;
    marker.tf1 = poseToStampedTransform(box_pose, "world", marker.aruco_frame_long);
    marker.tf2 = poseToStampedTransform(box_pose, "world", marker.aruco_frame_short);
    marker.tf_final=marker.tf1;
    markers.push_back(marker);
    ros::Duration(0.5).sleep();
}

// collision_objects.push_back(bin); //you can insert different objects using a vector of collition objects
ROS_INFO("Start with adding objects");
planning_scene_interface.addCollisionObjects(collision_objects); //add objects to planning interface
ros::Duration(3.0).sleep();


// bin.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
// bin.operation = bin.MOVE;

bin.operation = bin.ADD; //change operation to MOVE

double desired_frequency = 10.0; // 5 Hz
ros::Rate loop_rate(desired_frequency);

//define helper variables for checks
bool rot1_check =true;
bool rot2_check =true;
bool detected = false;

while (node.ok()){

    collision_objects.clear(); //clear previous data in the vector

    //loop over all the 5 markers!
    for (int i = 0; i<5; ++i){

    //check if the frames are already available and skip if hey arent!
        try{
            listener.lookupTransform("world", markers[i].aruco_frame_long, ros::Time(0), markers[i].tf1);
        }
            catch (tf::TransformException ex){
            // ROS_WARN("%s",ex.what());
        }
        try{
            listener.lookupTransform("world", markers[i].aruco_frame_short, ros::Time(0), markers[i].tf2);
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

    // check orientation
        rot1_check=true;
        rot2_check=true;

    //Logic: check in which frames the aruco marker gets detected
    // and publish it in the frame nearer to the camera if detected 2 times
        if(det_vector[i]){

            detected = true;
            if(det_vector[(i+5)]){
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
            if(det_vector[(i+5)]){
                markers[i].tf_final = markers[i].tf2;
                detected = true;
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
            if(i != object_to_pick){
                markers[i].counter = 0;
                markers[i].object.primitive_poses[0].position.x = markers[i].tf_final.getOrigin().x(); //set pose
                markers[i].object.primitive_poses[0].position.y = markers[i].tf_final.getOrigin().y();
                markers[i].object.primitive_poses[0].position.z = markers[i].tf_final.getOrigin().z();
                markers[i].object.primitive_poses[0].orientation.w= markers[i].tf_final.getRotation().w();
                markers[i].object.primitive_poses[0].orientation.x= markers[i].tf_final.getRotation().x();
                markers[i].object.primitive_poses[0].orientation.y= markers[i].tf_final.getRotation().y();
                markers[i].object.primitive_poses[0].orientation.z= markers[i].tf_final.getRotation().z();

                //Offset the object by half of its length in its native coorinate system
                tf2::Quaternion quat;
                tf2::fromMsg(markers[i].object.primitive_poses[0].orientation, quat);

                // Convert the tf2::Quaternion to a tf2::Matrix3x3
                tf2::Matrix3x3 rot_mat(quat);

                // Create a tf2::Vector3 for the offset
                //WARNING: OFFSET(X,Y,Z) , WHERE Z = 1/2 CUBE HEIGHT
                tf2::Vector3 offset(0, 0, -0.02);

                // Rotate the offset vector by the rotation matrix
                offset = rot_mat * offset;

                // Add the rotated offset to the position
                markers[i].object.primitive_poses[0].position.x = markers[i].tf_final.getOrigin().x() + offset.x();
                markers[i].object.primitive_poses[0].position.y = markers[i].tf_final.getOrigin().y() + offset.y();
                markers[i].object.primitive_poses[0].position.z = markers[i].tf_final.getOrigin().z() + offset.z();

                // input collision object
                collision_objects.push_back(markers[i].object); // add to vector
            }
        }
    }

    planning_scene_interface.applyCollisionObjects(collision_objects); //apply changes to planning interface

    loop_rate.sleep(); 
}
planning_scene_interface.removeCollisionObjects(object_ids); //delete objects from planning interface*/

ros::shutdown(); //turn off
return 0;
}



// // Substitute beginning with this snippet here to have the orientation logic as well!
// while (node.ok()){

//     collision_objects.clear(); //clear previous data in the vector

//     //loop over all the 5 markers!
//     for (int i = 0; i<5; ++i){
//         try{
//     // Wait for the "world" frame to become available

//             listener.lookupTransform("world", markers[i].aruco_frame_long, ros::Time(0), markers[i].tf1);
//             listener.lookupTransform("world", markers[i].aruco_frame_short, ros::Time(0), markers[i].tf2);

//             //Conduct the orientation check --> check whether the angles of the z-axis between the detected aruco marker and the camera frame is 
//             // under a certain threshhold
//             tf::StampedTransform camera_to_marker_transform_long;
//             tf::StampedTransform camera_to_marker_transform_short;

//             listener.lookupTransform("zed2i_long_left_camera_frame", markers[i].aruco_frame_long, ros::Time(0), camera_to_marker_transform_long);
//             listener.lookupTransform("zed2i_long_left_camera_frame", markers[i].aruco_frame_long, ros::Time(0), camera_to_marker_transform_short);


//             // Convert the rotation to a tf2 Quaternion
//             tf2::Quaternion quaternion_long;
//             tf2::Quaternion quaternion_short;

//             quaternion_long.setValue(camera_to_marker_transform_long.getRotation().x(),
//                                 camera_to_marker_transform_long.getRotation().y(),
//                                 camera_to_marker_transform_long.getRotation().z(),
//                                 camera_to_marker_transform_long.getRotation().w());

//             quaternion_short.setValue(camera_to_marker_transform_short.getRotation().x(),
//                                 camera_to_marker_transform_short.getRotation().y(),
//                                 camera_to_marker_transform_short.getRotation().z(),
//                                 camera_to_marker_transform_short.getRotation().w());

//             // Convert the quaternion to a 3x3 rotation matrix
//             tf2::Matrix3x3 rotation_matrix_long(quaternion_long);
//             tf2::Matrix3x3 rotation_matrix_short(quaternion_short);

//             // Get the Z-axis vectors (third column of the rotation matrix for the marker frame, and [0, 0, 1] for the camera frame)
//             tf2::Vector3 marker_z_axis_long = rotation_matrix_long.getColumn(2);
//             tf2::Vector3 camera_z_axis_long = tf2::Vector3(0, 0, 1);

//             tf2::Vector3 marker_z_axis_short = rotation_matrix_short.getColumn(2);
//             tf2::Vector3 camera_z_axis_short = tf2::Vector3(0, 0, 1);

//             // Calculate the angle between the two vectors
//             double angle_long = acos(camera_z_axis_long.dot(marker_z_axis_long));
//             double angle_short = acos(camera_z_axis_short.dot(marker_z_axis_short));

//             // Convert the angle to degrees if needed
//             double angle_degrees_long = angle_long * 180.0 / M_PI;
//             double angle_degrees_short = angle_short * 180.0 / M_PI;

//             // ROS_INFO("here is the pose %f", markers[i].tf1.getOrigin().x());

//             if(angle_degrees_long <= 45){
//                 rot1_check=true;
//             }
//             else{rot1_check = false;}

//             if(angle_degrees_short <= 45){
//                 rot2_check=true;
//             }
//             else{rot2_check = false;}
//         }

//             catch (tf::TransformException ex){
//             // ROS_WARN("%s",ex.what());
//         }

//         // Check whether the aruco markers have been detected and if they have been, check, whether the orientation of the marker with respect to the camera is valid: 
//         //If the marker surface z-axis is aligned with the z-axis of the camera frame, the quality of the detection is higher than when the marker is tilted.
//         //Therefore, if the angle between the 2 z-axis is larger than a certain threshhold in one camera frame, publish it in the other one! 
//         // This property is being calculated and stored inside the variables "rot1_check", "rot2_check"
//         if(det_vector[i]){





//      //substitute the case where both of the cams detect the aruco markers to have the orientation logic as well!:
//             detected = true;
//             if(det_vector[(i+5)]){

//                 //publish transform nearer to camera if aruco marker is detected in both frames and markers orientation is right
//                 if((rot1_check && rot2_check) ||((!rot1_check) && (!rot2_check))){
//                     if(dist_diff<=0){
//                         markers[i].tf_final = markers[i].tf1;

//                     }
//                     else{
//                         markers[i].tf_final = markers[i].tf2;
//                     }
//                 }
//                 // else check which of the detections has the aruco marker detected 
//                 else{
//                     if(rot1_check){
//                         markers[i].tf_final = markers[i].tf1;
//                     }
//                     else{
//                         markers[i].tf_final = markers[i].tf2;
//                     }
//                 }
//             }
//         }

