#pragma once
#include "EnemySpawner.h"
#include "../../../MathUtil/Util.cpp"

using namespace Parachute;

EnemySpawner::EnemySpawner(Game *game)
{
    this->game = game;
    this->activeStates.push_back(GameState::Playing);
}

void EnemySpawner::Update()
{
    Object::Update();

    // when enebled increment a timer variable in till it passes a threshold.
    if (visable)
    {
        timer += game->time.deltaTime;
        if (timer > spawnInterval)
        {
            // spawn enemy and reset the timer
            timer = 0;
            Enemy *enemy = new Enemy(game);
            game->objectManager.Initialize(enemy, Vector2{MathUtil::RandomRange(spawnOffset, game->GetResolution().x - spawnOffset), spawnOffset});
        }
    }
}

GameState EnemySpawner::GetGameState()
{
    return game->gameState;
}
