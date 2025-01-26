#pragma once
#include "../Body.cpp"

namespace Parachute
{
    class RigidBody : public Body
    {
    private:
        constexpr static Vector2 MAX_VELOCITY{200, 200};
        constexpr static Vector2 MIN_VELOCITY{0.001, 0.001};
        Vector2 forces{V2_ZERO};
        Vector2 impulses{V2_ZERO};
        Vector2 forcesPreviousFrame{V2_ZERO};
        Vector2 impulsesPreviousFrame{V2_ZERO};

    public:
        RigidBody() = default;
        ~RigidBody() = default;
        void Update() override;
        void AddForce(Vector2 force);
        void AddImpulse(Vector2 impulse);
        void OnColliding(Body *other, Vector2 collisionNormal);
        Vector2 velocity{V2_ZERO};
    };
}