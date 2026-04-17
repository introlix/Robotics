#! /usr/bin/env python3

"""
This ROS2 node periodically publishes "Hello World" messages to a topic.

---------
Publishing Topics:
    The channel containing the "Hello World" messages
    /py_example_topic - std_msgs/String

Subscription Topics:
    None

---------
Author: Satyam Mishra
Date: 2026-03-10
"""
import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class MinimalPublisher(Node):
    pass