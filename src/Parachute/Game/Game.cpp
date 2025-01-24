#pragma once
#include "./Game.h"
#include "Game.h"

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

void Parachute::Game::GetInputs()
{
    inputManager.AddInput(Input{"Left", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)});
    inputManager.AddInput(Input{"Right", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)});
    inputManager.AddInput(Input{"Up", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)});
    inputManager.AddInput(Input{"Down", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)});
}

void Game::Update()
{
    this->GetInputs();
    time.Update();
    objectManager.Update();
}

Vector2 Game::GetResolution()
{
    return Vector2{this->resolution};
}