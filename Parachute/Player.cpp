#include "./Player.h"

using namespace Parachute;

Player::Player()
{
    size = Vector2{40, 40};
    mass = 15;
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
        AddImpulse(Vector2::LEFT * speed);
    }

    if (game->inputManager.IsKeyBeingPressed("Right"))
    {
        AddImpulse(Vector2::RIGHT * speed);
    }

    if (game->inputManager.IsKeyBeingPressed("Up"))
    {
        AddImpulse(Vector2::UP * speed);
    }

    if (game->inputManager.IsKeyBeingPressed("Down"))
    {
        AddImpulse(Vector2::DOWN * speed);
    }
}