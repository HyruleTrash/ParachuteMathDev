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
    // // if it has a mass, and is supposed to be moving
    // std::cout << velocity << ", " << position << std::endl;
    if (mass != 0 && ((forces.GetMagnitude() != 0 || impulses.GetMagnitude() != 0) || velocity != V2_ZERO))
    {
        Vector2 totalForce{forces};

        // add drag if body has velocity
        if (velocity.GetMagnitude() != 0)
        {
            totalForce += -velocity.Normalize() * MathUtil::Physics::AIR_DRAG;
        }

        Vector2 nextVelocity{MathUtil::Physics::GetNextVelocity(velocity, totalForce, mass, game->time.deltaTime)};

        nextVelocity += impulses / mass;

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

        // reset forces
        forces = V2_ZERO;
        impulses = V2_ZERO;
    }

    if (forces.GetMagnitude() == 0 && impulses.GetMagnitude() == 0)
    {
        if (abs(velocity.x) < MIN_VELOCITY.x)
            velocity.x = 0;
        if (abs(velocity.y) < MIN_VELOCITY.x)
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

void RigidBody::OnColliding(Body *other, Vector2 collisionNormal)
{
    double density = other->density; // currently goes unused, can be used for thick air, or fluids

    // base collision
    Vector2 toRemove{collisionNormal * Dot(velocity, collisionNormal)};
    AddImpulse(-toRemove);

    // friction
    if (impulses.GetMagnitude() != 0 && abs(Dot(impulses.Normalize(), collisionNormal)) < 1)
    {
        Vector2 frictionDir{impulses.Normalize() - (collisionNormal * Dot(impulses.Normalize(), collisionNormal))};
        AddImpulse(-frictionDir * impulses.GetMagnitude() * other->friction);
    }
    if (forces.GetMagnitude() != 0 && abs(Dot(forces.Normalize(), collisionNormal)) < 1)
    {
        Vector2 frictionDir{forces.Normalize() - (collisionNormal * Dot(forces.Normalize(), collisionNormal))};
        AddForce(-frictionDir * forces.GetMagnitude() * other->friction);
    }

    if (dynamic_cast<StaticBody *>(other) != nullptr)
    {
        const double bouncyness{0.25};
        AddImpulse(collisionNormal * velocity.GetMagnitude() * bouncyness);
    }
    else if (dynamic_cast<RigidBody *>(other) != nullptr)
    {
        RigidBody *otherRb = dynamic_cast<RigidBody *>(other);
        otherRb->AddImpulse(-collisionNormal * velocity.GetMagnitude() * mass);
    }
}
