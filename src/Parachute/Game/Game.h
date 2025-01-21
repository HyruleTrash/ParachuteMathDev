#pragma once
#include "../Time/Time.cpp"
#include "../Object/ObjectManager.cpp"

namespace Parachute
{
    class Game
    {
    public:
        Game();
        ~Game();
        void Update();
        Time time;
        
        enum GameState {
            Start,
            Playing,
            Pauzed,
            End
        };
    };
} // namespace Parachute
