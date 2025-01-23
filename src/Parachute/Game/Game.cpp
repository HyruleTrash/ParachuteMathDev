#pragma once
#include "./Game.h"

using namespace Parachute;

Game::Game(int width, int height)
{
    resolution = Vector2{width, height};
    time = Time();
    sf::Vector2u outputRes{static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)};
    window = sf::RenderWindow(sf::VideoMode(outputRes), "Midnight Motorist", sf::Style::Close);
}

Game::Game() : Game(400, 400)
{
}

Game::Game(Vector2 resolution) : Game((int)resolution.x, (int)resolution.y)
{
}

Game::~Game()
{
}

void Game::Update()
{
    time.Update();
    objectManager.Update();
}

Vector2 Game::GetResolution()
{
    return Vector2{this->resolution};
}