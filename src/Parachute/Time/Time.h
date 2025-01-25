#pragma once
#include <chrono>

namespace Parachute
{
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