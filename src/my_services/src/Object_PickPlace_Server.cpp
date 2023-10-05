#include <ros/ros.h>
#include <actionlib/server/simple_action_server.h>
#include <my_services/PickPlaceAction.h>
#include <moveit/move_group_interface/move_group_interface.h>
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <franka_gripper/GraspAction.h>
#include <moveit_msgs/AttachedCollisionObject.h>
#include <moveit_msgs/CollisionObject.h>

//struct containing necessary information to grasp an object
struct grasp_data
{
    tf2::Transform pregrasp_pose;
    tf2::Transform place_pose;
    float gripper_width;
};

class PickPlaceAction_Server
{
protected:
 
  ros::NodeHandle nh_;
  actionlib::SimpleActionServer<my_services::PickPlaceAction> as_;
  std::string action_name_;
  my_services::PickPlaceFeedback feedback_;
  my_services::PickPlaceResult result_;
  std::vector<grasp_data> grasp_dictionary;

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

  //default_pose
  std::vector<double> default_joint_position;

public:
  // Initialize action server
  PickPlaceAction_Server(std::string name) :
    as_(nh_, name, boost::bind(&PickPlaceAction_Server::executeCB, this, _1), false),
    action_name_(name),
    tau(2 * M_PI),
    move_group_interface("panda_arm"),
    gripper_group("panda_hand"),
    client_("/franka_gripper/grasp", true)  // Initialize the client in the constructor
  {
    // Initialize JointModelGroup
    joint_model_group = move_group_interface.getCurrentState()->getJointModelGroup("panda_arm");
    //Initialize defualt_joint_position
    default_joint_position= {0.0, -tau/8, 0.0, -(3.0/8.0) * tau, 0.0, tau/4, tau/8};


    //define your grasp dictionary - grasp info for each of the objects!

    //grasp_data for object_id=1
    grasp_dictionary.push_back(create_grasp_data(0, -tau / 2, tau * 5 / 8, 0.0, 0.0, 0.13, 0.0, 0.0, -tau / 4, 0, 0, 0.18, 0.05));
    // object_id=2 is equal to object_id=1
    grasp_dictionary.push_back(grasp_dictionary[0]); 
    // grasp data for bowl (id=3)
    grasp_dictionary.push_back(create_grasp_data(0, -tau / 2, tau * 5 / 8, -0.035, 0.0, 0.2, 0.0, 0.0, -tau / 4, 0.085, 0.0, 0.22, 0.013));
    // grasp data for cuttingboard (id=4)
    grasp_dictionary.push_back(create_grasp_data(0, -tau / 2, tau * 5 / 8, -0.045, 0, 0.185, 0.0, 0.0, -tau / 4, 0.085, -0.085, 0.17, 0.003));
    //object_id=5 is equal to object_id=1
    grasp_dictionary.push_back(grasp_dictionary[0]);  

    //start actionserver
    as_.start();
  }

  ~PickPlaceAction_Server(void)
  {
  }
    grasp_data create_grasp_data(double roll1, double pitch1, double yaw1, 
                                double x1, double y1, double z1, 
                                double roll2, double pitch2, double yaw2, 
                                double x2, double y2, double z2, 
                                double gripper_width) 
    {
        grasp_data object;
        tf2::Quaternion quat_grasp, correct_grasp;
        quat_grasp.setRPY(roll1, pitch1, yaw1);
        correct_grasp.setRPY(roll2, pitch2, yaw2);

        tf2::Matrix3x3 rot_mat_grasp(quat_grasp), correct_mat(correct_grasp);
        tf2::Matrix3x3 rot_mat_place(correct_mat * rot_mat_grasp);

        tf2::Vector3 translation_grasp(x1, y1, z1), translation_place(x2, y2, z2);

        tf2::Transform pregrasp_pose_(rot_mat_grasp, translation_grasp);
        tf2::Transform place_pose_(rot_mat_place, translation_place);

        object.pregrasp_pose = pregrasp_pose_;
        object.place_pose = place_pose_;
        object.gripper_width = gripper_width;

        return object;
    }

