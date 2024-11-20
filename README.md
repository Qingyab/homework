bag中是一些描述机器人运动过程的参数。
rosbag info查看信息，包含


      path:        jiantu2.bag
      version:     2.0
      duration:    1:43s (103s)
      start:       Sep 21 2024 06:52:48.60 (1726872768.60)
      end:         Sep 21 2024 06:54:32.41 (1726872872.41)
      size:        36.9 MB
      messages:    91348
      compression: none [48/48 chunks]
      types:       nav_msgs/Odometry         [cd5e73d190d741a2f92e81eda573aca7]
                   sensor_msgs/Imu           [6a62c6daae103f4ff57a132d6f95cec2]
                   sensor_msgs/LaserScan     [90c7ef2dc6895d81024acba2ac42f369]
                   sensor_msgs/MagneticField [2f3b0b43eed0c9501de0fa3ff89a45aa]
      topics:      /driver/encoder    4758 msgs    : nav_msgs/Odometry
                   /driver/eul       28635 msgs    : sensor_msgs/Imu
                   /driver/imu       28469 msgs    : sensor_msgs/Imu
                   /driver/mag       28469 msgs    : sensor_msgs/MagneticField
                   /driver/scan       1017 msgs    : sensor_msgs/LaserScan

odometry是位姿，用四元数表示。
imu是惯性测量单元，包括加速度，角速度，磁场强度。
magneticfield将磁场强度分为x,y,z轴，分别显示。
laserscan为激光雷达数据，包含多个角度对应的距离。
