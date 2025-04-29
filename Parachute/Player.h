#pragma once
#include "Game.h"
#include "RigidBody.h"

namespace Parachute
{
    class Player : public RigidBody
    {
    public:
        Player();
        Player(Game *);
        ~Player() = default;
        void Update() override;
        double speed{0.4};
    };
}