    geometry_msgs::Pose calculate_target_pose(const geometry_msgs::Pose& input_pose,tf2::Transform goal_place_pose) {
      tf2::Quaternion quat_goal;
      tf2::fromMsg(input_pose.orientation, quat_goal);
      tf2::Matrix3x3 rot_mat_goal(quat_goal);
      tf2::Vector3 translation_goal(input_pose.position.x, input_pose.position.y, input_pose.position.z);
      tf2::Transform T_goal(rot_mat_goal, translation_goal);

      geometry_msgs::Pose target_pose;
      tf2::Transform T_place = T_goal * goal_place_pose;
      target_pose.position.x = T_place.getOrigin().getX();
      target_pose.position.y = T_place.getOrigin().getY();
      target_pose.position.z = T_place.getOrigin().getZ();
      target_pose.orientation = tf2::toMsg(T_place.getRotation());

      return target_pose;
  }

  //function which plans back to default pose - will be called either when end is reached or when error occured
  void return_backto_default(bool end_reached){
    //plan and move to initial pose
    move_group_interface.setStartState(*move_group_interface.getCurrentState());
    move_group_interface.setJointValueTarget(default_joint_position);

    //if plan to initial pose succeeds --> move to initial pose
    moveit::planning_interface::MoveGroupInterface::Plan plan_back;
    if(move_group_interface.plan(plan_back) == moveit::planning_interface::MoveItErrorCode::SUCCESS){

      //if move action was conducted correctly, return 
      if(move_group_interface.move() == moveit::planning_interface::MoveItErrorCode::SUCCESS){

        //if the function was not called due to an error but due to end of action - publsih feedback
        if(end_reached){
          feedback_.info = "Plan to initial pose was successfull";
          ROS_INFO("%s", feedback_.info.c_str());
          as_.publishFeedback(feedback_);
        }
        else{
          as_.setAborted(result_);
        }
      }
      else{
        feedback_.info += "AND plan to initial pose failed!";
        ROS_INFO("%s", feedback_.info.c_str());
        as_.publishFeedback(feedback_);
        as_.setAborted(result_);
      }
    }
    else{
      feedback_.info += "AND plan to initial pose failed!";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      as_.setAborted(result_);
      return;
    }
  }

