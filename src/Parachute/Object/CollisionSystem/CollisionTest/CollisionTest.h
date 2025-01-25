#pragma once
#include <vector>
#include "../../Object.cpp"
#include "./CollisionTestResult/CollisionTestResult.cpp"

namespace Parachute
{
    class CollisionTest
    {
    public:
        CollisionTest() = default;
        CollisionTest(Object *, Object *);
        ~CollisionTest() = default;
        CollisionTestResult TestAABB();
        Object *a{};
        Object *b{};
    };
}
