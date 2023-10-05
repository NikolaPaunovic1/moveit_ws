// #include <ros/ros.h>
// #include <sensor_msgs/PointCloud2.h>
// #include <my_services/ObjectPositionService.h> // Replace with the appropriate service header file
// #include <moveit/planning_scene_interface/planning_scene_interface.h>
// #include <tf2_geometry_msgs/tf2_geometry_msgs.h>
// #include <pcl_conversions/pcl_conversions.h>
// #include <pcl/filters/passthrough.h>
// #include <pcl/filters/extract_indices.h>
// #include <pcl/features/normal_3d.h>
// #include <pcl/segmentation/sac_segmentation.h>
// #include <moveit_msgs/CollisionObject.h>

// class ObjectDetectionService
// {
// public:
//     ObjectDetectionService(ros::NodeHandle& nh, moveit::planning_interface::PlanningSceneInterface& planning_scene_interface)
//         : pointcloud_(new sensor_msgs::PointCloud2),
//           cloud(new pcl::PointCloud<pcl::PointXYZ>),
//           cloud_normals(new pcl::PointCloud<pcl::Normal>),
//           tree(new pcl::search::KdTree<pcl::PointXYZ>()),
//           inliers_plane(new pcl::PointIndices),
//           coefficients_plane(new pcl::ModelCoefficients)
//     {
//         pointcloud_sub_ = nh.subscribe("/camera3/depth/points", 1, &ObjectDetectionService::pointCloudCallback, this);
//         service_ = nh.advertiseService("object_position_service", &ObjectDetectionService::handleRequest, this);
//         cloud_pub_ = nh.advertise<sensor_msgs::PointCloud2>("/camera4/depth/points", 1);
//     }

//     sensor_msgs::PointCloud2::ConstPtr pointcloud_;
//     ros::Subscriber pointcloud_sub_;
//     ros::Publisher cloud_pub_;
//     ros::ServiceServer service_;

//     pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
//     pcl::PointCloud<pcl::Normal>::Ptr cloud_normals;
//     pcl::search::KdTree<pcl::PointXYZ>::Ptr tree;
//     pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
//     pcl::PassThrough<pcl::PointXYZ> pass;
//     pcl::PointIndices::Ptr inliers_plane;
//     pcl::SACSegmentation<pcl::PointXYZ> segmentor;
//     pcl::ModelCoefficients::Ptr coefficients_plane;
//     pcl::ExtractIndices<pcl::PointXYZ> extract_indices;
// private:
//     void pointCloudCallback(const sensor_msgs::PointCloud2::ConstPtr& msg)
//     {
//         //ROS_INFO("The Pointcloud was received!");
//         pointcloud_ = msg;
//     }

//     bool handleRequest(my_services::ObjectPositionService::Request& req,
//                        my_services::ObjectPositionService::Response& res)
//     {
//         if (!pointcloud_ || pointcloud_->data.empty() || req.shape_name != "square"){
//                 if (!pointcloud_)
//                     ROS_WARN("The pointcloud is a 0-Pointer");
//                 if (pointcloud_->data.empty())
//                     ROS_WARN("The pointcloud is empty");
//                 if (req.shape_name != "square")
//                     ROS_WARN_STREAM("The requested shape is not 'square': " << req.shape_name);
//                 return false;
//             }

//         std::string frame_id = pointcloud_->header.frame_id;
//         ROS_INFO_STREAM("Point cloud frame_id: " << frame_id);
//         //----------------------------------------------------------------------
//         //TODO - IMPLEMENT OBJECT DETECTION
//         //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

//         //CONVERT POINTCLOUD TO PCL OBJECT
//         pcl::fromROSMsg(*pointcloud_, *cloud);

//         ROS_INFO("start passthroughfilter!");

//         //PASSTHROUGH FILTER --------
//         pass.setInputCloud(cloud);
//         pass.setFilterFieldName("z");
//         // min and max values in z axis to keep
//         pass.setFilterLimits(0.96, 1.15);
//         pass.filter(*cloud);

//         ROS_INFO("start normal computation!");
//         //COMPUTE NORMALS------------------
//         ne.setSearchMethod(tree);
//         ne.setInputCloud(cloud);
//         // Set the number of k nearest neighbors to use for the feature estimation.
//         ne.setKSearch(50);
//         ne.compute(*cloud_normals);

