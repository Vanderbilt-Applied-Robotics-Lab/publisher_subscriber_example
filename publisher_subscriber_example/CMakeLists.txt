cmake_minimum_required(VERSION 3.8)
project(publisher_subscriber_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)

## INCLUDE(S)
include_directories(include)

# executables
add_executable(simple_robot src/simple_robot.cpp)
add_executable(joint_angle_publisher src/joint_angle_publisher.cpp)

# link libraries
ament_target_dependencies(simple_robot rclcpp std_msgs)
ament_target_dependencies(joint_angle_publisher rclcpp std_msgs)

# installs
install(TARGETS simple_robot
  DESTINATION lib/${PROJECT_NAME})

install(TARGETS joint_angle_publisher
  DESTINATION lib/${PROJECT_NAME})

ament_package()