#pragma once
#include <string>
#include <chrono>

namespace Parachute
{
    /// @brief The input class holds relevant information regarding specific Inputs. such as when it was last held and released.
    class Input
    {
    public:
        Input() = default;
        Input(Input *input) : Input(input->name, input->isPressed) {}
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
