#include "ros_lib_version.h"
#include "ros_lib_internal.hpp"
#include <deque>

std::deque<cfsVector3> vectorList;

int32_t ROS_LIB_Init()
{
    return 0;
}

void msgCallback(const geometry_msgs::Vector3::ConstPtr& msg) 
{ 
  ROS_INFO("ROS_LIB: received data from ROS: %f,%f,%f", msg->x, msg->y, msg->z);
  cfsVector3 rosVector;
  rosVector.x = msg->x;
  rosVector.y = msg->y;
  rosVector.z = msg->z;
  vectorList.push_back(rosVector);
}

RosNode * ROS_LIB_InitRos(int argc, char **argv)
{
    ros::init(argc,argv,"ros_lib");
    RosNode *rosNode = new RosNode();
    return rosNode;
}

bool ROS_LIB_InitPublisher(RosNode *rosNode, RosMessageType rosMsgType, char rosTopic[])
{
    switch (rosMsgType)
    {
        case ROS_LIB_Vector3:
        rosNode->publisher = rosNode->nodeHandle.advertise<geometry_msgs::Vector3>(rosTopic, 100);
        ROS_INFO("ROS_LIB: Setup to publish Vector3 msgs to %s topic complete.", rosTopic);
        break;

        default:
        return false;
    }
    return true;
}

bool ROS_LIB_InitSubscriber(RosNode *rosNode, RosMessageType rosMsgType, char rosTopic[])
{
    switch (rosMsgType)
    {
        case ROS_LIB_Vector3:
        rosNode->subscriber = rosNode->nodeHandle.subscribe<geometry_msgs::Vector3>(rosTopic, 100, msgCallback);
        ROS_INFO("ROS_LIB: Setup to subscribe to Vector3 msgs from %s topic complete.",rosTopic);
        break;

        default:
        return false;
    }
    return true;
}

int8_t ROS_LIB_SendVectorToRos(RosNode *rosNode, double x, double y, double z)
{
    geometry_msgs::Vector3 msg;
    msg.x = x;
    msg.y = y;
    msg.z = z;
    ROS_INFO("ROS_LIB: send Vector3 msg to ROS: (%f,%f,%f), rostimenow.toSec: %f", msg.x, msg.y, msg.z , ros::Time::now().toSec());
    rosNode->publisher.publish(msg);
    return 0;
}

int ROS_LIB_GetVectorListSize()
{
    return vectorList.size();
}

cfsVector3 ROS_LIB_GetNextVector()
{
    auto returnVec = vectorList[0];
    vectorList.pop_front();
    return returnVec;
}

void ROS_LIB_SpinOnce()
{   
    // ROS_INFO("ROS_LIB: SpinOnce");
    ros::spinOnce();
}

void ROS_LIB_DeleteRosNode(RosNode *rosNode)
{
    ros::shutdown();
    delete rosNode;
}

int32_t ROS_LIB_Test()
{
    return 42;
}
