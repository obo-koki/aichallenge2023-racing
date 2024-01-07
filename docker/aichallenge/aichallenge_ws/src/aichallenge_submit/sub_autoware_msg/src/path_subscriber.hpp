#ifndef PATH_SUBSCRIBER_HPP_
#define PATH_SUBSCRIBER_HPP_

#include <rclcpp/rclcpp.hpp>
#include <autoware_auto_planning_msgs/msg/path.hpp>

using Path = autoware_auto_planning_msgs::msg::Path;

class PathSubscriber : public rclcpp::Node {
    public:
        PathSubscriber();

        void topicCallback(const Path::ConstSharedPtr msg);
    
    private:
        rclcpp::Subscription<Path>::SharedPtr sub_path_;
        Path::ConstSharedPtr path_;
};
#endif  // PATH_SUBSCRIBER_HPP_