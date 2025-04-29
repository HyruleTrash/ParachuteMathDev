#pragma once
#include <vector>
#include "CollisionTest.h"
#include "Object.h"
#include "Body.h"
#include "../MathUtil/Util.h"

namespace Parachute
{
    class CollisionSystem
    {
    public:
        CollisionSystem() = default;
        ~CollisionSystem() = default;
        void Update(std::vector<Object *>);
        std::vector<CollisionTest> SortBasedOnDistance(std::vector<Object *>);
    };
}
