#include "geometric_shapes/shapes.h"
#include "geometric_shapes/mesh_operations.h"
#include "geometric_shapes/shape_operations.h"
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/CollisionObject.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <std_msgs/Bool.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <my_services/PickPlace2Action.h> 
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

//Define a vector of type bool to store all detceted messages - one field for each marker id for every cam (2 cams and 8 ids ->16 fields)
std::vector<bool> det_vector(16, false); 

//define a ba helper variable called "object_to_pick"
//Idea: wehenever a Pick and place action gets triggered -> stop spawning the object you want to pick
//Reason: buggy behaviour if object was attached to the robot arm and the cams still detect the object and try to spawn it again
//Logic: write 2 subscribers - one for Action/goal and one for Action/result...
// if action goal was triggered -> set "object_to_pick" to Marker_id and stop spawning the object with the id of concern
// if action/result was received -> set "object_to_pick" to Marker_id and object can be spawned again
int object_to_pick = 8;
ros::Subscriber ActionGoalSub;
ros::Subscriber ActionResultSub;
//callback for subscribers to action_feedback
void action_callback(my_services::PickPlace2ActionGoal::ConstPtr goal_ptr){
    object_to_pick = (goal_ptr->goal.id)-1;
}

void action_result_callback(my_services::PickPlace2ActionResult::ConstPtr res){
    object_to_pick = 8;
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
moveit::planning_interface::PlanningSceneInterface planning_scene_interface; //planning interface

//Initialize subscriber for each topic
std::vector<ros::Subscriber> subscribers;
for (int i = 0; i < 8; ++i) {
    subscribers.push_back(node.subscribe<std_msgs::Bool>("/zed2i_long/aruco_octuple/detected" + std::to_string(i+1), 1, boost::bind(detected_cb, _1, i)));
    subscribers.push_back(node.subscribe<std_msgs::Bool>("/zed2i_short/aruco_octuple/detected" + std::to_string(i+1), 1, boost::bind(detected_cb, _1, i+8)));
}

//Initialize subscriber to Actionserver topics - needed to know when an action starts and end
//reason: Stop spawning the object to be picked - weird bugs, when object constantly keeps respawning
ActionGoalSub = node.subscribe<my_services::PickPlace2ActionGoal>("/PickPlace_Action/goal",1, action_callback);
ActionResultSub = node.subscribe<my_services::PickPlace2ActionResult>("/PickPlace_Action/result", 1,action_result_callback);

//wait for initialization
ros::Duration(5.0).sleep();

//define collision_objects to be loaded into the scene--------------------------------------------------------------------------
std::vector<moveit_msgs::CollisionObject> bins;

//define cutting_board collision object
moveit_msgs::CollisionObject board;
board.header.frame_id = move_group_interface.getPlanningFrame();
geometry_msgs::Pose board_pose;
board_pose.orientation.w = 1.0;
board_pose.orientation.x = 0.0;
board_pose.orientation.y = 0.0;
board_pose.orientation.z = 0.0;
board_pose.position.x = 0.0;
board_pose.position.y = 0.0;
board_pose.position.z = 3.0;
// Add the mesh to the CollisionObject
shapes::Mesh* m = shapes::createMeshFromResource("package://expanda/meshes/cutting_ass.stl"); //find mesh
double scale_factor = 0.001; // convert millimeters to meters
for (unsigned int i = 0; i < m->vertex_count; ++i)
{
m->vertices[i * 3] *= scale_factor;
m->vertices[i * 3 + 1] *= scale_factor;
m->vertices[i * 3 + 2] *= scale_factor;
}
shape_msgs::Mesh mesh; //create a mesh msg
shapes::ShapeMsg mesh_msg; //create a shape msg
shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
ros::Duration(0.5).sleep();
mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg
board.meshes.push_back(mesh);
board.mesh_poses.push_back(board_pose);
board.operation = board.ADD;


//Knife collision Object
moveit_msgs::CollisionObject knife;
knife.header.frame_id = move_group_interface.getPlanningFrame();
geometry_msgs::Pose knife_pose = board_pose;
// Add the mesh to the CollisionObject
m = shapes::createMeshFromResource("package://expanda/meshes/knife_ass.stl"); //find mesh
for (unsigned int i = 0; i < m->vertex_count; ++i)
{
m->vertices[i * 3] *= scale_factor;
m->vertices[i * 3 + 1] *= scale_factor;
m->vertices[i * 3 + 2] *= scale_factor;
}
shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
ros::Duration(0.5).sleep();
mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg
knife.meshes.push_back(mesh);
knife.mesh_poses.push_back(knife_pose);
knife.operation = knife.ADD;


//pan collision Object
moveit_msgs::CollisionObject pan;
pan.header.frame_id = move_group_interface.getPlanningFrame();
geometry_msgs::Pose pan_pose = board_pose;
// Add the mesh to the CollisionObject
m = shapes::createMeshFromResource("package://expanda/meshes/pan_ass.stl"); //find mesh
for (unsigned int i = 0; i < m->vertex_count; ++i)
{
m->vertices[i * 3] *= scale_factor;
m->vertices[i * 3 + 1] *= scale_factor;
m->vertices[i * 3 + 2] *= scale_factor;
}
shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
ros::Duration(0.5).sleep();
mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg
pan.meshes.push_back(mesh);
pan.mesh_poses.push_back(pan_pose);
pan.operation = pan.ADD;

//spoon collision Object
moveit_msgs::CollisionObject spoon;
spoon.header.frame_id = move_group_interface.getPlanningFrame();
geometry_msgs::Pose spoon_pose = board_pose;
// Add the mesh to the CollisionObject
m = shapes::createMeshFromResource("package://expanda/meshes/spoon_ass.stl"); //find mesh
for (unsigned int i = 0; i < m->vertex_count; ++i)
{
m->vertices[i * 3] *= scale_factor;
m->vertices[i * 3 + 1] *= scale_factor;
m->vertices[i * 3 + 2] *= scale_factor;
}
shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
ros::Duration(0.5).sleep();
mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg
spoon.meshes.push_back(mesh);
spoon.mesh_poses.push_back(spoon_pose);
spoon.operation = spoon.ADD;

//flakes collision Object
moveit_msgs::CollisionObject flakes;
flakes.header.frame_id = move_group_interface.getPlanningFrame();
geometry_msgs::Pose flakes_pose = board_pose;
// Add the mesh to the CollisionObject
m = shapes::createMeshFromResource("package://expanda/meshes/flakes.stl"); //find mesh
for (unsigned int i = 0; i < m->vertex_count; ++i)
{
m->vertices[i * 3] *= scale_factor;
m->vertices[i * 3 + 1] *= scale_factor;
m->vertices[i * 3 + 2] *= scale_factor;
}
shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
ros::Duration(0.5).sleep();
mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg
flakes.meshes.push_back(mesh);
flakes.mesh_poses.push_back(flakes_pose);
flakes.operation = flakes.ADD;

//bowl collision Object
moveit_msgs::CollisionObject bowl;
bowl.header.frame_id = move_group_interface.getPlanningFrame();
geometry_msgs::Pose bowl_pose = board_pose;
// Add the mesh to the CollisionObject
m = shapes::createMeshFromResource("package://expanda/meshes/bowl_ass.stl"); //find mesh
for (unsigned int i = 0; i < m->vertex_count; ++i)
{
m->vertices[i * 3] *= scale_factor;
m->vertices[i * 3 + 1] *= scale_factor;
m->vertices[i * 3 + 2] *= scale_factor;
}
shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
ros::Duration(0.5).sleep();
mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg
bowl.meshes.push_back(mesh);
bowl.mesh_poses.push_back(bowl_pose);
bowl.operation = bowl.ADD;

//fill the bin vector with the collisionobjects you want
bins.push_back(board); //should correspond to mesh of aruco_id specified first in launchfile
bins.push_back(knife); //should correspond to mesh of aruco_id specified second in launchfile
bins.push_back(pan); //should correspond to mesh of aruco_id specified third in launchfile
bins.push_back(spoon); //should correspond to mesh of aruco_id specified fourth in launchfile
bins.push_back(flakes); //should correspond to mesh of aruco_id specified fifth in launchfile
bins.push_back(bowl); //should correspond to mesh of aruco_id specified fifth in launchfile
bins.push_back(knife); //should correspond to mesh of aruco_id specified fifth in launchfile
bins.push_back(knife); //should correspond to mesh of aruco_id specified fifth in launchfile
//--------------------------------------------------------------------------------------------


//helper variable - has to be initialized here
std::vector<std::string> single_object_id;

//make a vector of markers to iterate through each marker efficiently
std::vector<Marker> markers;
ROS_INFO("Start with marker init");
//Initialize markers!
for (int i = 0; i < 8; ++i) {
    Marker marker;
    marker.id = "Bin" + std::to_string(i+1);
    marker.aruco_frame_long = "aruco_frame_long" + std::to_string(i+1);
    marker.aruco_frame_short = "aruco_frame_short" + std::to_string(i+1);
    object_ids.push_back(marker.id);
    bins[i].id = object_ids[i];
    bins[i].mesh_poses[0].position.x = 1.0*i;
    marker.object = bins[i];
    collision_objects.push_back(bins[i]);
    marker.counter = 0;
    marker.tf1 = poseToStampedTransform(board_pose, "world", marker.aruco_frame_long);
    marker.tf2 = poseToStampedTransform(board_pose, "world", marker.aruco_frame_short);
    marker.tf_final=marker.tf1;
    markers.push_back(marker);
    ros::Duration(0.5).sleep();
}

// collision_objects.push_back(bin); //you can insert different objects using a vector of collition objects
ROS_INFO("Start with adding objects");
planning_scene_interface.addCollisionObjects(collision_objects); //add objects to planning interface
ros::Duration(3.0).sleep();

//change the operation to move
board.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
board.operation = board.MOVE;
knife.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
knife.operation = knife.MOVE;
pan.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
pan.operation = pan.MOVE;
spoon.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
spoon.operation = spoon.MOVE;
flakes.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
flakes.operation = flakes.MOVE;
bowl.primitives.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
bowl.operation = bowl.MOVE;

double desired_frequency = 3.0; // 5 Hz
ros::Rate loop_rate(desired_frequency);

//define helper variables for checks
bool rot1_check =true;
bool rot2_check =true;
bool detected = false;

while (node.ok()){

    collision_objects.clear(); //clear previous data in the vector

    //loop over all the 8 markers!
    for (int i = 0; i<8; ++i){

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

    // check orientation - will not be used for now
        rot1_check=true;
        rot2_check=true;

    //Logic: check in which frames the aruco marker gets detected
    // and publish it in the frame nearer to the camera if detected 2 times
        if(det_vector[i]){

            detected = true;
            if(det_vector[(i+8)]){
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
            if(det_vector[(i+8)]){
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
                markers[i].object.mesh_poses[0].position.x = markers[i].tf_final.getOrigin().x(); //set pose
                markers[i].object.mesh_poses[0].position.y = markers[i].tf_final.getOrigin().y();
                markers[i].object.mesh_poses[0].position.z = markers[i].tf_final.getOrigin().z();
                markers[i].object.mesh_poses[0].orientation.w= markers[i].tf_final.getRotation().w();
                markers[i].object.mesh_poses[0].orientation.x= markers[i].tf_final.getRotation().x();
                markers[i].object.mesh_poses[0].orientation.y= markers[i].tf_final.getRotation().y();
                markers[i].object.mesh_poses[0].orientation.z= markers[i].tf_final.getRotation().z();

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

