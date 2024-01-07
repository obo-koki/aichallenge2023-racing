#include "trajectory_subscriber.hpp"
#include <memory>

using Trajectory = autoware_auto_planning_msgs::msg::Trajectory;
using std::placeholders::_1;

PathSubscriber::PathSubscriber() : Node("trajectory_subscriber")
{
  sub_path_ = create_subscription<Trajectory>("trajectory", 10, std::bind(&PathSubscriber::topicCallback, this, _1));
}

void PathSubscriber::topicCallback(const Trajectory::ConstSharedPtr msg)
{
  path_ = msg;
  RCLCPP_INFO(this->get_logger(), "I heard");
}

int main(int argc, char * argv[])
{
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<PathSubscriber>());
  rclcpp::shutdown();
  return 0;
}
