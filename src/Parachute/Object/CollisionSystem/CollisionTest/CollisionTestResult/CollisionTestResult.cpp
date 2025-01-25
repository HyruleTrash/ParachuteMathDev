#include "./CollisionTestResult.h"

using namespace Parachute;

CollisionTestResult::CollisionTestResult(bool result, Vector2 a, Vector2 b)
{
    this->result = result;
    this->collisionNormalA = a;
    this->collisionNormalB = b;
}