#pragma once
#include "./Game.h"
#include "../Object/Text/Text.cpp"
#include "../Object/Player/Player.cpp"
#include "../Object/Body/StaticBody/StaticBody.cpp"

using namespace Parachute;

Game::Game(int width, int height)
{
    resolution = Vector2{width, height};
    time = Time();
    sf::Vector2u outputRes{static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)};
    window = sf::RenderWindow(sf::VideoMode(outputRes), "Midnight Motorist", sf::Style::Close);
    ChangeGameState(GameState::Start);
}

void Parachute::Game::GetInputs()
{
    inputManager.AddInput(Input{"Left", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)});
    inputManager.AddInput(Input{"Right", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)});
    inputManager.AddInput(Input{"Up", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)});
    inputManager.AddInput(Input{"Down", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)});
    inputManager.AddInput(Input{"Escape", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)});
    inputManager.AddInput(Input{"Enter", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)});
}

void Game::Update()
{
    this->GetInputs();
    time.Update();
    objectManager.Update();

    while (const std::optional event = window.pollEvent())
    {
        if (event->is<sf::Event::Closed>())
            window.close();
    }

    if (gameState == GameState::Start && inputManager.IsKeyJustPressed("Enter"))
    {
        ChangeGameState(GameState::Playing);
    }
}

Vector2 Game::GetResolution()
{
    return Vector2{this->resolution};
}

void Game::ChangeGameState(GameState state)
{
    gameState = state;

    if (state == GameState::Start)
    {
        Text *startText = new Text{sf::Color::White, 40, "Press ENTER\nto Start", this};
        startText->activeStates.push_back(GameState::Start);
        objectManager.Initialize(startText, Vector2{resolution.x / 2, resolution.y * 0.75});
    }
    else if (state == GameState::Playing)
    {
        Player *player = new Player{this};
        player->activeStates.push_back(GameState::Playing);
        player->activeStates.push_back(GameState::Pauzed);
        objectManager.Initialize(player, Vector2{resolution.x / 2, resolution.y * 0.75});

        const double wallThickness{80};
        StaticBody *RightWall = new StaticBody{Vector2{wallThickness, wallThickness}, this};
        RightWall->activeStates.push_back(GameState::Playing);
        RightWall->activeStates.push_back(GameState::Pauzed);
        // objectManager.Initialize(RightWall, Vector2{resolution.x + wallThickness / 2, resolution.y / 2});
        objectManager.Initialize(RightWall, Vector2{resolution.x * 0.75, resolution.y / 2});
        StaticBody *LeftWall = new StaticBody{Vector2{wallThickness, resolution.y}, this};
        LeftWall->activeStates.push_back(GameState::Playing);
        LeftWall->activeStates.push_back(GameState::Pauzed);
        objectManager.Initialize(LeftWall, Vector2{0 - wallThickness / 2, resolution.y / 2});
    }
}
