#pragma once
#include <SFML/System/Clock.hpp>
#include <SFML/System/Time.hpp>

namespace Parachute
{
    class Time
    {
    private:
        sf::Clock* clock;
    public:
        Time();
        ~Time();
        void Update();
        float deltaTime;
    };
}