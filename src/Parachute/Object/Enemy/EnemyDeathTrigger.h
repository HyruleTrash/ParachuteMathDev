#pragma once
#include "../Body/RigidBody/RigidBody.h"
#include "./Enemy.h"

namespace Parachute
{
    /// @brief Simple trigger object, removes enemies from the game once the come into contact
    class EnemyDeathTrigger : public RigidBody
    {
    public:
        EnemyDeathTrigger() = default;
        EnemyDeathTrigger(Game *);
        ~EnemyDeathTrigger() = default;
        GameState GetGameState() override;
        void OnTriggerEntered(Body *other) override;
    };
}