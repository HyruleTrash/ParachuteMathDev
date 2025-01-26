#pragma once
#include <algorithm>
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include "./RigidBody.h"
#include "../StaticBody/StaticBody.cpp"
#include "../../../../MathUtil/Physics.cpp"
#include "../../../../MathUtil/Util.cpp"
#include "RigidBody.h"

using namespace Parachute;

Force::Force(Force *other)
{
    this->force = other->force;
    this->other = other->other;
}

Force::Force(Vector2 force, Body *other)
{
    this->force = force;
    this->other = other;
}

Vector2 Force::GetSum(std::vector<Force> &forces)
{
    Vector2 result{};
    for (auto forceData : forces)
        result += forceData.force;
    return result;
}

bool Force::Contains(std::vector<Force> &forces, Vector2 force, Body *other)
{
    for (auto forceData : forces)
    {
        if (forceData.force == force && forceData.other == other)
            return true;
    }

    return false;
}

void Force::RemoveNegated(std::vector<Force> &forces)
{
    std::vector<Force> toRemove{};
    // for (size_t i = 0; i < forces.size(); i++)
    // {
    //     Vector2 negationVector{-forces[i].force};
    //     for (size_t j = 0; j < forces.size(); j++)
    //     {
    //         if (-forces[j].force == negationVector)
    //         {
    //             toRemove.push_back(Force{forces[j]});
    //             toRemove.push_back(Force{forces[i]});
    //         }
    //     }
    // }

    for (auto force : toRemove)
    {
        for (int i = forces.size() - 1; i >= 0; i--)
        {
            if (forces[i].force == force.force && forces[i].other == force.other)
            {
                forces.erase(forces.begin() + i);
                break;
            }
        }
    }
}

void RigidBody::Update()
{
    // prepare forces
    Force::RemoveNegated(forces);
    Force::RemoveNegated(impulses);
    Vector2 totalForce{Force::GetSum(forces)};
    Vector2 totalImpulses{Force::GetSum(impulses)};

    // if it has a mass, and is supposed to be moving
    if (mass != 0 && ((totalForce.GetMagnitude() != 0 || totalImpulses.GetMagnitude() != 0) || velocity != V2_ZERO))
    {
        // add drag if body has velocity
        if (velocity.GetMagnitude() != 0)
        {
            totalForce += -velocity.Normalize() * MathUtil::Physics::AIR_DRAG;
        }

        Vector2 nextVelocity{MathUtil::Physics::GetNextVelocity(velocity, totalForce, mass, game->time.deltaTime)};

        nextVelocity += totalImpulses;

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

    if (totalForce.GetMagnitude() == 0 && totalImpulses.GetMagnitude() == 0)
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
    this->AddForce(force, this);
}

void RigidBody::AddImpulse(Vector2 impulse)
{
    this->AddImpulse(impulse, this);
}

void RigidBody::AddForce(Vector2 force, Body *other)
{
    if (!Force::Contains(forces, force, other))
        forces.push_back(Force{force, other});
}

void RigidBody::AddImpulse(Vector2 impulse, Body *other)
{
    if (!Force::Contains(impulses, impulse, other))
        impulses.push_back(Force{impulse, other});
}

void RigidBody::OnCollided(Body *other, Vector2 collisionNormal)
{
    double density = other->density;
    AddImpulse(collisionNormal * density, other);
}

void RigidBody::OnCollisionEnded(Body *other, IntersectionData data)
{
    Body *oldData = dynamic_cast<Body *>(data.intersectorOldData);
    double density = oldData->density;
    AddImpulse(-data.appliedNormalVector * density, other);
}
