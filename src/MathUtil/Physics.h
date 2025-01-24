#pragma once
#include <type_traits>
#include <iostream>
#include "./Vector2/Vector2.cpp"

namespace MathUtil
{
    class Physics
    {
    private:
    public:
        Physics() = default;
        ~Physics() = default;
        static Vector2 GetNextVelocity(Vector2 initialVelocity, Vector2 totalForce, double mass);
        static Vector2 GetPositionOffset(Vector2 nextVelocity, Vector2 initialVelocity, double time);
        constexpr static double AIR_DRAG{500};
    };
}