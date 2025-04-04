#include <navigation_pkg/NaviPublisher.hpp>

using namespace std::chrono_literals;

namespace ssy263_amd
{
    NaviPublisher::NaviPublisher(): Node("navi_publisher"), count_(0)
    {
        publisher_ = this->create_publisher<navi_interfaces::msg::Coord2d>("navi_topic", 10);
        timer_ = this->create_wall_timer(
        500ms, std::bind(&NaviPublisher::publish_callback, this));
    }
    
    NaviPublisher::~NaviPublisher()
    {

    }

    void NaviPublisher::publish_callback()
    {
        auto message = navi_interfaces::msg::Coord2d();
        message.x = this->count_++;
        message.y = 0.0;
        RCLCPP_INFO_STREAM(this->get_logger(), "Publishing: '" << message.x << "," << message.y <<"'");
        publisher_->publish(message);
    }
}