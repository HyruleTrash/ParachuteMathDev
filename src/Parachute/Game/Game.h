#pragma once
#include "../Time/Time.cpp"
#include "../Object/ObjectManager.cpp"

namespace Parachute
{
    class Game
    {
    public:
        enum class GameState
        {
            Start,
            Playing,
            Pauzed,
            End
        };
        Game();
        ~Game();
        void Update();
        Time time{};
        GameState gameState{GameState::Start};
        ObjectManager objectManager{};
    };
}
