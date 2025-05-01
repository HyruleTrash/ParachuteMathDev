#include "Game.h"
#include "Player.h"
#include "StaticBody.h"
#include "EnemySpawner.h"
#include "EnemyDeathTrigger.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    
    Game::Game(int width, int height)
    {
        resolution = Vector2{width, height};
        time = Time();
        sf::Vector2u outputRes{static_cast<unsigned int>(resolution.x), static_cast<unsigned int>(resolution.y)};
        window = sf::RenderWindow(sf::VideoMode(outputRes), "Midnight Motorist", sf::Style::Close);
        ChangeGameState(GameState::Start);
    }

    /// @brief Updates/adds used keybinds
    void Parachute::Game::GetInputs()
    {
        inputManager.AddInput(Input{"Left", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left)});
        inputManager.AddInput(Input{"Right", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right)});
        inputManager.AddInput(Input{"Up", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up)});
        inputManager.AddInput(Input{"Down", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down)});
        inputManager.AddInput(Input{"Escape", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)});
        inputManager.AddInput(Input{"Enter", sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Enter)});
    }

    /// @brief The main update loop that runs every frame and calls all other game systems
    void Game::Update()
    {
        this->GetInputs();
        time.Update();
        objectManager.Update();

        // once the window event close button has been recieved, close the window
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        // closes the game once the Escape key is pressed
        if (inputManager.IsKeyJustPressed("Escape"))
        {
            window.close();
        }

        // When the game's state is the start menu, and Enter is pressed. Begin the game.
        if (gameState == GameState::Start && inputManager.IsKeyJustPressed("Enter"))
        {
            ChangeGameState(GameState::Playing);
        }

        // When the game is running count up points, and display them
        if (gameState == GameState::Playing)
        {
            points += time.deltaTime;
            totalPoints += time.deltaTime;
            Text *pointCounterText = dynamic_cast<Text *>(pointCounterObject);
            pointCounterText->text = MathUtil::Util::IntToStringWithZeros((int)round(points), 3);
        }

        // Logic for the game end screen, also responds to the Win/Lose condition
        if (gameState == GameState::End)
        {
            Text *pointCounterText = dynamic_cast<Text *>(pointCounterObject);
            pointCounterText->text = "Points: " + MathUtil::Util::IntToStringWithZeros((int)round(totalPoints), 3);
            if (inputManager.IsKeyJustPressed("Enter"))
            {
                points = 0;
                totalPoints = 0;
                ChangeGameState(GameState::Playing);
            }
        }
    }

    /// @brief retrieves the used window resolution
    /// @return
    Vector2 Game::GetResolution()
    {
        return Vector2{this->resolution};
    }

    /// @brief Contains the logic when the game's state is changed.
    /// Adds relative game objects and clears the old ones
    /// @param state
    void Game::ChangeGameState(GameState state)
    {
        gameState = state;

        objectManager.ClearObjects();

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

            // Adds the level walls
            const float wallOffset{0.95};
            StaticBody *RightWall = new StaticBody{resolution, this};
            RightWall->activeStates.push_back(GameState::Playing);
            objectManager.Initialize(RightWall, Vector2{(resolution.x / 2) + resolution.x * wallOffset, resolution.y / 2});
            StaticBody *LeftWall = new StaticBody{Vector2{resolution}, this};
            LeftWall->activeStates.push_back(GameState::Playing);
            objectManager.Initialize(LeftWall, Vector2{(resolution.x / 2) - resolution.x * wallOffset, resolution.y / 2});
            StaticBody *TopWall = new StaticBody{resolution, this};
            TopWall->activeStates.push_back(GameState::Playing);
            objectManager.Initialize(TopWall, Vector2{resolution.x / 2, (resolution.y / 2) - resolution.y});
            StaticBody *BottomWall = new StaticBody{Vector2{resolution}, this};
            BottomWall->activeStates.push_back(GameState::Playing);
            objectManager.Initialize(BottomWall, Vector2{resolution.x / 2, (resolution.y / 2) + resolution.y});

            // Enemy logics
            EnemySpawner *enemySpawner = new EnemySpawner{this};
            objectManager.Initialize(enemySpawner, Vector2::ZERO);
            EnemyDeathTrigger *deathTrigger = new EnemyDeathTrigger{this};
            objectManager.Initialize(deathTrigger, Vector2{resolution.x / 2, (resolution.y / 2) + resolution.y * wallOffset});

            // score displays
            Text *pointCounter = new Text{sf::Color::White, 40, "000", this};
            pointCounter->activeStates.push_back(GameState::Playing);
            objectManager.Initialize(pointCounter, Vector2{resolution.x * 0.1, resolution.y * 0.1});
            pointCounterObject = pointCounter;

            Text *fakeHighscore = new Text{sf::Color::Green, 30, "HS: " + std::to_string((int)HIGH_SCORE), this};
            fakeHighscore->activeStates.push_back(GameState::Playing);
            objectManager.Initialize(fakeHighscore, Vector2{resolution.x * 0.15, resolution.y * 0.2});
        }
        else if (state == GameState::End)
        {
            _CrtDumpMemoryLeaks();
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

    /// @brief Holds the game end logic, and lets an outside class interact with the points of the user
    /// @param toRemove
    void Game::RemovePoints(double toRemove)
    {
        points -= toRemove;
        if (points < 0)
            ChangeGameState(GameState::End);
    }
}