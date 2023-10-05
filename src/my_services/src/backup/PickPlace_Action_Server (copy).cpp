#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <my_services/PickPlaceAction.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <franka_gripper/GraspAction.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>


class PickPlaceAction_Server
{
protected:
 
  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<my_services::PickPlaceAction> as_;
  std::string action_name_;
  my_services::PickPlaceFeedback feedback_;
  my_services::PickPlaceResult result_;


  // PlanningSceneInterface
  moveit::planning_interface::PlanningSceneInterface planning_scene_interface;

  // JointModelGroup
  const moveit::core::JointModelGroup* joint_model_group;

  // Action client for franka_gripper
  actionlib::SimpleActionClient<franka_gripper::GraspAction> client_;

  // tau = 2*PI
  const double tau;

  // MoveGroupInterface instances
  moveit::planning_interface::MoveGroupInterface move_group_interface;
  moveit::planning_interface::MoveGroupInterface gripper_group;



public:
 
  PickPlaceAction_Server(std::string name) :
    as_(nh_, name, boost::bind(&PickPlaceAction_Server::executeCB, this, _1), false),
    action_name_(name),
    tau(2 * M_PI),
    move_group_interface("panda_arm"),
    gripper_group("panda_hand"),
    client_("/franka_gripper/grasp", true)  // Initialize the client in the constructor

  {

    // Initialize JointModelGroup
    // joint_model_group = move_group_interface->getCurrentState()->getJointModelGroup("panda_arm");
    joint_model_group = move_group_interface.getCurrentState()->getJointModelGroup("panda_arm");

    as_.start();
  }
  

  ~PickPlaceAction_Server(void)
  {
  }
 
  void executeCB(const my_services::PickPlaceGoalConstPtr &goal)
  {

  // helper variables
  bool success = true;

  // Feedback info: Action Server Start
  feedback_.info.clear();
  feedback_.info = action_name_ + "has been started!";
  as_.publishFeedback(feedback_);

  //Scan the planning Scene fo Objects -- Preprare helper variables for objects and poses
  std::map<std::string, moveit_msgs::CollisionObject> object_map = planning_scene_interface.getObjects();
  geometry_msgs::Pose my_object_pose;
  moveit_msgs::AttachedCollisionObject attached_object;
  moveit_msgs::CollisionObject my_object;

  //set planning time to 10 second - default = 5

  move_group_interface.setPlanningTime(10.0);
  
  bool found_object = false;

  // Look for object named "Bin"+std::to_string(goal->id)
  std::string object_input = "Bin"+std::to_string(goal->id);

  //helper variable for timeout condition
  int time = 0;
  while(!found_object){
    if (object_map.find(object_input) != object_map.end()) {

        found_object = true;

        my_object = object_map[object_input];

        // You can now access the properties of my_object, such as its shape and pose
        // my_object_pose = my_object.primitive_poses[0];
        std::map<std::string, geometry_msgs::Pose> object_poses = planning_scene_interface.getObjectPoses({object_input});
        my_object_pose = object_poses[object_input];
        // ROS_INFO("The length of the vector primitive poses is: %d", my_object.primitive_poses.size());

        // Print the object pose
        // // shape_msgs::SolidPrimitive my_object_shape = my_object.primitives[0];
        // ROS_INFO("Object pose: x=%f, y=%f, z=%f , ox=%f, oy=%f, oz=%f, ow=%f", my_object_pose.position.x, my_object_pose.position.y, my_object_pose.position.z, 
        // my_object_pose.orientation.x, my_object_pose.orientation.y, my_object_pose.orientation.z, my_object_pose.orientation.w);

        // Create an attached collision object
        attached_object.link_name = "panda_hand"; // replace with your gripper link name
        attached_object.touch_links = std::vector<std::string>{ "panda_hand", "panda_leftfinger", "panda_rightfinger" };
        attached_object.object = my_object;

        // Set operation to add (0=add, 1=remove, 2=append)
        attached_object.object.operation = attached_object.object.ADD;
      }

      ros::Duration(0.01).sleep();
      time += 1;
      //if The object has not been found for a certain amount of time, then exit the function and set the action as failed!
      if (time >= 500){
      feedback_.info = "Object was not found in the scene";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      result_.success = false;  
      as_.setAborted(result_);
      return;
      }
    }

    // publish info to the console for the user
    ROS_INFO("%s: Object to be picked: %i \n Final Pose Position[x,y,z]: %f, %f, %f \n Final Pose Orientation[x,y,z,w]: %f, %f, %f, %f", feedback_.info.c_str(), 
    goal->id, goal->pose.position.x, goal->pose.position.y, goal->pose.position.z, goal->pose.orientation.x, goal->pose.orientation.y, goal->pose.orientation.z, goal->pose.orientation.w);

    ROS_INFO("%s: Object to be picked: %i \n Final Pose Position[x,y,z]: %f, %f, %f \n Final Pose Orientation[x,y,z,w]: %f, %f, %f, %f", feedback_.info.c_str(), 
    goal->id, my_object_pose.position.x, my_object_pose.position.y, my_object_pose.position.z, my_object_pose.orientation.x, my_object_pose.orientation.y, my_object_pose.orientation.z, my_object_pose.orientation.w);
 
    // start executing the action

    // Get the current state so that you can return to it at the end of the demo!
    moveit::core::RobotStatePtr current_state = move_group_interface.getCurrentState();
    std::vector<double> joint_starting_position;
    current_state->copyJointGroupPositions(joint_model_group, joint_starting_position);

    //OPEN GRIPPER--------------------
    gripper_group.setStartState(*gripper_group.getCurrentState());

    std::vector<double> gripper_joints = {0.04, 0.04};
    gripper_group.setJointValueTarget(gripper_joints);
    gripper_group.move();
    feedback_.info = "Gripper opened!";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);

