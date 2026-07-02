#ifndef SIMPLE_ROBOT
#define SIMPLE_ROBOT

#include <iostream>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

/**
 * Subscribes to the /joint_angle topic and updates the kinematics of a 1 DOF robot
 * Applied Robotics
 */
class SimpleRobot : public rclcpp::Node
{
public:
    /**
     * Constructor
     * @param link_length The length of a the link [m]
     */
    SimpleRobot(float link_length);

    /**
     * Default destructor
     */
    ~SimpleRobot() = default;

    /**
     * Set the joint angle of the robot
     * @param theta joint angle in radians
     */
    void setJointAngle(float theta);

    /**
     * prints the x and y location of the robot's end-effector (EE)
     */
    void printEELocation();

private:
    /**
     * Callback for the /joint_angle topic
     * ADDED ON FROM PREVIOUS EXAMPLE
     * @param msg Reference to the incoming message object
     */
    void jointAngleCallback(const std_msgs::msg::Float32 & msg);

    /**
     * Subscriber object for the /joint_angle topic
     * ADDED ON FROM PREVIOUS EXAMPLE 
     */
    rclcpp::Subscription<std_msgs::msg::Float32>::SharedPtr subscriber_;

    float link_length_;
    float joint_angle_ = 0;

    std::array<float, 2> ee_location_; // [x,y] We will learn better ways of doing this soon
};
#endif // SIMPLE_ROBOT