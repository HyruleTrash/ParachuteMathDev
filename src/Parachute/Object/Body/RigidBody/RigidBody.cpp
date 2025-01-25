#pragma once
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "./RigidBody.h"
#include "../StaticBody/StaticBody.cpp"
#include "../../../../MathUtil/Physics.cpp"
#include "../../../../MathUtil/Util.cpp"
#include "RigidBody.h"

using namespace Parachute;

void RigidBody::Update()
{
    // if it has a mass, and is supposed to be moving
    if (mass != 0 && ((forces.GetMagnitude() != 0 || impulses.GetMagnitude() != 0) || velocity != V2_ZERO))
    {
        Vector2 totalForce{forces};

        // add drag if body has velocity
        if (velocity.GetMagnitude() != 0)
        {
            totalForce += -velocity.Normalize() * MathUtil::Physics::AIR_DRAG;
        }

        Vector2 nextVelocity{MathUtil::Physics::GetNextVelocity(velocity, totalForce, mass, game->time.deltaTime)};

        nextVelocity += impulses;

        // Limit Velocity, for terminal velocity
        const double maxVelocityMagnitude{MathUtil::GetMagnitude(MAX_VELOCITY)};
        double nextVelocityMagnitude = nextVelocity.GetMagnitude();
        if (nextVelocityMagnitude > maxVelocityMagnitude)
        {
            nextVelocity = nextVelocity.Normalize() * maxVelocityMagnitude;
        }

        Vector2 offset{MathUtil::Physics::GetPositionOffset(nextVelocity, velocity, game->time.deltaTime)};
        position += offset;

        velocity = nextVelocity;
    }

    if (forces.GetMagnitude() == 0 && impulses.GetMagnitude() == 0)
    {
        if (abs(velocity.x) < 1)
            velocity.x = 0;
        if (abs(velocity.y) < 1)
            velocity.y = 0;
    }

    Body::Update();
}

void RigidBody::AddForce(Vector2 force)
{
    forces += force;
}

void RigidBody::AddImpulse(Vector2 impulse)
{
    impulses += impulse;
}

void RigidBody::OnCollided(Body *other, Vector2 collisionNormal)
{
    double density = other->density;
    AddImpulse(collisionNormal * density);
}

void RigidBody::OnCollisionEnded(Body *other, IntersectionData data)
{
    Body *oldData = dynamic_cast<Body *>(data.intersectorOldData);
    double density = oldData->density;
    AddImpulse(-data.appliedNormalVector * density);
}