//         ROS_INFO("start planesurface removal!");
//         //REMOVE THE PLANE SURFACE---------------------------------
//         segmentor.setOptimizeCoefficients(true);
//         segmentor.setModelType(pcl::SACMODEL_PLANE);
//         segmentor.setMethodType(pcl::SAC_RANSAC);
//         /* run at max 1000 iterations before giving up */
//         segmentor.setMaxIterations(1000);
//         /* tolerance for variation from model */
//         segmentor.setDistanceThreshold(0.01);
//         segmentor.setInputCloud(cloud);
//         /* Create the segmentation object for the planar model and set all the parameters */
//         segmentor.segment(*inliers_plane, *coefficients_plane);
//         /* Extract the planar inliers from the input cloud */
//         extract_indices.setInputCloud(cloud);
//         extract_indices.setIndices(inliers_plane);
//         /* Remove the planar inliers, extract the rest */
//         extract_indices.setNegative(true);
//         extract_indices.filter(*cloud);
        
//         // //EXTRACT BOX---------------------------
//         // // Create the segmentation object for BOX segmentation and set all the parameters
//         // pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> box_segmentor;
//         // pcl::PointIndices::Ptr inliers_cylinder(new pcl::PointIndices);
//         // box_segmentor.setOptimizeCoefficients(true);
//         // box_segmentor.setModelType(pcl::SACMODEL_STICK);
//         // box_segmentor.setMethodType(pcl::SAC_RANSAC);
//         // // Set the normal angular distance weight
//         // box_segmentor.setNormalDistanceWeight(0.1);
//         // // run at max 1000 iterations before giving up
//         // box_segmentor.setMaxIterations(1000);
//         // // tolerance for variation from model
//         // box_segmentor.setDistanceThreshold(0.008);
//         // // min max values of radius in meters to consider
//         // box_segmentor.setRadiusLimits(0.01, 0.1);
//         // box_segmentor.setInputCloud(cloud);
//         // box_segmentor.setInputNormals(cloud_normals);

//         // // Obtain the box inliers and coefficients
//         // box_segmentor.segment(*inliers_cylinder, *coefficients_cylinder);

//         // // Extract the box inliers from the input cloud
//         // pcl::ExtractIndices<pcl::PointXYZ> extract;
//         // extract.setInputCloud(cloud);
//         // extract.setIndices(inliers_cylinder);
//         // extract.setNegative(false);
//         // extract.filter(*cloud);

//         // //START INITIALIZING MODEL COEFFICIENTS-------------
//         // if (cloud->points.empty() || coefficients_cylinder->values.size() != 7)
//         // {
//         // ROS_ERROR_STREAM_NAMED("cylinder_segment", "Can't find the cylindrical component.");
//         // return;
//         // }

//         // ROS_INFO("Detected Cylinder - Adding CollisionObject to PlanningScene");

//         // /* Store the radius of the cylinder. */
//         // cylinder_params.radius = coefficients_cylinder->values[6];
//         // /* Store direction vector of z-axis of box. */
//         // cylinder_params.direction_vec[0] = coefficients_cylinder->values[3];
//         // cylinder_params.direction_vec[1] = coefficients_cylinder->values[4];
//         // cylinder_params.direction_vec[2] = coefficients_cylinder->values[5];

//         // //TEST THE FILTERED POINTCLOUD BY PUBLISHING A TOPIC
//         // ROS_INFO("Start publishing!");
//         // sensor_msgs::PointCloud2 testcloud;
//         // pcl::toROSMsg(*cloud, testcloud);
//         // cloud_pub_.publish(testcloud);
//         //----------------------------------------------------------------------
//         // SET OBJECT POSE
//         geometry_msgs::Pose target_pose;

//         ROS_INFO("print out orientation!");
//         tf2::Quaternion orientation;
//         orientation.setRPY(0, -(2 * M_PI) / 2, (2 * M_PI) *3/ 8);
//         target_pose.orientation = tf2::toMsg(orientation);;
//         // target_pose1.position.x = 0.5;
//         // target_pose1.position.y = 0.0;
//         // target_pose1.position.z = 0.515;
//         //+++++++++++++++++++++++++++++++
//         target_pose.position.x = 0.51;
//         target_pose.position.y = 0.0;
//         target_pose.position.z = 0.515+0.022+0.036;

//         res.object_pose = target_pose;
//     }

// };

// int main(int argc, char** argv)
// {
//     ros::init(argc, argv, "object_detection_service_node");
//     ros::NodeHandle nh;
//     moveit::planning_interface::PlanningSceneInterface psi;

//     ObjectDetectionService object_detection_service(nh,psi);

//     ROS_INFO("Object detection service is loading.");

//     ros::Duration(2.0).sleep();
//     ros::Rate rate(1);

//     while(!object_detection_service.pointcloud_){

