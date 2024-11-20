#!/usr/bin/env python3

import rospy
from nav_msgs.msg import Odometry
from sensor_msgs.msg import Imu, MagneticField, LaserScan

def odometry_callback(data):
    rospy.loginfo("Odometry: Position (%f, %f, %f)", data.pose.pose.position.x, data.pose.pose.position.y, data.pose.pose.position.z)

def imu_callback(data):
    rospy.loginfo("IMU: Orientation (%f, %f, %f, %f)", data.orientation.x, data.orientation.y, data.orientation.z, data.orientation.w)

def magnetic_callback(data):
    rospy.loginfo("Magnetic Field: (%f, %f, %f)", data.magnetic_field.x, data.magnetic_field.y, data.magnetic_field.z)

def scan_callback(data):
    rospy.loginfo("LaserScan: Range min (%f), max (%f)", min(data.ranges), max(data.ranges))

def listener():
    rospy.init_node('motion_replay', anonymous=True)

    rospy.Subscriber("/driver/encoder", Odometry, odometry_callback)
    rospy.Subscriber("/driver/eul", Imu, imu_callback)
    rospy.Subscriber("/driver/imu", Imu, imu_callback)
    rospy.Subscriber("/driver/mag", MagneticField, magnetic_callback)
    rospy.Subscriber("/driver/scan", LaserScan, scan_callback)

    rospy.spin()

if __name__ == '__main__':
    listener()