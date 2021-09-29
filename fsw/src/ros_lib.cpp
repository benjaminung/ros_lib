#include "ros_lib_version.h"
#include "ros_lib_internal.hpp"

int32_t ROS_LIB_Init()
{
    return 0;
}

RosPub * ROS_LIB_InitRos(int argc, char **argv)
{
    ros::init(argc,argv,"ros_lib");
    RosPub * rosPub = new RosPub();
    rosPub->publisher = rosPub->nodeHandle.advertise<geometry_msgs::Vector3>("ros_cfe_vectormsg", 100);
    return rosPub;
}

int8_t ROS_LIB_SendVectorToRos(RosPub *rosPub, double x, double y, double z)
{
    geometry_msgs::Vector3 msg;
    msg.x = x;
    msg.y = y;
    msg.z = z;
    ROS_INFO("send ROS Vector3 msg: (%f,%f,%f), rostimenow.toSec: %f", msg.x, msg.y, msg.x , ros::Time::now().toSec());
    rosPub->publisher.publish(msg);
    return 0;
}

void ROS_LIB_DeleteRosPub(RosPub *rosPub)
{
    delete rosPub;
}

int32_t ROS_LIB_Test()
{
    return 42;
}
