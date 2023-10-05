#include <ros/ros.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <moveit_msgs/CollisionObject.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <geometric_shapes/shapes.h>
#include <geometric_shapes/mesh_operations.h>
#include "geometric_shapes/shape_operations.h"
#include <tf/transform_listener.h>

int main (int argc, char **argv)
{

    //initialize node
    ros::init(argc, argv, "cam_tripod_spawner");

    //implement async spinner to read object cam poses and spawn objects
    ros::AsyncSpinner spinner(1);
    spinner.start();

    //initialize environment when working with real world
    moveit::planning_interface::PlanningSceneInterface planning_scene_interface;
    tf::TransformListener listener; //tf listener & transformations
    ros::Duration(1.5).sleep();

    // Define Objects to be spawned

    //define cones for camera objects
    moveit_msgs::CollisionObject cone;
    cone.header.frame_id = "panda_link0";
    cone.id = "cone";
    shapes::Mesh* m = shapes::createMeshFromResource("package://expanda/meshes/cone_600_130.stl"); //find mesh
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


    // Set the object's pose - get it from TF_tree
    tf::StampedTransform cone_tf;
    try{
    listener.lookupTransform("world", "zed2i_long_base_link", ros::Time(0), cone_tf);
    }
        catch (tf::TransformException ex){
        ROS_WARN("Transform to cam_frame_long not available");
    }
    geometry_msgs::Pose mesh_pose;
    mesh_pose.orientation.w = 1.0;
    mesh_pose.orientation.x = 0.0;
    mesh_pose.orientation.y = 0.0;
    mesh_pose.orientation.z = 0.0;
    mesh_pose.position.x = cone_tf.getOrigin().x();
    mesh_pose.position.y = cone_tf.getOrigin().y();
    mesh_pose.position.z = 0.0;

    // Add the mesh to the CollisionObject
    cone.meshes.push_back(mesh);
    cone.mesh_poses.push_back(mesh_pose);
    cone.operation = cone.ADD;

    //define second cone
    //define cones for camera objects
    moveit_msgs::CollisionObject cone_2;
    cone_2.header.frame_id = "panda_link0";
    cone_2.id = "cone_2";

    // Set the object's pose - get it from TF_tree
    tf::StampedTransform cone_2tf;
    try{
    listener.lookupTransform("world", "zed2i_short_base_link", ros::Time(0), cone_2tf);
    }
        catch (tf::TransformException ex){
        ROS_WARN("Transform to cam_frame_short not available");
    }
    geometry_msgs::Pose mesh_pose_2;
    mesh_pose_2.orientation.w = 1.0;
    mesh_pose_2.orientation.x = 0.0;
    mesh_pose_2.orientation.y = 0.0;
    mesh_pose_2.orientation.z = 0.0;
    mesh_pose_2.position.x = cone_2tf.getOrigin().x();
    mesh_pose_2.position.y = cone_2tf.getOrigin().y();
    mesh_pose_2.position.z = 0.0;
    // Add the mesh to the CollisionObject
    cone_2.meshes.push_back(mesh);
    cone_2.mesh_poses.push_back(mesh_pose_2);
    cone_2.operation = cone_2.ADD;

    //ONLY IF YOU WANT ANOTHER MESH FOR CONE_2---------------
    m = shapes::createMeshFromResource("package://expanda/meshes/cone_1000_200.stl"); //find mesh

    //scale your mesh
    for (unsigned int i = 0; i < m->vertex_count; ++i)
    {
      m->vertices[i * 3] *= scale_factor;
      m->vertices[i * 3 + 1] *= scale_factor;
      m->vertices[i * 3 + 2] *= scale_factor;
    }

    shapes::constructMsgFromShape(m,mesh_msg); //convert shape into a shape msg
    ros::Duration(0.5).sleep();
    mesh = boost::get<shape_msgs::Mesh>(mesh_msg); // shape msg is assigned to mesh msg
    //-------------------------------------------------------------------

    //define a collision_objects vector to store all collision objects to be spawned!
    std::vector<moveit_msgs::CollisionObject> collision_objects;

    //define third cone -- only spawn if a user input was given
    if(argc>2 && std::string(argv[1]) != "" && std::string(argv[2]) != "")
    {
        moveit_msgs::CollisionObject cone_3;
        cone_3.header.frame_id = "panda_link0";
        cone_3.id = "cone_3";
        geometry_msgs::Pose mesh_pose_3;
        mesh_pose_3.orientation.w = 1.0;
        mesh_pose_3.orientation.x = 0.0;
        mesh_pose_3.orientation.y = 0.0;
        mesh_pose_3.orientation.z = 0.0;
        mesh_pose_3.position.x = atof(argv[1]);
        mesh_pose_3.position.y = atof(argv[2]);
        mesh_pose_3.position.z = 0.0;
        // Add the mesh to the CollisionObject
        cone_3.meshes.push_back(mesh);
        cone_3.mesh_poses.push_back(mesh_pose_3);
        cone_3.operation = cone_3.ADD;

        collision_objects.push_back(cone_3);

        //if more than 2 args were given:
        if(argc>3)
        {
            ROS_WARN("Only 2 User Inputs were necessary (x,y) but %d were given!", (argc-1));
        }
    }

    //add all the objects into one vector
    collision_objects.push_back(cone);
    collision_objects.push_back(cone_2);
    ros::Duration(1.0).sleep();

    //add cams as boxes:

    //cam1
    moveit_msgs::CollisionObject box1;
    box1.id = "box1";
    box1.header.frame_id = "panda_link0";

    shape_msgs::SolidPrimitive box1_primitive;
    box1_primitive.type = box1_primitive.BOX;
    box1_primitive.dimensions.resize(3);
    box1_primitive.dimensions[0] = 0.07;  // x dimension
    box1_primitive.dimensions[1] = 0.22;   // y dimension
    box1_primitive.dimensions[2] = 0.07;  // z dimension

    geometry_msgs::Pose box1_pose;
    box1_pose.position.x = cone_tf.getOrigin().x();
    box1_pose.position.y = cone_tf.getOrigin().y();
    box1_pose.position.z = cone_tf.getOrigin().z();

    box1_pose.orientation.x = cone_tf.getRotation().x();
    box1_pose.orientation.y = cone_tf.getRotation().y();
    box1_pose.orientation.z = cone_tf.getRotation().z();
    box1_pose.orientation.w = cone_tf.getRotation().w();

    box1.primitives.push_back(box1_primitive);
    box1.primitive_poses.push_back(box1_pose);
    box1.operation = box1.ADD;

    //cam2
    moveit_msgs::CollisionObject box2;
    box2.id = "box2";
    box2.header.frame_id = "panda_link0";

    shape_msgs::SolidPrimitive box2_primitive;
    box2_primitive.type = box2_primitive.BOX;
    box2_primitive.dimensions.resize(3);
    box2_primitive.dimensions[0] = 0.07;  // x dimension
    box2_primitive.dimensions[1] = 0.22;   // y dimension
    box2_primitive.dimensions[2] = 0.07;  // z dimension

    geometry_msgs::Pose box2_pose;
    box2_pose.position.x = cone_2tf.getOrigin().x();
    box2_pose.position.y = cone_2tf.getOrigin().y();
    box2_pose.position.z = cone_2tf.getOrigin().z();

    box2_pose.orientation.x = cone_2tf.getRotation().x();
    box2_pose.orientation.y = cone_2tf.getRotation().y();
    box2_pose.orientation.z = cone_2tf.getRotation().z();
    box2_pose.orientation.w = cone_2tf.getRotation().w();

    box2.primitives.push_back(box2_primitive);
    box2.primitive_poses.push_back(box2_pose);
    box2.operation = box2.ADD;

    collision_objects.push_back(box2);
    collision_objects.push_back(box1);

    ros::Duration(1.0).sleep();

    // Define A collisionobject named Wall

    //define wall dimensions
    double wall_width = 2.0;  // 2 meters wide
    double wall_height = 1;  // 2.5 meters tall
    double wall_depth = 0.02;  // 2 cm thick

    // Create a wall object
    moveit_msgs::CollisionObject wall;
    wall.header.frame_id = "panda_link0";
    wall.id = "wall";

    // Define the shape and size
    shape_msgs::SolidPrimitive wall_primitive;
    wall_primitive.type = wall_primitive.BOX;
    wall_primitive.dimensions.resize(3);
    wall_primitive.dimensions[0] = wall_depth;   // x dimension (depth)
    wall_primitive.dimensions[1] = wall_width;   // y dimension (width)
    wall_primitive.dimensions[2] = wall_height;  // z dimension (height)

    // Define the wall pose (position & orientation)
    geometry_msgs::Pose wall_pose;
    wall_pose.orientation.w = 1.0;
    wall_pose.position.x = -0.43;  // Setting the wall at -0.43m in x-direction
    wall_pose.position.y = 0.0;
    wall_pose.position.z = wall_height / 2;  // centering the wall in z-direction

    // Add shape and pose to collision object
    wall.primitives.push_back(wall_primitive);
    wall.primitive_poses.push_back(wall_pose);
    wall.operation = wall.ADD;

    // Add wall to collision_objects vector
    collision_objects.push_back(wall);
    ros::Duration(0.5).sleep();


    //add the collision object into the world
    ROS_INFO("Add camera tripods!");
    planning_scene_interface.addCollisionObjects(collision_objects);
    ros::Duration(1.0).sleep();
    //exit
    return 0;
}