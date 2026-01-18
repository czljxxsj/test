#include "rclcpp/rclcpp.hpp"

class MyNode : public rclcpp::Node
{
public:
    MyNode() : Node("my_node_name") // 节点名字
    {
        // 创建一个定时器，每 1000ms (1秒) 触发一次
        timer_ = this->create_wall_timer(
            std::chrono::milliseconds(1000),
            std::bind(&MyNode::timer_callback, this));
    }

private:
    void timer_callback()
    {
        // 类似于 cout，但在 ROS 里我们用 RCLCPP_INFO
        RCLCPP_INFO(this->get_logger(), "Hello ROS 2! I am Tangchongbo.");
    }
    rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char **argv)
{
    rclcpp::init(argc, argv);
    rclcpp::spin(std::make_shared<MyNode>()); // 让节点转起来
    rclcpp::shutdown();
    return 0;
}