    //Move to Pregrasp pose - 0.1m above the object
    geometry_msgs::Pose target_pose1;
    geometry_msgs::Pose current_pose = move_group_interface.getCurrentPose().pose;

    // Get the current orientation as a quaternion
    geometry_msgs::Quaternion current_orientation = current_pose.orientation;

    //Hardcode grasp
    tf2::Quaternion quat_grasp;
    quat_grasp.setRPY(0, -tau / 2, tau *3/ 8);

    tf2::Quaternion quat_object;
    tf2::fromMsg(my_object_pose.orientation, quat_object);

    // Convert the tf2::Quaternion to rotationmatrices so that calculations can be made
    tf2::Matrix3x3 rot_mat_object(quat_object);
    tf2::Matrix3x3 rot_mat_grasp(quat_grasp);
    //multiply the matrices and convert back to quaternion for valid pose representation
    //correct by 90 degrees because the markers get spawned in +90 degree
    tf2::Quaternion quat_correcting;
    quat_correcting.setRPY(0, 0, tau / 4);
    tf2::Matrix3x3 rot_mat_correcting(quat_correcting);
  
    // tf2::Matrix3x3 rot_mat = rot_mat_grasp * rot_mat_object * rot_mat_correcting;
    tf2::Matrix3x3 rot_mat = rot_mat_object * rot_mat_correcting * rot_mat_grasp ;
    tf2::Quaternion quat_from_rotmat;
    rot_mat.getRotation(quat_from_rotmat);
    target_pose1.orientation = tf2::toMsg(quat_from_rotmat);
    target_pose1.position = my_object_pose.position;
    //ADD OFFSET FROM ENDEFFECTOR LINK TO SURFACE OF THE DETECTED MARKER
    target_pose1.position.z += 0.1+0.07;

    ROS_INFO("the header frame is: %s and Pose.z = %f", attached_object.object.header.frame_id.c_str(),target_pose1.position.z);
    
    // SET THE START AND END POSES -- PLAN TO GRASP LOCATION
    move_group_interface.setStartState(*move_group_interface.getCurrentState());
    move_group_interface.setPoseTarget(target_pose1);

    //PLAN
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

