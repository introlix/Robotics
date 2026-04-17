# ROS2

### Create ROS2 Package
```
ros2 pkg create --build-type ament_cmake --license Apache-2.0 name_goes_here
```

### Build ROS2 all Package
CD into root dir i.e. ros_ws or ros2_ws or anyother name
```
colcon build
```

### Build ROS2 one Package
From same DIR
```
colcon build --packages-select pkg_name
```

### Get ROS2 Node List
To get running nodes run this:
```
ros2 node list
```