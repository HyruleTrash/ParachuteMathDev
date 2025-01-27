#include "EnemyDeathTrigger.h"

Parachute::EnemyDeathTrigger::EnemyDeathTrigger(Game *game)
{
    this->game = game;
    this->isTrigger = true;
    this->activeStates.push_back(GameState::Playing);
    this->size = game->GetResolution();
}

GameState Parachute::EnemyDeathTrigger::GetGameState()
{
    return game->gameState;
}

/// @brief On enemy entered, trigger logic
/// @param other
void Parachute::EnemyDeathTrigger::OnTriggerEntered(Body *other)
{
    if (dynamic_cast<Enemy *>(other) != nullptr && other->collisionEnabled)
    {
        game->objectManager.Delete(other);
        return;
    }
}
