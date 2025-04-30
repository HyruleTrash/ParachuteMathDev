#include "./CollisionTestResult.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    
    CollisionTestResult::CollisionTestResult(bool result, Vector2 a, Vector2 b)
    {
        this->result = result;
        this->collisionNormalA = a;
        this->collisionNormalB = b;
    }
}