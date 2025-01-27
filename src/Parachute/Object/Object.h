#pragma once
#include <vector>
#include "../../MathUtil/Vector2/Vector2.cpp"
#include "./Bounds/Bounds.cpp"
#include "../Game/GameState.h"

namespace Parachute
{
    // forward declaration of Game object
    class Game;

    /// @brief Game object, used to keep track of all in game objects
    class Object
    {
    private:
    public:
        Object() = default;
        ~Object() = default;
        virtual void Update();
        virtual GameState GetGameState() { return GameState::Start; };
        bool visable{true};
        bool checkGameState{true};
        Game *game;
        Vector2 position{};
        Vector2 size{};
        Bounds bounds;
        std::vector<GameState> activeStates{};
    };
}