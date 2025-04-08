#include <navigation_pkg/NaviSubscriber.hpp>

using std::placeholders::_1;

namespace ssy263_amd
{
    NaviSubscriber::NaviSubscriber(): Node("navi_subscriber")
    {
        subscriber_ = this->create_subscription<navi_interfaces::msg::Coord2d>(
            "navi_topic", 10, std::bind(&NaviSubscriber::subscriber_callback, this, _1));
    }
    
    NaviSubscriber::~NaviSubscriber()
    {

    }

    void NaviSubscriber::subscriber_callback(const navi_interfaces::msg::Coord2d & msg) const
    {
        RCLCPP_INFO_STREAM(this->get_logger(), "x: " << msg.x << "; " << "y: " << msg.y);
    }
}