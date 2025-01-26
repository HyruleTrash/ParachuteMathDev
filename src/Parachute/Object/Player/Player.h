#pragma once
#include "../Body/RigidBody/RigidBody.h"
#include "../Enemy/Enemy.h"

namespace Parachute
{
    class Player : public RigidBody
    {
    private:
        constexpr static Vector2 DEFAULT_PLAYER_SIZE{40, 40};
        constexpr static float DEFAULT_PLAYER_MASS{5};

    public:
        Player();
        Player(Game *);
        ~Player() = default;
        void Update() override;
        void OnColliding(Body *other, Vector2 collisionNormal) override;
        double speed{0.4};
    };
}