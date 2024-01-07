#ifndef PATH_SUBSCRIBER_HPP_
#define PATH_SUBSCRIBER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <autoware_auto_planning_msgs/msg/trajectory.hpp>

using Trajectory = autoware_auto_planning_msgs::msg::Trajectory;

class PathSubscriber : public rclcpp::Node {
    public:
        PathSubscriber();

        void topicCallback(const Trajectory::ConstSharedPtr msg);
    
    private:
        rclcpp::Subscription<Trajectory>::SharedPtr sub_path_;
        Trajectory::ConstSharedPtr path_;
};
#endif  // PATH_SUBSCRIBER_HPP_