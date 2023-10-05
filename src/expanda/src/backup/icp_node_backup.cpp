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
}

void camera_frame_cb(const sensor_msgs::PointCloud2ConstPtr& next_pc2_msg) {
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2_in(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::fromROSMsg(*next_pc2_msg, *cloud2_in);
  cloud2_in_received = true;

  if(cloud_in_received && cloud2_in_received){

    pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
    icp.setInputCloud(cloud2_in);
    icp.setInputTarget(cloud_in);
    pcl::PointCloud<pcl::PointXYZ> Final;
    icp.align(Final);

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
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "icp_node");
  ros::NodeHandle n("~");

  ros::Subscriber sub = n.subscribe("/camera/depth/points", 1, fixed_frame_cb);
  ros::Subscriber sub2 = n.subscribe("/camera2/depth/points", 1, camera_frame_cb);

  _pub = n.advertise<sensor_msgs::PointCloud2>("/camera3/depth/points", 1);

  ros::spin();
}
