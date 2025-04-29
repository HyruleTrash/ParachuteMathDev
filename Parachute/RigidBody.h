#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Body.h"
#include "StaticBody.h"
#include "../MathUtil/Physics.h"
#include "../MathUtil/Util.h"

namespace Parachute
{
    class RigidBody : public Body
    {
    private:
        constexpr static Vector2 MAX_VELOCITY{200, 200};
        constexpr static Vector2 MIN_VELOCITY{0.001, 0.001};
        Vector2 forces{MathUtil::V2_ZERO};
        Vector2 impulses{MathUtil::V2_ZERO};
        Vector2 forcesPreviousFrame{MathUtil::V2_ZERO};
        Vector2 impulsesPreviousFrame{MathUtil::V2_ZERO};

    public:
        RigidBody() = default;
        ~RigidBody() = default;
        void Update() override;
        void AddForce(Vector2 force);
        void AddImpulse(Vector2 impulse);
        void OnColliding(Body *other, Vector2 collisionNormal);
        Vector2 velocity{MathUtil::V2_ZERO};
    };
}