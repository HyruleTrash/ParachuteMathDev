#pragma once
#include "./Game.h"
#include "../Object/Text/Text.cpp"
#include "../Object/Player/Player.cpp"
#include "../Object/Enemy/EnemySpawner.cpp"
#include "../Object/Enemy/EnemyDeathTrigger.cpp"
#include "../Object/Body/StaticBody/StaticBody.cpp"
#include "Game.h"

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

    if (inputManager.IsKeyJustPressed("Escape"))
    {
        window.close();
    }

    if (gameState == GameState::Start && inputManager.IsKeyJustPressed("Enter"))
    {
        ChangeGameState(GameState::Playing);
    }
    if (gameState == GameState::Playing)
    {
        points += time.deltaTime;
        totalPoints += time.deltaTime;
        Text *pointCounterText = dynamic_cast<Text *>(pointCounterObject);
        pointCounterText->text = intToStringWithZeros((int)round(points), 3);
    }
    if (gameState == GameState::End)
    {
        Text *pointCounterText = dynamic_cast<Text *>(pointCounterObject);
        pointCounterText->text = "Points: " + intToStringWithZeros((int)round(totalPoints), 3);
        if (inputManager.IsKeyJustPressed("Enter"))
        {
            points = 0;
            totalPoints = 0;
            ChangeGameState(GameState::Playing);
        }
    }
}

Vector2 Game::GetResolution()
{
    return Vector2{this->resolution};
}

void Game::ChangeGameState(GameState state)
{
    gameState = state;

    if (state != GameState::Pauzed)
    {
        objectManager.ClearObjects();
    }

    if (state == GameState::Start)
    {
        Text *startText = new Text{sf::Color::White, 40, "Press ENTER\nto Start", this};
        startText->activeStates.push_back(GameState::Start);
        objectManager.Initialize(startText, Vector2{resolution.x / 2, resolution.y * 0.75});
    }
    else if (state == GameState::Playing)
    {
        Player *player = new Player{this};
        objectManager.Initialize(player, Vector2{resolution.x / 2, resolution.y * 0.9});

        const float wallOffset{0.95};
        StaticBody *RightWall = new StaticBody{resolution, this};
        RightWall->activeStates.push_back(GameState::Playing);
        RightWall->activeStates.push_back(GameState::Pauzed);
        objectManager.Initialize(RightWall, Vector2{(resolution.x / 2) + resolution.x * wallOffset, resolution.y / 2});
        StaticBody *LeftWall = new StaticBody{Vector2{resolution}, this};
        LeftWall->activeStates.push_back(GameState::Playing);
        LeftWall->activeStates.push_back(GameState::Pauzed);
        objectManager.Initialize(LeftWall, Vector2{(resolution.x / 2) - resolution.x * wallOffset, resolution.y / 2});
        StaticBody *TopWall = new StaticBody{resolution, this};
        TopWall->activeStates.push_back(GameState::Playing);
        TopWall->activeStates.push_back(GameState::Pauzed);
        objectManager.Initialize(TopWall, Vector2{resolution.x / 2, (resolution.y / 2) - resolution.y});
        StaticBody *BottomWall = new StaticBody{Vector2{resolution}, this};
        BottomWall->activeStates.push_back(GameState::Playing);
        BottomWall->activeStates.push_back(GameState::Pauzed);
        objectManager.Initialize(BottomWall, Vector2{resolution.x / 2, (resolution.y / 2) + resolution.y});

        EnemySpawner *enemySpawner = new EnemySpawner{this};
        objectManager.Initialize(enemySpawner, V2_ZERO);
        EnemyDeathTrigger *deathTrigger = new EnemyDeathTrigger{this};
        objectManager.Initialize(deathTrigger, Vector2{resolution.x / 2, (resolution.y / 2) + resolution.y * wallOffset});

        Text *pointCounter = new Text{sf::Color::White, 40, "000", this};
        pointCounter->activeStates.push_back(GameState::Playing);
        pointCounter->activeStates.push_back(GameState::Pauzed);
        objectManager.Initialize(pointCounter, Vector2{resolution.x * 0.1, resolution.y * 0.1});
        pointCounterObject = pointCounter;

        Text *fakeHighscore = new Text{sf::Color::Green, 30, "HS: " + std::to_string((int)HIGH_SCORE), this};
        fakeHighscore->activeStates.push_back(GameState::Playing);
        fakeHighscore->activeStates.push_back(GameState::Pauzed);
        objectManager.Initialize(fakeHighscore, Vector2{resolution.x * 0.15, resolution.y * 0.2});
    }
    else if (state == GameState::End)
    {
        Text *pointCounter = new Text{sf::Color::White, 30, "000", this};
        pointCounter->activeStates.push_back(GameState::End);
        objectManager.Initialize(pointCounter, Vector2{resolution.x / 2, resolution.y * 0.3});
        pointCounterObject = pointCounter;

        std::string resultText = totalPoints > HIGH_SCORE ? "You won!!" : "Press ENTER\nto retry";
        Text *endText = new Text{sf::Color::White, 40, resultText, this};
        endText->activeStates.push_back(GameState::End);
        objectManager.Initialize(endText, Vector2{resolution.x / 2, resolution.y * 0.5});
    }
}

void Game::RemovePoints(double toRemove)
{
    points -= toRemove;
    if (points < 0)
        ChangeGameState(GameState::End);
}
