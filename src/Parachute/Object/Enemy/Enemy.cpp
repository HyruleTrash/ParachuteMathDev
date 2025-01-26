#pragma once
#include <cmath>
#include "./Enemy.h"
#include "../../../MathUtil/Util.cpp"
#include "Enemy.h"

using namespace Parachute;

Enemy::Enemy()
{
    size = DEFAULT_ENEMY_SIZE;
    mass = DEFAULT_ENEMY_MASS;
    spawnTimeStamp = std::chrono::high_resolution_clock::now();
    collisionEnabled = false;
    this->activeStates.push_back(GameState::Playing);
    this->activeStates.push_back(GameState::Pauzed);
    int randomColorIndex = (int)round(RandomRange(1, sizeof(colors) / sizeof(colors[0]))) - 1;
    color = colors[randomColorIndex];
}

Enemy::Enemy(Game *game) : Enemy()
{
    this->game = game;
}

void Enemy::Update()
{
    RigidBody::Update();

    // move down
    AddForce(V2_DOWN * speed);

    // To and fro movement
    if (RandomRange(-100, 100) > 50)
        AddImpulse(V2_LEFT * RandomRange(-5, 5));

    // ignore the top bounding box, enable collision after having been in game
    if (!collisionEnabled)
    {
        auto now = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::duration<double>>(now - spawnTimeStamp).count() > wakeUpThreshold)
            collisionEnabled = true;
    }
}
void Enemy::OnColliding(Body *other, Vector2 collisionNormal)
{
    if (dynamic_cast<Player *>(other) != nullptr)
    {
        game->objectManager.Delete(this);
        return;
    }
    RigidBody::OnColliding(other, collisionNormal);
}