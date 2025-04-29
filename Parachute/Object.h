#pragma once
#include <vector>
#include "../MathUtil/Vector2.h"
#include "Bounds.h"
#include "GameState.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    class Game;

    class Object
    {
    private:
    public:
        Object() = default;
        ~Object() = default;
        virtual void Update();
        virtual GameState GetGameState() { return GameState::Start; };
        bool visible{true};
        Game *game;
        Vector2 position{};
        Vector2 size{};
        Bounds bounds;
        std::vector<GameState> activeStates{};
    };
}