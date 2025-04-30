#pragma once
#include <iostream>
#include "Body.h"

namespace Parachute
{
    /// @brief Static bodies only exist to be in your way, doesn't move is only used for collisions. Such as walls
    class StaticBody : public Body
    {
    public:
        StaticBody() = default;
        StaticBody(MathUtil::Vector2 size, Game *);
        ~StaticBody() = default;
        void Update() override;
        double GetDensity() override;
        float bouncyness{0.8};
    };
}