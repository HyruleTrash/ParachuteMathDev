#pragma once
#include "../Body.cpp"

namespace Parachute
{
    class RigidBody : public Body
    {
    private:
        constexpr static Vector2 MAX_VELOCITY{200, 200};

    public:
        RigidBody();
        ~RigidBody();
        void Update() override;
        Vector2 velocity{};
        Vector2 force{};
        double timeSinceForceChange;
        float mass{};
    };
}