#pragma once
#include <string>
#include <chrono>

namespace Parachute
{
    class Input
    {
    public:
        Input() = default;
        Input(Input *);
        Input(std::string);
        Input(std::string, bool);
        ~Input() = default;
        std::string name{""};
        bool isPressed{};
        std::chrono::time_point<std::chrono::high_resolution_clock> pressTimeStamp{};
        std::chrono::time_point<std::chrono::high_resolution_clock> releaseTimeStamp{};
        constexpr static double JUSTPRESSED_THRESHOLD{1};
    };
}