//         ROS_WARN("Point cloud is not available yet.");
//         ros::spinOnce();
//         rate.sleep();
//     }
//     ROS_INFO("Server is ready!");

//     ros::spin();

//     return 0;
// }


#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <my_services/ObjectPositionService.h> // Replace with the appropriate service header file
#include <moveit/planning_scene_interface/planning_scene_interface.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/features/normal_3d.h>
#include <pcl/segmentation/sac_segmentation.h>
#include <moveit_msgs/CollisionObject.h>

class ObjectDetectionService
{
public:
    ObjectDetectionService(ros::NodeHandle& nh, moveit::planning_interface::PlanningSceneInterface& planning_scene_interface)
        : pointcloud_(new sensor_msgs::PointCloud2),
          cloud(new pcl::PointCloud<pcl::PointXYZ>),
          cloud_normals(new pcl::PointCloud<pcl::Normal>),
          tree(new pcl::search::KdTree<pcl::PointXYZ>()),
          inliers_plane(new pcl::PointIndices),
          coefficients_plane(new pcl::ModelCoefficients)
    {
        pointcloud_sub_ = nh.subscribe("/camera3/depth/points", 1, &ObjectDetectionService::pointCloudCallback, this);
        service_ = nh.advertiseService("object_position_service", &ObjectDetectionService::handleRequest, this);
        cloud_pub_ = nh.advertise<sensor_msgs::PointCloud2>("/camera4/depth/points", 1);
    }

    sensor_msgs::PointCloud2::ConstPtr pointcloud_;
    ros::Subscriber pointcloud_sub_;
    ros::Publisher cloud_pub_;
    ros::ServiceServer service_;

    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    pcl::PointCloud<pcl::Normal>::Ptr cloud_normals;
    pcl::search::KdTree<pcl::PointXYZ>::Ptr tree;
    pcl::NormalEstimation<pcl::PointXYZ, pcl::Normal> ne;
    pcl::PassThrough<pcl::PointXYZ> pass;
    pcl::PointIndices::Ptr inliers_plane;
    pcl::SACSegmentation<pcl::PointXYZ> segmentor;
    pcl::ModelCoefficients::Ptr coefficients_plane;
    pcl::ExtractIndices<pcl::PointXYZ> extract_indices;

private:
    void pointCloudCallback(const sensor_msgs::PointCloud2::ConstPtr& msg)
    {
        pointcloud_ = msg;
    }

