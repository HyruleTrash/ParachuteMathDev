#pragma once
#include <chrono>

namespace Parachute
{
    class Time
    {
    private:
        std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
        double runTime;
    public:
        Time();
        ~Time();
        void Update();
        float deltaTime;
    };
}