#include "ros_pub_lib_version.h"
#include "ros_pub_lib_internal.hpp"

int32_t ROS_PUB_LIB_Init()
{
    return 0;
}

RosPub * ROS_PUB_LIB_InitRos(int argc, char **argv)
{
    ros::init(argc,argv,"ros_pub_lib");
    RosPub * rosPub = new RosPub();
    rosPub->ros_pub = rosPub->nh.advertise<geometry_msgs::Vector3>("ros_cfe_vectormsg", 100);
    return rosPub;
}

int8_t ROS_PUB_LIB_SendVectorToRos(RosPub * rosPub, double x, double y, double z)
{
    geometry_msgs::Vector3 msg;
    msg.x = x;
    msg.y = y;
    msg.z = z;
    ROS_INFO("send vector msg: (%f,%f,%f), rostimenow.toSec: %f", msg.x, msg.y, msg.x , ros::Time::now().toSec());
    rosPub->ros_pub.publish(msg);
    return 0;
}

int32_t ROS_PUB_LIB_Test()
{
    return 42;
}
