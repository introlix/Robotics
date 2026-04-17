#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "std_msgs/msg/string.hpp"

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node
{
public:
    MinimalPublisher() : Node("minimal_publisher"), count(0)
    {
        publisher_ = this->create_publisher<std_msgs::msg::String>("/cpp_example_topic", 10);
        timer_ = this->create_wall_timer(500ms, std::bind(&MinimalPublisher::timerCallback, this));
    }

    void timerCallback()
    {
        auto message = std_msgs::msg::String();
        message.data = "Hello, world! " + std::to_string(count++);
        
        publisher_->publish(message);
        RCLCPP_INFO(this->get_logger(), "Publishing: '%s'", message.data.c_str());
    }

private:
    rclcpp::Publisher<std_msgs::msg::String>::SharedPtr publisher_;
    rclcpp::TimerBase::SharedPtr timer_;
    size_t count;
};

int main(int argc, char *argv[])
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MinimalPublisher>());
    rclcpp::shutdown();
    return 0;
}