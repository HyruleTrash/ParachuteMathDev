#pragma once
#include "./Physics.h"
#include <cmath>
#include "Physics.h"

using namespace MathUtil;

/// @brief Returns the velocity that should be applied upcoming frame based on the already existing velocity
/// @param initialVelocity
/// @param totalForce
/// @param mass
/// @param time
/// @return
Vector2 Physics::GetNextVelocity(Vector2 initialVelocity, Vector2 totalForce, double mass, double time)
{
    Vector2 acceleration{totalForce / mass};
    return Vector2{initialVelocity + acceleration * time};
}

/// @brief Returns a offset vector2 that should be applied on the body/objects position. This is based on its velocity.
/// @param nextVelocity
/// @param initialVelocity
/// @param time
/// @return
Vector2 Physics::GetPositionOffset(Vector2 nextVelocity, Vector2 initialVelocity, double time)
{
    return Vector2{((nextVelocity + initialVelocity) / 2) * time};
}