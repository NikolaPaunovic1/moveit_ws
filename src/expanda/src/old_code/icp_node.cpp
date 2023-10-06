#include "ros/ros.h"
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/registration/icp.h>

bool cloud_in_received = false;
bool cloud2_in_received = false;
ros::Publisher _pub;
pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_in(new pcl::PointCloud<pcl::PointXYZ>);

void fixed_frame_cb(const sensor_msgs::PointCloud2ConstPtr& pc2_msg) {
  pcl::fromROSMsg(*pc2_msg, *cloud_in);
  cloud_in_received = true;
  
  ROS_INFO("Pointcloud 1 received!");
}

void camera_frame_cb(const sensor_msgs::PointCloud2ConstPtr& next_pc2_msg) {
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_in(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::fromROSMsg(*next_pc2_msg, *cloud2_in);
  cloud2_in_received = true;
  ROS_INFO("Pointcloud 2 recevied!");

  if(cloud_in_received && cloud2_in_received){

    ROS_INFO("Entering ICP Algorithm!");
    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    icp.setInputCloud(cloud2_in);
    icp.setInputTarget(cloud_in);
    pcl::PointCloud<pcl::PointXYZ> Final;
    ROS_INFO("Starting Alignment!");
    icp.align(Final);
    ROS_INFO("Finished Alignment!");

    if (icp.hasConverged()) {
        sensor_msgs::PointCloud2 output;
        pcl::toROSMsg(Final, output);
        _pub.publish(output);
    } else {
        ROS_WARN("ICP did not converge.");
    }
  }
  else if(!cloud_in_received){
    ROS_WARN("Pointcloud topic 1 was not received!");
    ros::Duration(1.0).sleep();
  }
  else{
    ROS_WARN("Pointcloud topic 2 was not received!");
    ros::Duration(1.0).sleep();
  }

  // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_in(new pcl::PointCloud<pcl::PointXYZ>);
  // pcl::fromROSMsg(*next_pc2_msg, *cloud2_in);
  // cloud2_in_received = true;
  // ROS_INFO("Pointcloud 2 received!");
  // ros::Duration(1.0).sleep();

}

int main(int argc, char** argv) {
  ros::init(argc, argv, "icp_node");
  ros::NodeHandle n("~");
  _pub = n.advertise<sensor_msgs::PointCloud2>("/camera3/depth/points", 1);

  ros::Duration(5.0).sleep();

  ros::Subscriber sub = n.subscribe("/camera/depth/points", 1, fixed_frame_cb);
  ros::Subscriber sub2 = n.subscribe("/camera2/depth/points", 1, camera_frame_cb);



  ros::spin();
}


// #include <tf/transform_listener.h>
// #include <pcl_ros/transforms.h>

// // ...

// tf::TransformListener listener;
// ros::Duration(1.0).sleep(); // Give the listener some time to receive the transforms

// // Transform cloud2_in to the frame of cloud_in
// sensor_msgs::PointCloud2 cloud2_transformed_msg;
// std::string target_frame = pc2_msg->header.frame_id; // Assuming cloud_in is in pc2_msg's frame
// std::string source_frame = next_pc2_msg->header.frame_id; // Assuming cloud2_in is in next_pc2_msg's frame
// if (listener.canTransform(target_frame, source_frame, ros::Time(0))) {
//     pcl_ros::transformPointCloud(target_frame, *next_pc2_msg, cloud2_transformed_msg, listener);
// } else {
//     ROS_WARN("No transform available between %s and %s", source_frame.c_str(), target_frame.c_str());
//     return;
// }

// // Convert the transformed sensor_msgs::PointCloud2 to pcl::PointCloud<pcl::PointXYZ>
// pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_transformed(new pcl::PointCloud<pcl::PointXYZ>);
// pcl::fromROSMsg(cloud2_transformed_msg, *cloud2_transformed);

// // Now pass cloud2_transformed to ICP instead of cloud2_in
// icp.setInputCloud(cloud2_transformed);