    bool handleRequest(my_services::ObjectPositionService::Request& req,
                       my_services::ObjectPositionService::Response& res)
    {
        if (pointcloud_->data.empty() || req.shape_name != "square")
        {
            return false;
        }

        std::string frame_id = pointcloud_->header.frame_id;
        ROS_INFO_STREAM("Point cloud frame_id: " << frame_id);
        //----------------------------------------------------------------------
        //TODO - IMPLEMENT OBJECT DETECTION
        //^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^

        //CONVERT POINTCLOUD TO PCL OBJECT
        pcl::fromROSMsg(*pointcloud_, *cloud);


        ROS_INFO("Start passthroughfilter!");
        //PASSTHROUGH FILTER --------
        pass.setInputCloud(cloud);
        pass.setFilterFieldName("z");
        // min and max values in z axis to keep
        pass.setFilterLimits(1.0, 1.15);
        pass.filter(*cloud);

        pcl::PassThrough<pcl::PointXYZ> pass_y;
        pass_y.setInputCloud(cloud);
        pass_y.setFilterFieldName("y");
        // min and max values in y axis to keep
        pass_y.setFilterLimits(-0.2, 0.2); // Replace these values with the desired limits for the y-axis
        pass_y.filter(*cloud);

        pcl::PassThrough<pcl::PointXYZ> pass_x;
        pass_x.setInputCloud(cloud);
        pass_x.setFilterFieldName("x");
        // min and max values in y axis to keep
        pass_x.setFilterLimits(-0.2, 0.2); // Replace these values with the desired limits for the y-axis
        pass_x.filter(*cloud);

        ROS_INFO("Start normal_computer!");
        //COMPUTE NORMALS
        ne.setSearchMethod(tree);
        ne.setInputCloud(cloud);
        // Set the number of k nearest neighbors to use for the feature estimation.
        ne.setKSearch(50);
        ne.compute(*cloud_normals);

        ROS_INFO("Start plane remover!");
        //REMOVE THE PLANE SURFACE
        segmentor.setOptimizeCoefficients(true);
        segmentor.setModelType(pcl::SACMODEL_PLANE);
        segmentor.setMethodType(pcl::SAC_RANSAC);
        /* run at max 1000 iterations before giving up */
        segmentor.setMaxIterations(1000);
        /* tolerance for variation from model */
        segmentor.setDistanceThreshold(0.01);
        segmentor.setInputCloud(cloud);
        /* Create the segmentation object for the planar model and set all the parameters */
        ROS_INFO("Start Segmentor!");
        segmentor.segment(*inliers_plane, *coefficients_plane);
        /* Extract the planar inliers from the input cloud */
        extract_indices.setInputCloud(cloud);
        extract_indices.setIndices(inliers_plane);
        /* Remove the planar inliers, extract the rest */
        extract_indices.setNegative(true);
        extract_indices.filter(*cloud);

        //EXTRACT NORMALS------------------------------
        pcl::ExtractIndices<pcl::Normal> extract_normals;
        extract_normals.setNegative(true);
        extract_normals.setInputCloud(cloud_normals);
        extract_normals.setIndices(inliers_plane);
        extract_normals.filter(*cloud_normals);
        //EXTRACT OBJECT--------------------------
        //EXTRACT BOX---------------------------
        // Create the segmentation object for BOX segmentation and set all the parameters
        pcl::ModelCoefficients::Ptr coefficients_cylinder(new pcl::ModelCoefficients);
        pcl::SACSegmentationFromNormals<pcl::PointXYZ, pcl::Normal> box_segmentor;
        pcl::PointIndices::Ptr inliers_cylinder(new pcl::PointIndices);
        box_segmentor.setOptimizeCoefficients(true);
        box_segmentor.setModelType(pcl::SACMODEL_CYLINDER);
        box_segmentor.setMethodType(pcl::SAC_RANSAC);
        // Set the normal angular distance weight
        box_segmentor.setNormalDistanceWeight(0.1);
        // run at max 1000 iterations before giving up
        box_segmentor.setMaxIterations(1000);
        // tolerance for variation from model
        box_segmentor.setDistanceThreshold(0.008);
        // min max values of radius in meters to consider
        box_segmentor.setRadiusLimits(0.01, 0.1);
        box_segmentor.setInputCloud(cloud);
        box_segmentor.setInputNormals(cloud_normals);

        // Obtain the box inliers and coefficients
        box_segmentor.segment(*inliers_cylinder, *coefficients_cylinder);

        // Extract the box inliers from the input cloud
        pcl::ExtractIndices<pcl::PointXYZ> extract;
        extract.setInputCloud(cloud);
        extract.setIndices(inliers_cylinder);
        extract.setNegative(false);
        extract.filter(*cloud);

        /////////////////////////////////////////////////////////////////////

    //     //START INITIALIZING MODEL COEFFICIENTS-------------
    //     if (cloud->points.empty() || coefficients_cylinder->values.size() != 7)
    //     {
    //     ROS_ERROR_STREAM_NAMED("cylinder_segment", "Can't find the cylindrical component.");
    //     return;
    //     }

    //     ROS_INFO("Detected Cylinder - Adding CollisionObject to PlanningScene");

    //     /* Store the radius of the cylinder. */
    //     cylinder_params.radius = coefficients_cylinder->values[6];
    //     /* Store direction vector of z-axis of box. */
    //     cylinder_params.direction_vec[0] = coefficients_cylinder->values[3];
    //     cylinder_params.direction_vec[1] = coefficients_cylinder->values[4];
    //     cylinder_params.direction_vec[2] = coefficients_cylinder->values[5];

    //     ROS_INFO_STREAM(cylinder_params.radius);


    //     double max_angle_y = -std::numeric_limits<double>::infinity();
    //     double min_angle_y = std::numeric_limits<double>::infinity();

    //     double lowest_point[3] = { 0.0, 0.0, 0.0 };
    //     double highest_point[3] = { 0.0, 0.0, 0.0 };
        
    //     for (auto const point : cloud->points)
    //     {
    //     const double angle = atan2(point.z, point.y);
    //     /* Find the coordinates of the highest point */
    //     if (angle < min_angle_y)
    //     {
    //         min_angle_y = angle;
    //         lowest_point[0] = point.x;
    //         lowest_point[1] = point.y;
    //         lowest_point[2] = point.z;
    //     }
    //     /* Find the coordinates of the lowest point */
    //     else if (angle > max_angle_y)
    //     {
    //         max_angle_y = angle;
    //         highest_point[0] = point.x;
    //         highest_point[1] = point.y;
    //         highest_point[2] = point.z;
    //     }
    //     }
    //     /* Store the center point of cylinder */
    //     cylinder_params.center_pt[0] = (highest_point[0] + lowest_point[0]) / 2;
    //     cylinder_params.center_pt[1] = (highest_point[1] + lowest_point[1]) / 2;
    //     cylinder_params.center_pt[2] = (highest_point[2] + lowest_point[2]) / 2;
    //     /* Store the height of cylinder */
    //     cylinder_params.height =
    //         sqrt(pow((lowest_point[0] - highest_point[0]), 2) + pow((lowest_point[1] - highest_point[1]), 2) +
    //             pow((lowest_point[2] - highest_point[2]), 2));

    //     //ADD_CYLINDER------------------------------------------------------------

    //         // BEGIN_SUB_TUTORIAL add_cylinder
    // //
    // // Adding Cylinder to Planning Scene
    // // ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
    // // Define a collision object ROS message.
    //     moveit_msgs::CollisionObject collision_object;
    //     collision_object.header.frame_id = "camera_rgb_optical_frame";
    //     collision_object.id = "cylinder";

    //     // Define a cylinder which will be added to the world.
    //     shape_msgs::SolidPrimitive primitive;
    //     primitive.type = primitive.CYLINDER;
    //     primitive.dimensions.resize(2);
    //     /* Setting height of cylinder. */
    //     primitive.dimensions[0] = cylinder_params.height;
    //     /* Setting radius of cylinder. */
    //     primitive.dimensions[1] = cylinder_params.radius;

    //     // Define a pose for the cylinder (specified relative to frame_id).
    //     geometry_msgs::Pose cylinder_pose;
    //     /* Computing and setting quaternion from axis angle representation. */
    //     Eigen::Vector3d cylinder_z_direction(cylinder_params.direction_vec[0], cylinder_params.direction_vec[1],
    //                                         cylinder_params.direction_vec[2]);
    //     Eigen::Vector3d origin_z_direction(0., 0., 1.);
    //     Eigen::Vector3d axis;
    //     axis = origin_z_direction.cross(cylinder_z_direction);
    //     axis.normalize();
    //     double angle = acos(cylinder_z_direction.dot(origin_z_direction));
    //     cylinder_pose.orientation.x = axis.x() * sin(angle / 2);
    //     cylinder_pose.orientation.y = axis.y() * sin(angle / 2);
    //     cylinder_pose.orientation.z = axis.z() * sin(angle / 2);
    //     cylinder_pose.orientation.w = cos(angle / 2);

    //     // Setting the position of cylinder.
    //     cylinder_pose.position.x = cylinder_params.center_pt[0];
    //     cylinder_pose.position.y = cylinder_params.center_pt[1];
    //     cylinder_pose.position.z = cylinder_params.center_pt[2];

    //     // Add cylinder as collision object
    //     collision_object.primitives.push_back(primitive);
    //     collision_object.primitive_poses.push_back(cylinder_pose);
    //     collision_object.operation = collision_object.ADD;
    //     planning_scene_interface_.applyCollisionObject(collision_object);

        //TEST THE POINTCLOUD------------------------------------------
        ROS_INFO("Start publishing!");
        //TEST THE FILTERED POINTCLOUD BY PUBLISHING A TOPIC
        sensor_msgs::PointCloud2 testcloud;
        pcl::toROSMsg(*cloud, testcloud);
        cloud_pub_.publish(testcloud);

        //----------------------------------------------------------------------
        // SET OBJECT POSE
        geometry_msgs::Pose target_pose;
    
        tf2::Quaternion orientation;
        orientation.setRPY(0, -(2 * M_PI) / 2, (2 * M_PI) *3/ 8);
        target_pose.orientation = tf2::toMsg(orientation);;
        // target_pose1.position.x = 0.5;
        // target_pose1.position.y = 0.0;
        // target_pose1.position.z = 0.515;
        //+++++++++++++++++++++++++++++++
        target_pose.position.x = 0.51;
        target_pose.position.y = 0.0;
        target_pose.position.z = 0.515+0.022+0.036;

        res.object_pose = target_pose;
        // Perform object detection using the pointcloud_ data

        // Fill in the response data
        // res.object_pose = ...

        return true;
    }

};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "object_detection_service_node");
    ros::NodeHandle nh;
    moveit::planning_interface::PlanningSceneInterface psi;

    ObjectDetectionService object_detection_service(nh,psi);

    ROS_INFO("Object detection service is loading.");

    ros::Duration(2.0).sleep();
    ros::Rate rate(1);

    while(!object_detection_service.pointcloud_){

        ROS_WARN("Point cloud is not available yet.");
        ros::spinOnce();
        rate.sleep();
    }
    ROS_INFO("Server is ready!");

    ros::spin();

    return 0;
}
