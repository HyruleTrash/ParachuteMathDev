#pragma once
#include "Game.h"
#include "RigidBody.h"

namespace Parachute
{
    /// @brief Lets the user interact with their own physics based object
    class Player : public RigidBody
    {
    private:
        constexpr static MathUtil::Vector2 DEFAULT_PLAYER_SIZE{40, 40};
        constexpr static float DEFAULT_PLAYER_MASS{5};

    public:
        Player();
        Player(Game *);
        ~Player() = default;
        void Update() override;
        void OnColliding(Body *other, MathUtil::Vector2 collisionNormal) override;
        double speed{0.4};
    };
}