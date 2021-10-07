#ifndef _ros_lib_h_
#define _ros_lib_h_

#include <stdint.h>

#ifdef __cplusplus
#include <ros/ros.h>
#include <geometry_msgs/Vector3.h>

extern "C"
{
struct RosNode
{
    ros::NodeHandle nodeHandle;
    ros::Publisher publisher;
    ros::Subscriber subscriber;
};

#else
struct RosNode;
typedef struct RosNode RosNode;
#endif

typedef enum RosNodeType {ROS_LIB_Publish, ROS_LIB_Subscribe} RosNodeType;
typedef enum RosMessageType {ROS_LIB_Vector3, ROS_LIB_Twist} RosMessageType;

typedef struct 
{
    double x;
    double y;
    double z;
} cfsVector3;

int32_t ROS_LIB_Init(void);
RosNode * ROS_LIB_InitRos(int argc, char **argv);
bool ROS_LIB_InitPublisher(RosNode *rosNode, RosMessageType rosMsgType, char rosTopic[]);
bool ROS_LIB_InitSubscriber(RosNode *rosNode, RosMessageType rosMsgType, char rosTopic[]);

int8_t ROS_LIB_SendVectorToRos(RosNode *rosNode, double x, double y, double z);
int ROS_LIB_GetVectorListSize();
cfsVector3 ROS_LIB_GetNextVector();

void ROS_LIB_SpinOnce();
int32_t ROS_LIB_Test(void);
void ROS_LIB_DeleteRosNode(RosNode *rosNode);

#ifdef __cplusplus
}
#endif

#endif