  void executeCB(const my_services::PickPlaceGoalConstPtr &goal)
  {

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

  //Look for object of interest (goal->id) - Logic:
  //Iterate through the found object and if the object of interest was found, store its pose and initialize the attachedCollisionObject for pick and place tasks
  //If object was not found in a certain amount of time -> ABORT
  bool found_object = false;
  std::string object_input = "Bin"+std::to_string(goal->id);
  int time = 0;
  while(!found_object){
    if (object_map.find(object_input) != object_map.end()) {
        found_object = true;
        my_object = object_map[object_input];
        std::map<std::string, geometry_msgs::Pose> object_poses = planning_scene_interface.getObjectPoses({object_input});
        my_object_pose = object_poses[object_input];
        attached_object.link_name = "panda_hand"; // replace with your gripper link name
        attached_object.touch_links = std::vector<std::string>{ "panda_hand", "panda_leftfinger", "panda_rightfinger" };
        attached_object.object = my_object;
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
    
    // EXECUTE ACTION----------------------------------------

    // Get the current state so that you can return to it at the end of the script!
    moveit::core::RobotStatePtr current_state = move_group_interface.getCurrentState();
    std::vector<double> joint_starting_position;
    current_state->copyJointGroupPositions(joint_model_group, joint_starting_position);

    //open gripper and update feedback
    gripper_group.setStartState(*gripper_group.getCurrentState());
    std::vector<double> gripper_joints = {0.038, 0.038};
    gripper_group.setJointValueTarget(gripper_joints);

    //if gripper failed to open return!
    if(gripper_group.move()==moveit::planning_interface::MoveItErrorCode::SUCCESS){
      feedback_.info = "Gripper opened!";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
    }
    else{
      feedback_.info = "Gripper failed to open!";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      result_.success = false;  
      as_.setAborted(result_);
      return;
    }

    //Initialize Object Pose
    tf2::Quaternion quat_object;
    tf2::fromMsg(my_object_pose.orientation, quat_object);
    tf2::Matrix3x3 rot_mat_object(quat_object);
    tf2::Vector3 translation_object(my_object_pose.position.x, my_object_pose.position.y, my_object_pose.position.z);
    tf2::Transform T_object(rot_mat_object, translation_object);

    //Multiply pregrasp pose from dictionary with object Pose to define the PoseTarget
    geometry_msgs::Pose target_pose1;
    tf2::Transform T_pregrasp = T_object * grasp_dictionary[(goal->id-1)].pregrasp_pose;
    target_pose1.position.x = T_pregrasp.getOrigin().getX();
    target_pose1.position.y = T_pregrasp.getOrigin().getY();
    target_pose1.position.z = T_pregrasp.getOrigin().getZ();
    target_pose1.orientation = tf2::toMsg(T_pregrasp.getRotation());

    // Set PoseTarget and compute the plan
    move_group_interface.setStartState(*move_group_interface.getCurrentState());
    move_group_interface.setPoseTarget(target_pose1);
    bool success = true;
    moveit::planning_interface::MoveGroupInterface::Plan my_plan;
    success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);

    //If valid plan could be found -> execute trajecotry
    if(success){
    feedback_.info = "Plan to pregrasp pose was planned successfully";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);

      //check if movement could be executed successfully - return to default pose if failed!
      if(move_group_interface.move() == moveit::planning_interface::MoveItErrorCode::SUCCESS){
        feedback_.info = "Endeffector successfully moved to pregrasp pose!";
        ROS_INFO("%s", feedback_.info.c_str());
        as_.publishFeedback(feedback_);
      }
      else{
        feedback_.info = "Endeffector failed to moved to pregrasp pose!";
        ROS_INFO("%s", feedback_.info.c_str());
        as_.publishFeedback(feedback_);
        return_backto_default(0);
        return;
      }
    }
    else{
      feedback_.info = "Plan to pregrasp pose failed!";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      as_.setAborted(result_);
      return;
    }

    // Plan to graspPose and execute if plan was successfull
    geometry_msgs::Pose target_pose1_5 = target_pose1;
    target_pose1_5.position.z -= 0.05;
    move_group_interface.setStartState(*move_group_interface.getCurrentState());
    move_group_interface.setPoseTarget(target_pose1_5);
    success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    if(success){
      feedback_.info = "Plan to grasp pose was planned successfully";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);

      //check if movement could be executed successfully - return to default pose if failed!
      if(move_group_interface.move() == moveit::planning_interface::MoveItErrorCode::SUCCESS){
        feedback_.info = "Endeffector successfully moved to pregrasp pose!";
        ROS_INFO("%s", feedback_.info.c_str());
        as_.publishFeedback(feedback_);
      }
      else{
        feedback_.info = "Endeffector failed to moved to pregrasp pose!";
        ROS_INFO("%s", feedback_.info.c_str());
        as_.publishFeedback(feedback_);
        return_backto_default(0);
        return;
      }
    }
    else{
      feedback_.info = "Plan to grasp pose failed!";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      return_backto_default(0);
      return;
    }

    //Wait for action server - close the gripper a bit if action is ready to be executed
    ROS_INFO("Waiting for Grasp action server to start.");
    client_.waitForServer();
    gripper_group.setStartState(*gripper_group.getCurrentState());
    float openwidth = (grasp_dictionary[(goal->id)-1].gripper_width/2) + 0.01;
    gripper_joints = {openwidth, openwidth};
    gripper_group.setJointValueTarget(gripper_joints);

