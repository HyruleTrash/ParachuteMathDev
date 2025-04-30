#include "RigidBody.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    
    const Vector2 RigidBody::MAX_VELOCITY{200, 200};
    const Vector2 RigidBody::MIN_VELOCITY{0.001, 0.001};

    void RigidBody::Update()
    {
        // // if it has a mass, and is supposed to be moving
        if (mass != 0 && ((forces.GetMagnitude() != 0 || impulses.GetMagnitude() != 0) || velocity != Vector2::ZERO))
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
            const double maxVelocityMagnitude{MathUtil::Util::GetMagnitude(MAX_VELOCITY)};
            double nextVelocityMagnitude = nextVelocity.GetMagnitude();
            if (nextVelocityMagnitude > maxVelocityMagnitude)
            {
                nextVelocity = nextVelocity.Normalize() * maxVelocityMagnitude;
            }

            Vector2 offset{MathUtil::Physics::GetPositionOffset(nextVelocity, velocity, game->time.deltaTime)};
            position += offset;

            velocity = nextVelocity;

            // reset forces
            forces = Vector2::ZERO;
            impulses = Vector2::ZERO;
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

    /// @brief Used for collision distance sorting, checkout the collision system class for more
    /// @return
    double RigidBody::CollisionOffset()
    {
        return velocity.GetMagnitude();
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
        if (!collisionEnabled)
            return;

        double density = other->density; // currently goes unused, can be used for thick air, or fluids

        // base collision repelant force, to make sure neither bodies are intersecting
        Vector2 toRemove{collisionNormal * MathUtil::Util::Dot(velocity, collisionNormal)};
        AddImpulse(-toRemove);

        // friction
        if (impulses.GetMagnitude() != 0 && abs(MathUtil::Util::Dot(impulses.Normalize(), collisionNormal)) < 1)
        {
            Vector2 frictionDir{impulses.Normalize() - (collisionNormal * MathUtil::Util::Dot(impulses.Normalize(), collisionNormal))};
            AddImpulse(-frictionDir * impulses.GetMagnitude() * other->friction);
        }
        if (forces.GetMagnitude() != 0 && abs(MathUtil::Util::Dot(forces.Normalize(), collisionNormal)) < 1)
        {
            Vector2 frictionDir{forces.Normalize() - (collisionNormal * MathUtil::Util::Dot(forces.Normalize(), collisionNormal))};
            AddForce(-frictionDir * forces.GetMagnitude() * other->friction);
        }

        // apply repelant force, depends on body type
        if (dynamic_cast<StaticBody *>(other) != nullptr)
        {
            StaticBody *otherStaticBody = dynamic_cast<StaticBody *>(other);
            AddImpulse(collisionNormal * velocity.GetMagnitude() * otherStaticBody->bouncyness);
        }
        else if (dynamic_cast<RigidBody *>(other) != nullptr)
        {
            RigidBody *otherRb = dynamic_cast<RigidBody *>(other);
            otherRb->AddImpulse(-collisionNormal * velocity.GetMagnitude() * mass);
        }
    }
}
