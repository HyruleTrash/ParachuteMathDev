#pragma once
#include "./Physics.h"
#include <cmath>
#include "Physics.h"

using namespace MathUtil;

Vector2 Physics::GetNextVelocity(Vector2 initialVelocity, Vector2 totalForce, double mass, double time)
{
    Vector2 acceleration{totalForce / mass};
    return Vector2{initialVelocity + acceleration * time};
}

Vector2 Physics::GetPositionOffset(Vector2 nextVelocity, Vector2 initialVelocity, double time)
{
    return Vector2{((nextVelocity + initialVelocity) / 2) * time};
}