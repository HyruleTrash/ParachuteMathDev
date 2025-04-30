#pragma once
#include <chrono>

namespace Parachute
{
    /// @brief Logs the application start time, then calculates the time it takes between each frame, every frame
    class Time
    {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
        double runTime{0};

    public:
        Time();
        ~Time() = default;
        void Update();
        float deltaTime;
    };
}