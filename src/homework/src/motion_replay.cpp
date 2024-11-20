#include <ros/ros.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/Imu.h>
#include <sensor_msgs/MagneticField.h>
#include <sensor_msgs/LaserScan.h>

void odometryCallback(const nav_msgs::Odometry::ConstPtr& msg) {
    ROS_INFO("Odometry: Position (%f, %f, %f)", 
             msg->pose.pose.position.x, 
             msg->pose.pose.position.y, 
             msg->pose.pose.position.z);
}

void imuCallback(const sensor_msgs::Imu::ConstPtr& msg) {
    ROS_INFO("IMU: Orientation (%f, %f, %f, %f)", 
             msg->orientation.x, 
             msg->orientation.y, 
             msg->orientation.z, 
             msg->orientation.w);
}

void magneticCallback(const sensor_msgs::MagneticField::ConstPtr& msg) {
    ROS_INFO("Magnetic Field: (%f, %f, %f)", 
             msg->magnetic_field.x, 
             msg->magnetic_field.y, 
             msg->magnetic_field.z);
}

void scanCallback(const sensor_msgs::LaserScan::ConstPtr& msg) {
    // 过滤无穷大值
    std::vector<float> valid_ranges;
    for (const auto& range : msg->ranges) {
        if (range < std::numeric_limits<float>::infinity()) {
            valid_ranges.push_back(range);
        }
    }

    if (!valid_ranges.empty()) {
        float min_range = *std::min_element(valid_ranges.begin(), valid_ranges.end());
        float max_range = *std::max_element(valid_ranges.begin(), valid_ranges.end());
        ROS_INFO("LaserScan: Range min (%f), max (%f)", min_range, max_range);
    } else {
        ROS_INFO("LaserScan: All ranges are inf");
    }
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "motion_replay");
    ros::NodeHandle nh;

    ros::Subscriber odometry_sub = nh.subscribe("/driver/encoder", 10, odometryCallback);
    ros::Subscriber imu_eul_sub = nh.subscribe("/driver/eul", 10, imuCallback);
    ros::Subscriber imu_sub = nh.subscribe("/driver/imu", 10, imuCallback);
    ros::Subscriber magnetic_sub = nh.subscribe("/driver/mag", 10, magneticCallback);
    ros::Subscriber scan_sub = nh.subscribe("/driver/scan", 10, scanCallback);

    ros::spin();

    return 0;
}