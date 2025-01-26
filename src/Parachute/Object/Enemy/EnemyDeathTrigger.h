#pragma once
#include "../Body/RigidBody/RigidBody.h"
#include "./Enemy.h"

namespace Parachute
{
    class EnemyDeathTrigger : public RigidBody
    {
    private:
    public:
        EnemyDeathTrigger() = default;
        EnemyDeathTrigger(Game *);
        ~EnemyDeathTrigger() = default;
        GameState GetGameState() override;
        void OnTriggerEntered(Body *other) override;
    };
}