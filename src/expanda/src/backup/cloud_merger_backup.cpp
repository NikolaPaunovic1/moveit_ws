#include <ros/ros.h>
#include <sensor_msgs/PointCloud2.h>
#include <tf2_ros/transform_listener.h>
#include <pcl_ros/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/conversions.h>
#include <pcl_conversions/pcl_conversions.h>
#include <tf2_geometry_msgs/tf2_geometry_msgs.h>
#include <pcl_ros/transforms.h>



class PointCloudMerger
{
public:
    PointCloudMerger(ros::NodeHandle& nh)
        : tf_listener_(tf_buffer_)
    {
        cloud1_sub_ = nh.subscribe("/camera/depth/points", 1, &PointCloudMerger::cloud1Callback, this);
        cloud2_sub_ = nh.subscribe("/camera2/depth/points", 1, &PointCloudMerger::cloud2Callback, this);
        merged_cloud_pub_ = nh.advertise<sensor_msgs::PointCloud2>("/camera3/depth/points", 1);
    }

    void cloud1Callback(const sensor_msgs::PointCloud2::ConstPtr& msg)
    {
        ROS_INFO("PC1 Callback!");
        cloud1_ = msg;
    }

    void cloud2Callback(const sensor_msgs::PointCloud2::ConstPtr& msg)
    {
        ROS_INFO("PC2 Callback!");
        cloud2_ = msg;
    }

    void mergeClouds()
    {
        if (!cloud1_ || !cloud2_){
            ROS_WARN("One of the Pointclouds is empty!");
            return;
        }

        geometry_msgs::TransformStamped transform;
        try
        {
            transform = tf_buffer_.lookupTransform(cloud1_->header.frame_id, cloud2_->header.frame_id, ros::Time(0));
        }
        catch (tf2::TransformException& ex)
        {
            ROS_WARN("%s", ex.what());
            return;
        }

        sensor_msgs::PointCloud2 cloud2_transformed;
        //tf2::doTransform(*cloud2_, cloud2_transformed, transform);
        ROS_INFO("Starting Transoform!");
        pcl_ros::transformPointCloud(cloud1_->header.frame_id,*cloud2_, cloud2_transformed, tf_buffer_);

        pcl::PointCloud<pcl::PointXYZ> pcl_cloud1, pcl_cloud2, pcl_merged_cloud;
        pcl::fromROSMsg(*cloud1_, pcl_cloud1);
        pcl::fromROSMsg(cloud2_transformed, pcl_cloud2);
        ROS_INFO("Starting merging!");

        pcl_merged_cloud = pcl_cloud1 + pcl_cloud2;

        sensor_msgs::PointCloud2 merged_cloud;
        pcl::toROSMsg(pcl_merged_cloud, merged_cloud);
        merged_cloud.header.frame_id = cloud1_->header.frame_id;
        merged_cloud.header.stamp = ros::Time::now();
        ROS_INFO("Starting Publishing!");

        merged_cloud_pub_.publish(merged_cloud);
    }

private:
    ros::Subscriber cloud1_sub_;
    ros::Subscriber cloud2_sub_;
    ros::Publisher merged_cloud_pub_;

    sensor_msgs::PointCloud2::ConstPtr cloud1_;
    sensor_msgs::PointCloud2::ConstPtr cloud2_;

    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;
};

int main(int argc, char** argv)
{
    ros::init(argc, argv, "pointcloud_merger");
    ros::NodeHandle nh;

    PointCloudMerger pointcloud_merger(nh);

    ros::Duration(5.0).sleep();
    

    ros::Rate rate(2);  // Rate in Hz
    while (ros::ok())
    {
        pointcloud_merger.mergeClouds();
        ros::spinOnce();
        rate.sleep();
    }

}

