#pragma once
#include <cmath>
#include <SFML/Graphics.hpp>
#include "Body.h"
#include "StaticBody.h"
#include "../MathUtil/Physics.h"
#include "../MathUtil/Util.h"

namespace Parachute
{
    /// @brief Base physics body, moves depending on the forces applied to it
    class RigidBody : public Body
    {
    private:
        static const MathUtil::Vector2 MAX_VELOCITY;
        static const MathUtil::Vector2 MIN_VELOCITY;
        MathUtil::Vector2 forces{MathUtil::Vector2::ZERO};
        MathUtil::Vector2 impulses{MathUtil::Vector2::ZERO};

    public:
        RigidBody() = default;
        ~RigidBody() = default;
        void Update() override;
        double CollisionOffset() override;
        void AddForce(MathUtil::Vector2 force);
        void AddImpulse(MathUtil::Vector2 impulse);
        void OnColliding(Body *other, MathUtil::Vector2 collisionNormal);
        MathUtil::Vector2 velocity{MathUtil::Vector2::ZERO};
    };
}