#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>
#include "./StaticBody.h"

using namespace Parachute;

Parachute::StaticBody::StaticBody(Vector2 size, Game *game)
{
    this->size = size;
    this->game = game;
}

void StaticBody::Update()
{
    Body::Update();
}

double StaticBody::GetDensity()
{
    return INFINITY;
}