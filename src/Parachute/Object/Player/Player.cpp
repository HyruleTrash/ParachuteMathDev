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
    if (visable)
    {
        if (game->inputManager.IsKeyBeingPressed("Left"))
        {
            AddImpulse(V2_LEFT * speed);
        }

        if (game->inputManager.IsKeyBeingPressed("Right"))
        {
            AddImpulse(V2_RIGHT * speed);
        }

        // temp wheels for my terrible looking car
        Vector2 sizeWheel{size.x / 3, size.y / 2};
        sf::RectangleShape shape({(float)sizeWheel.x, (float)sizeWheel.y});
        shape.setFillColor(sf::Color{100, 100, 100});
        Vector2 origin{sizeWheel / 2};
        shape.setOrigin({(float)origin.x, (float)origin.y});
        sizeWheel *= Vector2{1.1, 0.9};
        sf::Vector2f pos{(float)(position.x - sizeWheel.x), (float)(position.y - sizeWheel.y)};
        shape.setPosition(pos);
        game->window.draw(shape);
        pos = sf::Vector2f{(float)(position.x - sizeWheel.x), (float)(position.y + sizeWheel.y)};
        shape.setPosition(pos);
        game->window.draw(shape);
        pos = sf::Vector2f{(float)(position.x + sizeWheel.x), (float)(position.y + sizeWheel.y)};
        shape.setPosition(pos);
        game->window.draw(shape);
        pos = sf::Vector2f{(float)(position.x + sizeWheel.x), (float)(position.y - sizeWheel.y)};
        shape.setPosition(pos);
        game->window.draw(shape);
    }
    RigidBody::Update();
    if (visable)
    {
        // temp window for my terrible looking car
        Vector2 sizeWindow{size.x / 1.2, size.y / 2};
        sf::RectangleShape shape({(float)sizeWindow.x, (float)sizeWindow.y});
        shape.setFillColor(sf::Color{100, 100, 255});
        Vector2 origin{sizeWindow / 2};
        shape.setOrigin({(float)origin.x, (float)origin.y});
        sizeWindow *= Vector2{0.0, 0.8};
        sf::Vector2f pos{(float)(position.x - sizeWindow.x), (float)(position.y - sizeWindow.y)};
        shape.setPosition(pos);
        game->window.draw(shape);
    }
}
void Player::OnColliding(Body *other, Vector2 collisionNormal)
{
    if (dynamic_cast<Enemy *>(other) != nullptr)
    {
        game->RemovePoints(10);
        game->objectManager.Delete(other);
        return;
    }
    RigidBody::OnColliding(other, collisionNormal);
}