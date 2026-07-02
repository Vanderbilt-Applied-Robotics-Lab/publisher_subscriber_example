#include <publisher_subscriber_example/simple_robot.h>

SimpleRobot::SimpleRobot(float link_length) : Node("simple_robot"), link_length_(link_length)
{
    // initialize ee location to theta = 0
    setJointAngle(0);

    // create subscriber object
    subscriber_ = this->create_subscription<std_msgs::msg::Float32>("/joint_angle", 10, 
        std::bind(&SimpleRobot::jointAngleCallback, this, std::placeholders::_1));
}

void SimpleRobot::setJointAngle(float theta)
{
    joint_angle_ = theta;

    ee_location_[0] = link_length_*std::sin(joint_angle_); // x
    ee_location_[1] = link_length_*std::cos(joint_angle_); // y
}

void SimpleRobot::printEELocation()
{
    std::cout << "EE Location. x: " << ee_location_[0] << " [m] y: " << ee_location_[1] << " [m]" << std::endl;  
}

void SimpleRobot::jointAngleCallback(const std_msgs::msg::Float32 & msg)
{
    std::cout << "Received joint angle: " << msg.data << std::endl;
    setJointAngle(msg.data);
    printEELocation();
}

int main(int argc, char * argv[])
{
    // initialize the node
    rclcpp::init(argc, argv);

    // create instance of class with 0.5 meter long robot
    auto node = std::make_shared<SimpleRobot>(0.5);

    // loop and update publishers and subscribers
    rclcpp::spin(node);
    rclcpp::shutdown();
    return 0;

}
