#pragma once
#include "../Body/RigidBody/RigidBody.h"

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
        double speed{0.4};
    };
}