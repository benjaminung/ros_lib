project(CFE_ROS_PUB_LIB CXX)

# Create the app module
add_cfe_app(ros_pub_lib fsw/src/ros_pub_lib.cpp)

# The API to this library (which may be invoked/referenced from other apps)
# is stored in fsw/public_inc.  Using "target_include_directories" is the 
# preferred method of indicating this (vs. directory-scope "include_directories").
target_include_directories(ros_pub_lib PUBLIC fsw/public_inc /opt/ros/noetic/lib /opt/ros/noetic/include)
target_link_directories(ros_pub_lib PUBLIC /opt/ros/noetic/lib)
target_link_libraries(ros_pub_lib roscpp rostime rosconsole)

# if (ENABLE_UNIT_TESTS)
#   add_subdirectory(ut-stubs)
#   add_subdirectory(unit-test)
# endif (ENABLE_UNIT_TESTS)


