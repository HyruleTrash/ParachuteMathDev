#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "./RigidBody.h"
#include "../../../../MathUtil/Util.cpp"

using namespace Parachute;

RigidBody::RigidBody()
{
}

RigidBody::~RigidBody()
{
}

void RigidBody::Update()
{
    timeSinceForceChange += game->time.deltaTime;
    Vector2 acceleration{1, 1};

    double maxVelocityMagnitude{MathUtil::GetMagnitude(MAX_VELOCITY)};
    Vector2 nextVelocity{MathUtil::GetNextVelocity(velocity, acceleration, timeSinceForceChange)};
    if (nextVelocity.GetMagnitude() > maxVelocityMagnitude)
    {
        nextVelocity.Normalize() * maxVelocityMagnitude;
        timeSinceForceChange = 0;
    }

    Vector2 offset{MathUtil::GetPositionOffset(nextVelocity, velocity, timeSinceForceChange)};
    position += offset;

    // temp looping
    if (position.x - size.x / 2 >= game->GetResolution().x)
        position.x = 0 - size.x / 2;
    if (position.x + size.x / 2 < 0 - size.x / 2)
        position.x = game->GetResolution().x + size.x / 2;
    if (position.y - size.y / 2 >= game->GetResolution().y)
        position.y = 0 - size.y / 2;
    if (position.y + size.y / 2 < 0 - size.y / 2)
        position.y = game->GetResolution().y + size.y / 2;

    Body::Update();
}