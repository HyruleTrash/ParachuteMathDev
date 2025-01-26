#include <cmath>
#include "./CollisionTest.h"
#include "CollisionTest.h"
#include "../../../../MathUtil/Util.cpp"

using namespace Parachute;

CollisionTest::CollisionTest(Object *a, Object *b)
{
    this->a = a;
    this->b = b;
}

CollisionTestResult CollisionTest::TestAABB()
{
    if (
        a->bounds.R_Side.x + a->position.x > b->bounds.L_Side.x + b->position.x &&
        a->bounds.L_Side.x + a->position.x < b->bounds.R_Side.x + b->position.x &&
        a->bounds.T_Side.y + a->position.y < b->bounds.B_Side.y + b->position.y &&
        a->bounds.B_Side.y + a->position.y > b->bounds.T_Side.y + b->position.y)
    {
        Vector2 collisionNormalA{a->bounds.GetClosestNormal(a->position, b->position, &b->bounds)};
        std::cout << collisionNormalA << std::endl;
        Vector2 collisionNormalB{-collisionNormalA};

        return CollisionTestResult{true, collisionNormalA, collisionNormalB};
    }
    else
        return CollisionTestResult{false, V2_ZERO, V2_ZERO};
}