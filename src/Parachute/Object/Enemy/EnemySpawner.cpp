#pragma once
#include "EnemySpawner.h"
#include "../../../MathUtil/Util.cpp"

using namespace Parachute;

EnemySpawner::EnemySpawner(Game *game)
{
    this->game = game;
    this->activeStates.push_back(GameState::Playing);
    this->activeStates.push_back(GameState::Pauzed);
}

void EnemySpawner::Update()
{
    Object::Update();

    if (visable)
    {
        timer += game->time.deltaTime;
        if (timer > spawnInterval)
        {
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
