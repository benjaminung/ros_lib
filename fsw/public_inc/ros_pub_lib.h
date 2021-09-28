#ifndef _ros_pub_lib_h_
#define _ros_pub_lib_h_

#include <stdint.h>

#ifdef __cplusplus
#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>

extern "C"
{
struct RosPub
{
    ros::NodeHandle nh;
    ros::Publisher ros_pub;
    double num;
};
#else
struct RosPub;
typedef struct RosPub RosPub;
#endif

int32_t ROS_PUB_LIB_Init(void);
RosPub * ROS_PUB_LIB_InitRos(int argc, char **argv);
int8_t ROS_PUB_LIB_SendVectorToRos(RosPub * rosPub, double x, double y, double z);
int32_t ROS_PUB_LIB_Test(void);

#ifdef __cplusplus
}
#endif

#endif