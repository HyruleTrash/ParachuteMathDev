#pragma once
#include "./Player.h"
#include "Player.h"

using namespace Parachute;

Player::Player()
{
    size = DEFAULT_PLAYER_SIZE;
    mass = DEFAULT_PLAYER_MASS;
    this->activeStates.push_back(GameState::Playing);
    this->activeStates.push_back(GameState::Pauzed);
}

Player::Player(Game *game) : Player()
{
    this->game = game;
}

void Player::Update()
{
    RigidBody::Update();

    if (game->inputManager.IsKeyBeingPressed("Left"))
    {
        AddImpulse(V2_LEFT * speed);
    }

    if (game->inputManager.IsKeyBeingPressed("Right"))
    {
        AddImpulse(V2_RIGHT * speed);
    }

    // Leave for later possible use
    // if (game->inputManager.IsKeyBeingPressed("Up"))
    // {
    //     AddImpulse(V2_UP * speed);
    // }

    // if (game->inputManager.IsKeyBeingPressed("Down"))
    // {
    //     AddImpulse(V2_DOWN * speed);
    // }
}
void Player::OnColliding(Body *other, Vector2 collisionNormal)
{
    if (dynamic_cast<Enemy *>(other) != nullptr)
    {
        game->ChangeGameState(GameState::End);
        return;
    }
    RigidBody::OnColliding(other, collisionNormal);
}