    //EXECUTE THE PLAN
    if(success){
    feedback_.info = "Plan to object was planned successfully";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);
    move_group_interface.move();
    }
    else{
    feedback_.info = "Plan to object failed!";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);
    }

    // Grasp Pose
    geometry_msgs::Pose target_pose1_5 = target_pose1;
    target_pose1_5.position.z -= 0.06;
    move_group_interface.setStartState(*move_group_interface.getCurrentState());
    move_group_interface.setPoseTarget(target_pose1_5);
    success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    if(success){
    feedback_.info = "Plan to grasp pose was planned successfully";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);
    move_group_interface.move();
    }

    //INITIALIZE THE ACTION CLIENT FOR GRIPPING-------------
    ROS_INFO("Waiting for Grasp action server to start.");
    client_.waitForServer();

    gripper_joints = {0.03, 0.03};
    //+++++++++++++++++++++++++++++++
    // gripper_joints = {0.011, 0.011};
    gripper_group.setJointValueTarget(gripper_joints);
    gripper_group.move();
    feedback_.info = "close the gripper a bit";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);
    ros::Duration(1.0).sleep();

    // Creates a goal to send to the action server.
    franka_gripper::GraspGoal grip_goal;
    grip_goal.width = 0.05;
    grip_goal.epsilon.inner = 0.005;
    grip_goal.epsilon.outer = 0.005;
    grip_goal.speed = 0.1;
    grip_goal.force = 20;

    ROS_INFO("Grasping Object!");
    client_.sendGoal(grip_goal);

    // Attach the object to the robot
    planning_scene_interface.applyAttachedCollisionObject(attached_object);

    // PLAN TO GOAL POSE---------------------------------------------------------------

    //DEFINE THE GOAL POSE
    tf2::Quaternion quat_goal;
    tf2::fromMsg(goal->pose.orientation, quat_goal);
    tf2::Matrix3x3 rot_mat_goal(quat_goal);
    rot_mat_goal = rot_mat_goal * rot_mat_grasp;
    rot_mat_goal.getRotation(quat_goal);
    geometry_msgs::Pose target_pose2;
    target_pose2.orientation = tf2::toMsg(quat_goal);
    // target_pose2.position.x = 0.5;
    // target_pose2.position.y = 0.4;

    // //Object height was determined before
    // target_pose2.position.z = my_object_pose.position.z + 0.1+ 0.032;
    //++++++++++++++++++++++++++++++++++++++++++++++

    target_pose2.position.x = goal->pose.position.x;
    target_pose2.position.y = goal->pose.position.y;
    target_pose2.position.z = goal->pose.position.z + 0.1;

    //PLAN AND MOVE TO THE GOAL POSE
    move_group_interface.setStartState(*move_group_interface.getCurrentState());
    move_group_interface.setPoseTarget(target_pose2);
    success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    if(success){    
      feedback_.info = "Plan to Final Pose was planned successfully";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      
      //EXECUTE THE PLAN
      move_group_interface.move();
      // move_group_interface.execute(my_plan);
    }
    else{
      feedback_.info = "Plan to Final Pose failed!";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
    }
    //stop grasp
    client_.cancelGoal();

    //OPEN GRIPPER---------------------------
    gripper_joints = {0.04, 0.04};
    gripper_group.setJointValueTarget(gripper_joints);
    gripper_group.move();

    //DETACH OBJECT-------
    move_group_interface.detachObject(attached_object.object.id);
    feedback_.info = "Object was placed successfully";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);

    // // Post Grasp Retreat
    // target_pose2.position.z += 0.15;
    // move_group_interface.setStartState(*move_group_interface.getCurrentState());
    // move_group_interface.setPoseTarget(target_pose2);
    // success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    // if(success){
    // feedback_.info = "Post grasp retreat was planned successfully";
    // ROS_INFO("%s", feedback_.info.c_str());
    // as_.publishFeedback(feedback_);
    // move_group_interface.move();
    // }

    move_group_interface.setStartState(*move_group_interface.getCurrentState());
    move_group_interface.setJointValueTarget(joint_starting_position);

    success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

    if(success){
      feedback_.info = "Plan to initial pose was successfully";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);


      // move_group_interface.execute(my_plan);
      move_group_interface.move();
    }
    else{
      feedback_.info = "Plan to initial Pose failed";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
    }

 
    if(success)
    {
      feedback_.info = action_name_ + "succeeded!";
      as_.publishFeedback(feedback_);
      result_.success = success;
      // set the action state to succeeded
      as_.setSucceeded(result_);
    }
  }
 
 
};
 
 
int main(int argc, char** argv)
{
  ros::init(argc, argv, "PickPlace_Action_Server");

  ros::AsyncSpinner spinner(1);
  spinner.start();

  PickPlaceAction_Server PickPlace_Action("PickPlace_Action");

   while(ros::ok())
  {
    // Do nothing. This just keeps your node from exiting.
    // Add a sleep if you want to reduce CPU usage.
    ros::Duration(0.01).sleep();
  }
  return 0;
}