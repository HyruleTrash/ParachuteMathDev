#pragma once
#include <SFML/Graphics.hpp>
#include "./GameState.h"
#include "../Time/Time.cpp"
#include "../Object/ObjectManager.cpp"
#include "./InputManager/InputManager.cpp"

namespace Parachute
{
    class Game
    {
    private:
        void GetInputs();
        MathUtil::Vector2 resolution;
        double points{0};
        double totalPoints{0};
        constexpr static double HIGH_SCORE{200};
        Object *pointCounterObject;

    public:
        Game(int width, int height);
        Game() : Game(400, 400) {};
        Game(Vector2 resolution) : Game((int)resolution.x, (int)resolution.y) {};
        ~Game() = default;
        void Update();
        Vector2 GetResolution();
        void ChangeGameState(GameState);
        void RemovePoints(double);
        Time time{};
        sf::RenderWindow window;
        GameState gameState{GameState::Start};
        ObjectManager objectManager{};
        InputManager inputManager{};
    };
}
