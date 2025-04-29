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
        AddImpulse(MathUtil::V2_LEFT * speed);
    }

    if (game->inputManager.IsKeyBeingPressed("Right"))
    {
        AddImpulse(MathUtil::V2_RIGHT * speed);
    }

    if (game->inputManager.IsKeyBeingPressed("Up"))
    {
        AddImpulse(MathUtil::V2_UP * speed);
    }

    if (game->inputManager.IsKeyBeingPressed("Down"))
    {
        AddImpulse(MathUtil::V2_DOWN * speed);
    }
}