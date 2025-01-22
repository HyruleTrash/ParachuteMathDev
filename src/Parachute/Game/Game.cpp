#pragma once
#include "./Game.h"

using namespace Parachute;

Game::Game()
{
    time = Time();
    window = sf::RenderWindow(sf::VideoMode({400, 400}), "Midnight Motorist");
}

Game::~Game()
{
}

void Game::Update()
{
    time.Update();
    objectManager.Update();
}