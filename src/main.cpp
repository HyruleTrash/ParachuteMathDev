#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "./MathUtil/Util.cpp"
#include "./Parachute/Game/Game.cpp"
#include "./Parachute/Object/Body/RigidBody/RigidBody.cpp"
#include "./Parachute/Object/Body/StaticBody/StaticBody.cpp"

int main()
{
    Parachute::Game game{};

    Parachute::RigidBody *body = new Parachute::RigidBody();
    body->size = MathUtil::Vector2{40, 40};
    body->mass = 20;
    body->game = &game;
    game.objectManager.Initialize(body, game.GetResolution() / 2);
    const double speed = 0.4;

    Parachute::StaticBody *temp = new Parachute::StaticBody();
    temp->size = MathUtil::Vector2{40, 40};
    temp->game = &game;
    temp->friction = 0.7;
    game.objectManager.Initialize(temp, body->position + MathUtil::Vector2{(game.GetResolution() / 4).x, 0.0});
    Parachute::RigidBody *tempTwo = new Parachute::RigidBody();
    tempTwo->size = MathUtil::Vector2{40, 40};
    tempTwo->mass = body->mass;
    tempTwo->game = &game;
    game.objectManager.Initialize(tempTwo, body->position + MathUtil::Vector2{0.0, (game.GetResolution() / 4).x});

    while (game.window.isOpen())
    {
        game.window.clear();
        game.Update();

        if (game.inputManager.IsKeyBeingPressed("Left"))
        {
            body->AddImpulse(V2_LEFT * speed);
        }

        if (game.inputManager.IsKeyBeingPressed("Right"))
        {
            body->AddImpulse(V2_RIGHT * speed);
        }

        if (game.inputManager.IsKeyBeingPressed("Up"))
        {
            body->AddImpulse(V2_UP * speed);
        }

        if (game.inputManager.IsKeyBeingPressed("Down"))
        {
            body->AddImpulse(V2_DOWN * speed);
        }

        while (const std::optional event = game.window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                game.window.close();
        }

        game.window.display();
    }
}