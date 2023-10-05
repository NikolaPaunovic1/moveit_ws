#include <ros/ros.h>
#include <my_services/PoseFinderService.h> // Replace with the appropriate service header file
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <moveit_msgs/CollisionObject.h>

class PoseFinderService
{
public:

    using Limits = std::vector<std::vector<double>>;

    geometry_msgs::Pose createPose(double px, double py, double pz, double ox, double oy, double oz, double ow) {
    geometry_msgs::Pose pose;

    pose.position.x = px;
    pose.position.y = py;
    pose.position.z = pz;

    pose.orientation.x = ox;
    pose.orientation.y = oy;
    pose.orientation.z = oz;
    pose.orientation.w = ow;

    return pose;
    }

    PoseFinderService(ros::NodeHandle& nh, moveit::planning_interface::PlanningSceneInterface& planning_scene_interface)
    : planning_scene_interface_(planning_scene_interface)
    {
        //initialize service server
        service_ = nh.advertiseService("pose_finder_service", &PoseFinderService::handleRequest, this);

        //initialize vector with object ids
        for (int j = 0; j < 8; ++j) {object_ids.push_back("Bin" + std::to_string(j+1));}

        //initialize zones to check for place_pose
        Limits zoneLimits = {
            {0.09, 0.30}, // x-axis limits - zone 1
            {0.25, 0.55}, // y-axis limits - zone 1
            {-0.05, 0.15},  // z-axis limits - zone 1
            {0.30, 0.5}, // x-axis limits - zone 2
            {0.25, 0.55}, // y-axis limits - zone 2
            {-0.05, 0.15},  // z-axis limits - zone 2
            {0.5, 0.8}, // x-axis limits - zone 3
            {0.25, 0.55}, // y-axis limits - zone 3
            {-0.05, 0.15}  // z-axis limits - zone 3
        };
        zones["work_area"] = zoneLimits;

        //Declare Origin Poses
        geometry_msgs::Pose pose_id1 = createPose(0.405, -0.31,0.0,0,0,1,0);
        geometry_msgs::Pose pose_id2 = createPose(0.54, -0.08,0.0,0,0,1,0);
        geometry_msgs::Pose pose_id3 = createPose(0.4, 0,0.0,0,0,0,1);
        geometry_msgs::Pose pose_id4 = createPose(0.32, -0.04,0.0,0,0,-0.7071068,0.7071068);
        geometry_msgs::Pose pose_id5 = createPose(0.58, -0.3,0.0,0,0,-0.7071068,0.7071068);
        geometry_msgs::Pose pose_id6 = createPose(0.17, -0.28,0.0,0.081,-0.047,0.972,0.215);
        geometry_msgs::Pose pose_id7 = createPose(0.4, -0.0,0.0,0,0,0,1);
        geometry_msgs::Pose pose_id8 = createPose(0.4, -0.0,0.0,0,0,0,1);

        origin_poses.push_back(pose_id1);
        origin_poses.push_back(pose_id2);
        origin_poses.push_back(pose_id3);
        origin_poses.push_back(pose_id4);
        origin_poses.push_back(pose_id5);
        origin_poses.push_back(pose_id6);
        origin_poses.push_back(pose_id7);
        origin_poses.push_back(pose_id8);

    }

    ros::ServiceServer service_;
    std::vector<std::string> object_ids;
    std::map<std::string, geometry_msgs::Pose> object_poses;
    std::map<std::string, Limits> zones;
    moveit::planning_interface::PlanningSceneInterface& planning_scene_interface_;
    std::vector<geometry_msgs::Pose> origin_poses;

private:

    bool handleRequest(my_services::PoseFinderService::Request& req,
                       my_services::PoseFinderService::Response& res)
    {

        ROS_INFO("Received service request.");

        //If request == "Origin", Then return the object to its initial position
        if(req.location == "origin"){  

            res.place_pose=origin_poses[(req.id-1)];
            return true;

        }

        //read out object poses of the planning_scene
        object_poses = planning_scene_interface_.getObjectPoses(object_ids);

        //helper variable to store the free zone
        int free_zone = 0;

        //check if the requested location was define! If yes: Check which of the zones inside the requested location is free
        if(zones.find(req.location) != zones.end()){
            
            //LOGIC: Iterate through each of the zones and check whether the object poses are inside it. 
            // If no object is inside a zone, then the zone is considered free and an object can be placed there
            //therefore the Response.pose will be assigned with the free zone
            for(int i=0; i< zones[req.location].size(); ++i){

                ROS_INFO("started first loop.");

                bool isInside = false; // helper variable to check if object is inside bowl

                //use an iterator object to iterate through the std::map object
                for (std::map<std::string, geometry_msgs::Pose>::iterator it = object_poses.begin(); it != object_poses.end(); ++it){

                    geometry_msgs::Pose pose = it->second;
                    if (
                        (pose.position.x > zones[req.location][i*3][0] && pose.position.x < zones[req.location][i*3][1]) &&
                        (pose.position.y > zones[req.location][i*3+1][0] && pose.position.y < zones[req.location][i*3+1][1]) &&
                        (pose.position.z > zones[req.location][i*3+2][0] && pose.position.z < zones[req.location][i*3+2][1])
                    ) {
                        isInside = true;
                        break;
                    }
                    
                    else{continue;}
                }
                
                if(!isInside){
                    free_zone = i;
                    break;
                }
            }

            //The resulting place pose is the midpoint of the free zone
            res.place_pose.position.x = (zones[req.location][free_zone*3][0]+zones[req.location][free_zone*3][1])/2;
            res.place_pose.position.y = (zones[req.location][free_zone*3+1][0]+zones[req.location][free_zone*3+1][1])/2;
            res.place_pose.position.z = 0.0;
            res.place_pose.orientation.x =0;
            res.place_pose.orientation.y =0;
            res.place_pose.orientation.z =1;
            res.place_pose.orientation.w =0;

            //place in different orientation if bowl is object to be placed
            if(req.id==6){
            res.place_pose.position.x+=0.01;
            res.place_pose.orientation.x =0;
            res.place_pose.orientation.y =0;
            res.place_pose.orientation.z =0;
            res.place_pose.orientation.w =1;   
            }
        }

        //if the requested location is not available, return False
        else{return false;}

        return true;
    }

};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pose_finder_service_node");
    ros::NodeHandle nh;
    moveit::planning_interface::PlanningSceneInterface psi;

    PoseFinderService pose_finder_service(nh,psi);

    ROS_INFO("Pose finder service is loading.");

    ros::Duration(2.0).sleep();

    ros::spin();

    return 0;
}
