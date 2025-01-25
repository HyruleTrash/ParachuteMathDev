#pragma once
#include "../../MathUtil/Vector2/Vector2.cpp"
#include "./Bounds/Bounds.cpp"

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
        bool visable{true};
        Game *game;
        Vector2 position{};
        Vector2 size{};
        Bounds bounds;
    };
}