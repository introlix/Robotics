#!/usr/bin/env python3

import rclpy
from rclpy.node import Node
from std_msgs.msg import String

class MinimalPublisher(Node):
    """Create a minimal publisher class that inherits from Node."""
    def __init__(self):
        # Initialize the Node with the name
        super().__init__('minimal_publisher')

        self.publisher = self.create_publisher(String, "/py_example_topic", 10)
        timer_period = 0.5
        self.timer = self.create_timer(timer_period, self.timer_callback)

        # counter to keep track of the number of messages published
        self.count = 0
    
    def timer_callback(self):
        """Callback function executed periodically by the timer."""
        msg = String()
        msg.data = "Hello, this is a message from the publisher!: %d" % self.count
        self.publisher.publish(msg)
        self.get_logger().info('Publishing: "%s"' % msg.data)
        self.count += 1


def main(args=None):
    """
    Main function to start the ROS2 Node

    Args:
        args: Command line arguments (default: None)
    """

    rclpy.init(args=args)

    minimal_publisher = MinimalPublisher()

    rclpy.spin(minimal_publisher)

    # Destroy the node explicitly
    minimal_publisher.destroy_node()
    rclpy.shutdown()

if __name__ == '__main__':
    main()