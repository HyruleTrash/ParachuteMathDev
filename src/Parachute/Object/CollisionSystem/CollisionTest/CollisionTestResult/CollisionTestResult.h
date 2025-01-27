#pragma once
#include "../../../../../MathUtil/Vector2/Vector2.cpp"

namespace Parachute
{
    /// @brief Holds the result after a collision test. The collision normals representing the side that was hit
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
