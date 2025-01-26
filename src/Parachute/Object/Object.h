#pragma once
#include <vector>
#include "../../MathUtil/Vector2/Vector2.cpp"
#include "./Bounds/Bounds.cpp"
#include "../Game/GameState.h"

namespace Parachute
{
    class Game;

    class Object
    {
    private:
    public:
        Object() = default;
        ~Object() = default;
        virtual void Update();
        virtual GameState GetGameState() { return GameState::Start; };
        bool visable{true};
        Game *game;
        Vector2 position{};
        Vector2 size{};
        Bounds bounds;
        std::vector<GameState> activeStates{};
    };
}