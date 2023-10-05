#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/registration/icp.h>
#include <message_filters/subscriber.h>
#include <message_filters/time_synchronizer.h>

ros::Publisher _pub;
void cloud_callback(const sensor_msgs::PointCloud2ConstPtr& pc1_msg, const sensor_msgs::PointCloud2ConstPtr& pc2_msg) {
  // Convert the sensor_msgs/PointCloud2 data to pcl/PointCloud
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud1(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::PointCloud<pcl::PointXYZ>::Ptr cloud2(new pcl::PointCloud<pcl::PointXYZ>);
  pcl::fromROSMsg(*pc1_msg, *cloud1);
  pcl::fromROSMsg(*pc2_msg, *cloud2);

  // Perform ICP
  pcl::IterativeClosestPoint<pcl::PointXYZ, pcl::PointXYZ> icp;
  icp.setInputCloud(cloud2);
  icp.setInputTarget(cloud1);
  pcl::PointCloud<pcl::PointXYZ> Final;
  icp.align(Final);

  // Check convergence and publish the output
  if (icp.hasConverged()) {
    sensor_msgs::PointCloud2 output;
    pcl::toROSMsg(Final, output);
    output.header = pc1_msg->header; // Set the output header to maintain the reference frame
    _pub.publish(output);
    ROS_INFO("The header Frame is: %s", output.header.frame_id.c_str());
  } else {
    ROS_WARN("ICP did not converge.");
  }
}

int main(int argc, char** argv) {
  ros::init(argc, argv, "icp_node");
  ros::NodeHandle n("~");
  _pub = n.advertise<sensor_msgs::PointCloud2>("/camera3/depth/points", 1);

  ros::Duration(5.0).sleep();
  message_filters::Subscriber<sensor_msgs::PointCloud2> pc1_sub(n, "/camera/depth/points", 1);
  message_filters::Subscriber<sensor_msgs::PointCloud2> pc2_sub(n, "/camera2/depth/points", 1);
  message_filters::TimeSynchronizer<sensor_msgs::PointCloud2, sensor_msgs::PointCloud2> sync(pc1_sub, pc2_sub, 10);
  sync.registerCallback(boost::bind(&cloud_callback, _1, _2));



  ros::spin();
}
