#pragma once
#include "../Body.cpp"

namespace Parachute
{
    class RigidBody : public Body
    {
    private:
        constexpr static Vector2 MAX_VELOCITY{200, 200};
        Vector2 forces{V2_ZERO};
        Vector2 impulses{V2_ZERO};

    public:
        RigidBody() = default;
        ~RigidBody() = default;
        void Update() override;
        void AddForce(Vector2 force);
        void AddImpulse(Vector2 impulse);
        void OnCollided(Body *other, Vector2 collisionNormal);
        void OnCollisionEnded(Body *other, IntersectionData);
        Vector2 velocity{V2_ZERO};
    };
}