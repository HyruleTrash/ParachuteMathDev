#pragma once
#include <SFML/Graphics.hpp>
#include <optional>
#include "GameState.h"
#include "Time.h"
#include "ObjectManager.h"
#include "InputManager.h"
#include "Input.h"
#include "Text.h"

namespace Parachute
{
    /// @brief The game class overall holds all game information, and scenic logic
    class Game
    {
    private:
        void GetInputs();
        MathUtil::Vector2 resolution;
        float points{0};
        float totalPoints{0};
        constexpr static float HIGH_SCORE{200};
        Object *pointCounterObject;

    public:
        Game(int width, int height);
        Game() : Game(400, 400) {};
        Game(MathUtil::Vector2 resolution) : Game((int)resolution.x, (int)resolution.y) {}
        ~Game() = default;
        void Update();
        MathUtil::Vector2 GetResolution();
        void ChangeGameState(GameState);
        void RemovePoints(double);
        Time time{};
        sf::RenderWindow window;
        GameState gameState{GameState::Start};
        ObjectManager objectManager{};
        InputManager inputManager{};
    };
}
