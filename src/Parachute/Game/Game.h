#pragma once
#include "../Time/Time.cpp"

namespace Parachute
{
    class Game
    {
    public:
        Game();
        ~Game();
        void Update();
        Time time;
    };
} // namespace Parachute
