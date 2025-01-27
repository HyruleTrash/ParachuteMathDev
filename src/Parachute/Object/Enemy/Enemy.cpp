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

    // pick a random color
    int randomColorIndex = (int)round(RandomRange(1, sizeof(colors) / sizeof(colors[0]))) - 1;
    color = colors[randomColorIndex];

    // pick a random direction
    directionLeft = (int)round(RandomRange(-1, 1)) == 0;
}

Enemy::Enemy(Game *game) : Enemy()
{
    this->game = game;
}

void Enemy::Update()
{
    RigidBody::Update();

    // move down
    AddForce(V2_DOWN * speed.y);

    // To and fro movement
    if (directionLeft)
        AddForce(V2_LEFT * speed.x);
    else
        AddForce(V2_RIGHT * speed.x);

    // to ignore the top bounding box, enable collision after having been in game for a certain amount of time
    if (!collisionEnabled)
    {
        auto now = std::chrono::high_resolution_clock::now();
        if (std::chrono::duration_cast<std::chrono::duration<double>>(now - spawnTimeStamp).count() > wakeUpThreshold)
            collisionEnabled = true;
    }
}

/// @brief On collision with the player, remove self to avoid any other collision logic from occuring
/// @param other
/// @param collisionNormal
void Enemy::OnColliding(Body *other, Vector2 collisionNormal)
{
    if (dynamic_cast<Player *>(other) != nullptr)
    {
        game->objectManager.Delete(this);
        return;
    }
    RigidBody::OnColliding(other, collisionNormal);
}

void Enemy::OnCollided(Body *other, Vector2 collisionNormal)
{
    if (collisionNormal == V2_LEFT)
    {
        directionLeft = false;
    }
    else if (collisionNormal == V2_RIGHT)
    {
        directionLeft = true;
    }
}
