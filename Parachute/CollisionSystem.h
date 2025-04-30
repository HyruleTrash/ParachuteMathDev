#pragma once
#include <vector>
#include "CollisionTest.h"
#include "Object.h"
#include "../MathUtil/Util.h"

namespace Parachute
{
    /// @brief Loops through all objects, and checks whatever any are colliding
    class CollisionSystem
    {
    public:
        CollisionSystem() = default;
        ~CollisionSystem() = default;
        void Update(std::vector<Object *>);
        std::vector<CollisionTest> SortBasedOnDistance(std::vector<Object *>);
    };
}
