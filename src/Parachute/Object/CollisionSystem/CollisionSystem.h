#pragma once
#include <vector>
#include "./CollisionTest/CollisionTest.cpp"
#include "../../../MathUtil/Util.cpp"

namespace Parachute
{
    class CollisionSystem
    {
    public:
        CollisionSystem() = default;
        ~CollisionSystem() = default;
        void Update(std::vector<Object *>);
        std::vector<CollisionTest> SortBasedOnDistance(std::vector<Object *>);
        void ApplyCollision(Object *, Object *, CollisionTestResult);
    };
}
