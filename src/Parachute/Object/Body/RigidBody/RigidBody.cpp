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
    // if it has a mass, and is supposed to be moving
    if (mass != 0 && ((totalForce.GetMagnitude() != 0 || totalImpulses.GetMagnitude() != 0) || velocity != V2_ZERO))
    {
        // force to acceleration
        timeSinceForceChange += game->time.deltaTime;
        Vector2 force{totalForce * timeSinceForceChange};
        force += totalImpulses * game->time.deltaTime;

        const double maxVelocityMagnitude{MathUtil::GetMagnitude(MAX_VELOCITY)};

        Vector2 nextVelocity{MathUtil::GetNextVelocity(velocity, force, mass)};
        if (nextVelocity.GetMagnitude() > maxVelocityMagnitude)
        {
            nextVelocity.Normalize() * maxVelocityMagnitude;
        }

        Vector2 offset{MathUtil::GetPositionOffset(nextVelocity, velocity, game->time.deltaTime)};
        position += offset;

        velocity = nextVelocity;
    }

    if (totalForce.GetMagnitude() == 0 && totalImpulses.GetMagnitude() == 0)
    {
        timeSinceForceChange = 0;
        if (abs(velocity.x) < 1)
            velocity.x = 0;
        if (abs(velocity.y) < 1)
            velocity.y = 0;
    }

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

void RigidBody::AddForce(Vector2 force)
{
    totalForce += force;
    timeSinceForceChange = 0;
}

void RigidBody::AddImpulse(Vector2 impulse)
{
    totalImpulses += impulse;
}
