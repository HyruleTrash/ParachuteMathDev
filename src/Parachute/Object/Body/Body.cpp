#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "./Body.h"
#include "../../Game/Game.h"

using namespace Parachute;

Body::Body()
{
}

Body::~Body()
{
}

void Body::Update()
{
    if (visable)
    {
        sf::RectangleShape shape({(float)size.x, (float)size.y});
        shape.setFillColor(sf::Color::Green);
        Vector2 origin{size / 2};
        shape.setOrigin({(float)origin.x, (float)origin.y});
        sf::Vector2f pos{(float)position.x, (float)position.y};
        shape.setPosition(pos);
        game->window.draw(shape);
    }
}