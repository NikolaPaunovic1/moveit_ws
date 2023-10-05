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
#include <image_transport/image_transport.h>
#include <cv_bridge/cv_bridge.h>
#include <sensor_msgs/image_encodings.h>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <tf2_ros/transform_listener.h>

class ObjectDetectionService
{
public:
    ObjectDetectionService(ros::NodeHandle& nh, moveit::planning_interface::PlanningSceneInterface& planning_scene_interface)
        : pointcloud_(new sensor_msgs::PointCloud2),
          cloud(new pcl::PointCloud<pcl::PointXYZ>),
          it(nh),
          tf_listener_(tf_buffer_)
    {
        pointcloud_sub_ = nh.subscribe("/camera/depth/points", 1, &ObjectDetectionService::pointCloudCallback, this);
        service_ = nh.advertiseService("object_position_service", &ObjectDetectionService::handleRequest, this);
        image_sub = it.subscribe("/camera/color/image_raw", 1, &ObjectDetectionService::image_cb, this);
    }

    sensor_msgs::PointCloud2::ConstPtr pointcloud_;
    ros::Subscriber pointcloud_sub_;
    ros::ServiceServer service_;
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud;
    image_transport::ImageTransport it;
    image_transport::Subscriber image_sub;
    cv_bridge::CvImagePtr cv_ptr;
    tf2_ros::Buffer tf_buffer_;
    tf2_ros::TransformListener tf_listener_;

private:

  void image_cb(const sensor_msgs::ImageConstPtr& msg)
  {
    try
    {
      cv_ptr = cv_bridge::toCvCopy(msg, sensor_msgs::image_encodings::BGR8);
    }
    catch (cv_bridge::Exception& e)
    {
      ROS_ERROR("cv_bridge exception: %s", e.what());
      return;
    }
  }
    
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

        //OPENCV--------------------------
        //^^^^^^^^^^^^^^^^^^^^^^^
        float image_size_y = cv_ptr->image.rows;
        float image_size_x = cv_ptr->image.cols;
    

        cv::Mat img = cv_ptr->image;
        cv::Mat gray, canny_0, canny, canny_roi;

        // Convert to grayscale
        cv::cvtColor(img, gray, cv::COLOR_BGR2GRAY);

        // Canny Edge detection on grayscale image
        cv::Canny(gray, canny_0, 125, 170);

        // Dilate the edges so that shapes are better visible
        cv::Mat kernel = cv::Mat::ones(2, 2, CV_8U);
        cv::dilate(canny_0, canny, kernel, cv::Point(-1, -1), 1);

        // Define a Region Of Interest for the Box Detection
        int x_roi[] = {185, 343};
        int y_roi[] = {133, 327};
        int cx = 0;
        int cy = 0;

        // Conduct box detection only inside ROI
        canny_roi = canny(cv::Range(y_roi[0], y_roi[1]), cv::Range(x_roi[0], x_roi[1]));

        // Only contours are of interest
        std::vector<std::vector<cv::Point>> contours;
        std::vector<cv::Vec4i> hierarchy;
        cv::findContours(canny_roi, contours, hierarchy, cv::RETR_TREE, cv::CHAIN_APPROX_NONE);

        // Prepare a vector for the edge points to be stored
        std::vector<cv::Point> edge_points;

        // Loop through the contours and only calculate the middle point
        // for the box shape (4 Corners) - Store inside "edge_points"
        for (size_t i = 0; i < contours.size(); ++i) {
            double area = cv::contourArea(contours[i]);
            if (area > 150) {
                std::vector<cv::Point> approx;
                cv::approxPolyDP(contours[i], approx, 0.035 * cv::arcLength(contours[i], true), true);
                if (approx.size() == 4) {
                    cv::Moments M = cv::moments(approx);
                    cx = static_cast<int>(M.m10 / M.m00);
                    cy = static_cast<int>(M.m01 / M.m00);

                    for (const cv::Point &point : approx) {
                        edge_points.push_back(point);
                    }
                }
            }
        }

        int radius = 3; // The radius of the circle
        cv::Scalar color(0, 255, 0); // The color of the circle, in this case, green (BGR)
        int thickness = 2; // The thickness of the circle outline, use -1 to fill the circle

        cv::circle(img, cv::Point(cx+x_roi[0], cy+y_roi[0]), radius, color, thickness);
        cv::namedWindow( "Middle Point", cv::WINDOW_AUTOSIZE );
        cv::imshow( "Middle Point", img);
        cv::waitKey(0);
        cv::destroyWindow("Middle Point");
        cv::Point my_point = cv::Point(cx + x_roi[0], cy + y_roi[0]);
        geometry_msgs::Point output_point;

        int u = my_point.x;
        int v = my_point.y;

        int width = pointcloud_->width;
        int height = pointcloud_->height;

        ROS_INFO("Point cloud width: %d, height: %d", width, height);

        if (u >= 0 && u < width && v >= 0 && v < height) {
            ROS_INFO("Check succeeded!!");
        } else {
        ROS_WARN("Invalid pixel coordinates: u = %d, v = %d", u, v);
        }

        int arrayPosition = v * pointcloud_->row_step + u * pointcloud_->point_step;

        int arrayPosX = arrayPosition + pointcloud_->fields[0].offset;
        int arrayPosY = arrayPosition + pointcloud_->fields[1].offset;
        int arrayPosZ = arrayPosition + pointcloud_->fields[2].offset;

        float X = 0.0;
        float Y = 0.0;
        float Z = 0.0;

        memcpy(&X, &pointcloud_->data[arrayPosX], sizeof(float));
        memcpy(&Y, &pointcloud_->data[arrayPosY], sizeof(float));
        memcpy(&Z, &pointcloud_->data[arrayPosZ], sizeof(float));

        output_point.x = X;
        output_point.y = Y;
        output_point.z = Z;

        geometry_msgs::PoseStamped input_pose_stamped;
        input_pose_stamped.pose.position = output_point;
        input_pose_stamped.pose.orientation.w = 1.0; // Set identity quaternion
        input_pose_stamped.header.frame_id = frame_id;
        input_pose_stamped.header.stamp = ros::Time::now();
    
        geometry_msgs::PoseStamped output_pose_stamped = tf_buffer_.transform(input_pose_stamped, "panda_link0", ros::Duration(1));

        ROS_INFO("Transformed point: x = %f, y = %f, z = %f", output_pose_stamped.pose.position.x, output_pose_stamped.pose.position.y, output_pose_stamped.pose.position.z); 

        res.object_pose.position =  output_pose_stamped.pose.position;
        res.object_pose.orientation = input_pose_stamped.pose.orientation;

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
