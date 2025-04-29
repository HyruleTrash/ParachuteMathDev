#pragma once
#include <iostream>
#include "Vector2.h"

namespace MathUtil
{
    class Physics
    {
    private:
    public:
        Physics() = default;
        ~Physics() = default;
        static Vector2 GetNextVelocity(Vector2 initialVelocity, Vector2 totalForce, double mass, double time);
        static Vector2 GetPositionOffset(Vector2 nextVelocity, Vector2 initialVelocity, double time);
        constexpr static double AIR_DRAG{10};
    };
}