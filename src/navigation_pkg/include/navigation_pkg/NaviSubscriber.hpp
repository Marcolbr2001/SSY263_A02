#ifndef NAVI_SUBSCRIBER_HPP
#define NAVI_SUBSCRIBER_HPP

#include <cstdio>
#include <chrono>
#include <memory>
#include <string>

#include "rclcpp/rclcpp.hpp"
#include "navi_interfaces/msg/coord2d.hpp"

namespace ssy263_amd
{
    class NaviSubscriber : public rclcpp::Node
    {
        public:
            NaviSubscriber();
            ~NaviSubscriber();

        private:
            void subscriber_callback(const navi_interfaces::msg::Coord2d & msg) const; 

            rclcpp::Subscription<navi_interfaces::msg::Coord2d>::SharedPtr subscriber_;
    };
}

#endif