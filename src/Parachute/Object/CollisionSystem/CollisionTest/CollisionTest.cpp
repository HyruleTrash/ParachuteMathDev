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
        a->position.x + (a->size.x / 2) > b->position.x - (b->size.x / 2) &&
        a->position.x - (a->size.x / 2) < b->position.x + (b->size.x / 2) &&
        a->position.y - (a->size.y / 2) < b->position.y + (b->size.y / 2) &&
        a->position.y + (a->size.y / 2) > b->position.y - (b->size.y / 2))
    {
        Vector2 collisionNormalA{};
        Vector2 collisionNormalB{};

        Vector2 directionTowards = GetDirection(a->position, b->position);
        directionTowards.x = SnapDirectionToEightDirections(directionTowards.x);
        directionTowards.y = SnapDirectionToEightDirections(directionTowards.y);

        collisionNormalA = directionTowards;
        collisionNormalB = -collisionNormalA;

        return CollisionTestResult{true, collisionNormalA, collisionNormalB};
    }
    else
        return CollisionTestResult{false, V2_ZERO, V2_ZERO};
}