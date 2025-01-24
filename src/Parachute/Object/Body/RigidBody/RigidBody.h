#pragma once
#include "../Body.cpp"

namespace Parachute
{
    class RigidBody : public Body
    {
    private:
        constexpr static Vector2 MAX_VELOCITY{200, 200};
        Vector2 totalForce{V2_ZERO};
        Vector2 totalImpulses{V2_ZERO};

    public:
        RigidBody();
        ~RigidBody();
        void Update() override;
        void AddForce(Vector2 force);
        void AddImpulse(Vector2 impulse);
        Vector2 velocity{V2_ZERO};
        double timeSinceForceChange;
        float mass{1};
    };
}