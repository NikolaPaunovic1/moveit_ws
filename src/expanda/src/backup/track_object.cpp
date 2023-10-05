#include "geometric_shapes/shapes.h"
#include "geometric_shapes/mesh_operations.h"
#include "geometric_shapes/shape_operations.h"

#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/CollisionObject.h>

#include <tf/transform_listener.h>

int main(int argc, char** argv){

ros::init(argc, argv, "bins_tracker");
ros::NodeHandle node; 

tf::TransformListener listener; //tf listener & transformations
tf::StampedTransform t_bin1;
tf::StampedTransform t_bin2;
tf::StampedTransform t_bin3;

std::vector<moveit_msgs::CollisionObject> collision_objects; //vector of objects
std::vector<std::string> object_ids; //vector of strings (names of objects)
object_ids.push_back("Bin1");
object_ids.push_back("Bin2");
object_ids.push_back("Bin3");

moveit::planning_interface::PlanningSceneInterface planning_scene_interface; //planning interface
moveit_msgs::CollisionObject bin; //Create an object msg

shapes::Mesh* m = shapes::createMeshFromResource("package://motoman_sda10f_support/meshes/bin.stl"); //find mesh
shape_msgs::Mesh mesh; //create a mesh msg
shapes::ShapeMsg mesh_msg; //create a shape msg
shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
ros::Duration(0.5).sleep();
mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg

bin.header.frame_id = "torso_base_link"; //"father frame"   
bin.meshes.resize(1); //scale
bin.meshes[0]=mesh; //mesh

bin.mesh_poses.resize(1); //vector resize
bin.mesh_poses[0].position.x = 0; //pose
bin.mesh_poses[0].position.y = 0;
bin.mesh_poses[0].position.z = 0;
bin.mesh_poses[0].orientation.w= 1.0;
bin.mesh_poses[0].orientation.x= 0;
bin.mesh_poses[0].orientation.y= 0;
bin.mesh_poses[0].orientation.z= 0;

bin.operation = bin.ADD; //add object to collitions 

bin.id =object_ids[0]; //rename object 
collision_objects.push_back(bin); //you can insert different objects using a vector of collition objects
bin.id=object_ids[1]; //rename object and reuse bin msg struture
collision_objects.push_back(bin); //add object to vector
bin.id=object_ids[2];//rename object and reuse bin msg struture
collision_objects.push_back(bin); //add object to vector

planning_scene_interface.addCollisionObjects(collision_objects); //add objects to planning interface

bin.meshes.clear(); //Clear mesh required for MOVE operation (Only to avoid a warning)
bin.operation = bin.MOVE; //change operation to MOVE

while (node.ok()){
    //Listen to tfs
    try{
        listener.lookupTransform("torso_base_link", "bin1", ros::Time(0), t_bin1);
    }

        catch (tf::TransformException ex){
        ROS_WARN("%s",ex.what());
    }

    try{
        listener.lookupTransform("torso_base_link", "bin2", ros::Time(0), t_bin2);
    }
    catch (tf::TransformException ex){
        ROS_WARN("%s",ex.what());
    }

    try{
        listener.lookupTransform("torso_base_link", "bin3", ros::Time(0), t_bin3);
    }
    catch (tf::TransformException ex){
        ROS_WARN("%s",ex.what());
    }

    collision_objects.clear(); //clear previous data in the vector

    bin.id = object_ids[0]; //bin 1 
    bin.mesh_poses[0].position.x = t_bin1.getOrigin().x(); //set pose
    bin.mesh_poses[0].position.y = t_bin1.getOrigin().y();
    bin.mesh_poses[0].position.z = t_bin1.getOrigin().z();
    bin.mesh_poses[0].orientation.w= t_bin1.getRotation().w();
    bin.mesh_poses[0].orientation.x= t_bin1.getRotation().x();
    bin.mesh_poses[0].orientation.y= t_bin1.getRotation().y();
    bin.mesh_poses[0].orientation.z= t_bin1.getRotation().z();

    collision_objects.push_back(bin); // add to vector

    bin.id = object_ids[1]; //rename
    bin.mesh_poses[0].position.x = t_bin2.getOrigin().x(); //set pose
    bin.mesh_poses[0].position.y = t_bin2.getOrigin().y();
    bin.mesh_poses[0].position.z = t_bin2.getOrigin().z();
    bin.mesh_poses[0].orientation.w= t_bin2.getRotation().w();
    bin.mesh_poses[0].orientation.x= t_bin2.getRotation().x();
    bin.mesh_poses[0].orientation.y= t_bin2.getRotation().y();
    bin.mesh_poses[0].orientation.z= t_bin2.getRotation().z();

    collision_objects.push_back(bin); //add to vector

    bin.id = object_ids[2]; //rename
    bin.mesh_poses[0].position.x = t_bin3.getOrigin().x(); //add vector
    bin.mesh_poses[0].position.y = t_bin3.getOrigin().y();
    bin.mesh_poses[0].position.z = t_bin3.getOrigin().z();
    bin.mesh_poses[0].orientation.w= t_bin3.getRotation().w();
    bin.mesh_poses[0].orientation.x= t_bin3.getRotation().x();
    bin.mesh_poses[0].orientation.y= t_bin3.getRotation().y();
    bin.mesh_poses[0].orientation.z= t_bin3.getRotation().z();

    collision_objects.push_back(bin); //add to vector

    planning_scene_interface.applyCollisionObjects(collision_objects); //apply changes to planning interface
    ros::Duration(0.5).sleep(); //ZzZzZ
}
planning_scene_interface.removeCollisionObjects(object_ids); //delete objects from planning interface*/

ros::shutdown(); //turn off
return 0;
}