# publisher_subscriber_example
Simple publisher and subscriber example. Builds on [basic_cpp_example](https://github.com/Vanderbilt-Applied-Robotics-Lab/basic_cpp_example). Joint angles are now published to a ROS 2 topic and subscribed to by `simple_robot`

## Downloading Code
1. Navigate to examples workspace source folder: `cd ~/workspaces/examples_ws/src`
2. Download code: `git clone https://github.com/Vanderbilt-Applied-Robotics-Lab/publisher_subscriber_example.git`

## Compiling Code
1. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
2. Compile the code: `colcon build`

## Running Code
1. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
2. Source the code: `source install/setup.bash`
3. Run simple robot: `ros2 run publisher_subscriber_example simple_robot`
4. Open a new terminal window
5. Navigate to examples workspace: `cd ~/workspaces/examples_ws`
6. Source the code: `source install/setup.bash`
3. Run joint angle publisher: `ros2 run publisher_subscriber_example joint_angle_publisher`
