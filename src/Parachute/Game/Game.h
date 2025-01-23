#pragma once
#include <SFML/Graphics.hpp>
#include "../Time/Time.cpp"
#include "../Object/ObjectManager.cpp"

namespace Parachute
{
    class Game
    {
    private:
        MathUtil::Vector2 resolution;

    public:
        enum class GameState
        {
            Start,
            Playing,
            Pauzed,
            End
        };
        Game(int width, int height);
        Game();
        Game(Vector2 resolution);
        ~Game();
        void Update();
        Vector2 GetResolution();
        Time time{};
        sf::RenderWindow window;
        GameState gameState{GameState::Start};
        ObjectManager objectManager{};
    };
}
