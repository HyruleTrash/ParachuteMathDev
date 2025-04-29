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
        static const Vector2 MAX_VELOCITY;
        static const Vector2 MIN_VELOCITY;
        Vector2 forces{Vector2::ZERO};
        Vector2 impulses{Vector2::ZERO};
        Vector2 forcesPreviousFrame{Vector2::ZERO};
        Vector2 impulsesPreviousFrame{Vector2::ZERO};

    public:
        RigidBody() = default;
        ~RigidBody() = default;
        void Update() override;
        void AddForce(Vector2 force);
        void AddImpulse(Vector2 impulse);
        void OnColliding(Body *other, Vector2 collisionNormal);
        Vector2 velocity{Vector2::ZERO};
    };
}