    //check if gripper could be closed successfully and abort action if this is not the case
    if(gripper_group.move() != moveit::planning_interface::MoveItErrorCode::SUCCESS){
      feedback_.info = "Tried to close the gripper and failed!";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      return_backto_default(0);
      return;
    }
    feedback_.info = "close the gripper a bit";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);


    // Attach the object to the robot after it was grasped
    planning_scene_interface.applyAttachedCollisionObject(attached_object);

    ros::Duration(1.0).sleep();


    // Initialize goal for the GraspAction and send to the GraspActionServer
    // set gripper width from grasp dictionary
    franka_gripper::GraspGoal grip_goal;
    grip_goal.width = grasp_dictionary[(goal->id-1)].gripper_width;
    grip_goal.epsilon.inner = 0.005;
    grip_goal.epsilon.outer = 0.005;
    grip_goal.speed = 0.1;
    grip_goal.force = 80;

    feedback_.info = "Grasping Object!";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);
    client_.sendGoal(grip_goal);

    ros::Duration(1.0).sleep();

  //Compute desired endeffector pose
    //Compute transform of the input goal pose
    //plan and move to the goal pose if plan succeeded
    move_group_interface.setStartState(*move_group_interface.getCurrentState());
    geometry_msgs::Pose target_pose2 = calculate_target_pose(goal->pose, grasp_dictionary[(goal->id-1)].place_pose);
    move_group_interface.setPoseTarget(target_pose2);
    success = (move_group_interface.plan(my_plan) == moveit::planning_interface::MoveItErrorCode::SUCCESS);
    if(success){    
      feedback_.info = "Plan to Final Pose was planned successfully";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      
      std::string input;
      moveit::core::MoveItErrorCode result_m;

      do {
          // Update the robot state
          move_group_interface.setStartState(*move_group_interface.getCurrentState());

          // Plan and execute the movement
          result_m = move_group_interface.move();

          if(result_m != moveit::planning_interface::MoveItErrorCode::SUCCESS) {
              // Request user input
              ROS_INFO("Keep trying? (y/n): ");
              std::cin >> input;
              ros::Duration(0.1).sleep();

              // Process user input
              if(input == "n") {
                  // Inform user
                  ROS_INFO("Please put your hand under the end effector and press 'enter' to release the object");
                  // Wait for user to press 'enter'
                  std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                  std::cin.get();

                  // Release object
                  client_.cancelGoal();
                  gripper_joints = {0.04, 0.04};
                  gripper_group.setJointValueTarget(gripper_joints);
                  //-----maybe set if clause here as well to check if movement has been executed correctly
                  gripper_group.move();
                  move_group_interface.detachObject(attached_object.object.id);

                  // Sleep for a couple of seconds after the object was released and then return to default pose
                  ros::Duration(2.0).sleep();
                  return_backto_default(0);
                  return;
              }
              else if(input == "y"){
                //if user presses yes, ask him for a new pose
                  ROS_INFO("Please enter the new pose (x, y, z, qx, qy, qz, qw): ");
                  geometry_msgs::Pose new_pose;
                  std::cin >> new_pose.position.x >> new_pose.position.y >> new_pose.position.z
                          >> new_pose.orientation.x >> new_pose.orientation.y >> new_pose.orientation.z >> new_pose.orientation.w;
                  //calculate new endeffector pose based on user input
                  target_pose2 = calculate_target_pose(new_pose, grasp_dictionary[(goal->id-1)].place_pose);
                  move_group_interface.setPoseTarget(target_pose2);
              }
              else {
                  while(input != "y" && input != "n"){
                      ROS_WARN("Invalid input. Please enter 'y' or 'n': ");
                      std::cin >> input;
                  }
              }
          }
      } while(result_m != moveit::planning_interface::MoveItErrorCode::SUCCESS && input != "n");


    }
    else{
      feedback_.info = "Plan to Final Pose failed!";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      client_.cancelGoal();    
      gripper_joints = {0.039, 0.039};
      gripper_group.setJointValueTarget(gripper_joints);
      gripper_group.move();
      move_group_interface.detachObject(attached_object.object.id);
      return_backto_default(0);
      return;
    }
    //stop grasp
    client_.cancelGoal();

    //open gripper
    gripper_joints = {0.039, 0.039};
    gripper_group.setJointValueTarget(gripper_joints);
    if(gripper_group.move() != moveit::planning_interface::MoveItErrorCode::SUCCESS){
      feedback_.info = "Tried to open the gripper and failed!";
      ROS_INFO("%s", feedback_.info.c_str());
      as_.publishFeedback(feedback_);
      return_backto_default(0);
      return;
    }

    //detach object
    move_group_interface.detachObject(attached_object.object.id);
    feedback_.info = "Object was placed successfully";
    ROS_INFO("%s", feedback_.info.c_str());
    as_.publishFeedback(feedback_);

    //return back to default pose
    return_backto_default(true);

    //If no fail was detected --> set Action as succeeded
    result_.success = success;
    if(success)
    {
      feedback_.info = action_name_ + "succeeded!";
      as_.publishFeedback(feedback_);
      // set the action state to succeeded
      as_.setSucceeded(result_);
    }
    else{
      // set the action state to failed
      as_.setAborted(result_);
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
    // add a sleep if you want to reduce CPU usage
    ros::Duration(0.01).sleep();
  }
  return 0;
}