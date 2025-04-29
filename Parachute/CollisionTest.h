#pragma once
#include <vector>
#include "CollisionTestResult.h"
#include "Object.h"

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
