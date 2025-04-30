#pragma once
#include "../MathUtil/Vector2.h"

namespace Parachute
{
    /// @brief Holds the result after a collision test. The collision normals representing the side that was hit
    class CollisionTestResult
    {
    public:
        CollisionTestResult() = default;
        CollisionTestResult(bool, MathUtil::Vector2, MathUtil::Vector2);
        ~CollisionTestResult() = default;
        bool result;
        MathUtil::Vector2 collisionNormalA{};
        MathUtil::Vector2 collisionNormalB{};
    };
}
