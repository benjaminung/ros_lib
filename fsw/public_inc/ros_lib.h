#ifndef _ros_lib_h_
#define _ros_lib_h_

#include <stdint.h>

#ifdef __cplusplus
#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>

extern "C"
{
struct RosPub
{
    ros::NodeHandle nodeHandle;
    ros::Publisher publisher;
};
#else
struct RosPub;
typedef struct RosPub RosPub;
#endif

int32_t ROS_LIB_Init(void);
RosPub * ROS_LIB_InitRos(int argc, char **argv);
int8_t ROS_LIB_SendVectorToRos(RosPub *rosPub, double x, double y, double z);
int32_t ROS_LIB_Test(void);
void ROS_LIB_DeleteRosPub(RosPub *rosPub);

#ifdef __cplusplus
}
#endif

#endif