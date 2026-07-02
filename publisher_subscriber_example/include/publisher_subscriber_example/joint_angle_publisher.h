#ifndef JOINT_ANGLE_PUBLISHER
#define JOINT_ANGLE_PUBLISHER

#include <array>
#include <cmath>
#include <iostream> // for printing
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/float32.hpp>

/**
 * publishes to the /joint_angle topic
 * Applied Robotics
 */
class JointAnglePublisher : public rclcpp::Node
{
public:
    /**
     * Constructor
     */
    JointAnglePublisher();

    /**
     * Default destructor
     */
    ~JointAnglePublisher() = default;

    /**
     * Publishes a specified joint angle
     * @param theta joint angle in radians
     */
    void publishJointAngle(float angle);

private:

    // publisher object
    rclcpp::Publisher<std_msgs::msg::Float32>::SharedPtr publisher_;

    // output message
    std_msgs::msg::Float32 msg_ = std_msgs::msg::Float32();

};
#endif // JOINT_ANGLE_PUBLISHER