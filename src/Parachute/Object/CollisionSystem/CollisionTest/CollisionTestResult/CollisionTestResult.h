#pragma once
#include "../../../../../MathUtil/Vector2/Vector2.cpp"

namespace Parachute
{
    class CollisionTestResult
    {
    public:
        CollisionTestResult() = default;
        CollisionTestResult(bool, Vector2, Vector2);
        ~CollisionTestResult() = default;
        bool result;
        Vector2 collisionNormalA{};
        Vector2 collisionNormalB{};
    };
}
