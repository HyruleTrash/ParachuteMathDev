#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "./RigidBody.h"
#include "../../../../MathUtil/Util.cpp"
#include "RigidBody.h"

using namespace Parachute;

RigidBody::RigidBody()
{
}

RigidBody::~RigidBody()
{
}

void RigidBody::Update()
{
    if (totalForce.GetMagnitude() != 0 && mass != 0)
    {
        timeSinceForceChange += game->time.deltaTime;
        Vector2 force{totalForce * timeSinceForceChange};

        double maxVelocityMagnitude{MathUtil::GetMagnitude(MAX_VELOCITY)};
        Vector2 nextVelocity{MathUtil::GetNextVelocity(velocity, force, mass)};
        if (nextVelocity.GetMagnitude() > maxVelocityMagnitude)
        {
            nextVelocity.Normalize() * maxVelocityMagnitude;
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
    }

    Body::Update();
}

void Parachute::RigidBody::AddForce(Vector2 force)
{
    totalForce += force;
    timeSinceForceChange = 0;
}