#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "./MathUtil/Util.cpp"
#include "./Parachute/Game/Game.cpp"
#include "./Parachute/Object/Body/RigidBody/RigidBody.cpp"

int main()
{
    Parachute::Game game{};

    Parachute::RigidBody *body = new Parachute::RigidBody();
    body->size = MathUtil::Vector2{40, 40};
    body->game = &game;
    game.objectManager.Initialize(body, game.GetResolution() / 2);
    // body->AddImpulse(MathUtil::Vector2{2000, 2000});

    while (game.window.isOpen())
    {
        game.window.clear();
        game.Update();

        if (game.inputManager.IsKeyJustPressed("Left"))
        {
            body->AddForce(V2_LEFT);
        }
        if (game.inputManager.IsKeyJustReleased("Left"))
        {
            body->AddForce(-V2_LEFT);
        }

        if (game.inputManager.IsKeyJustPressed("Right"))
        {
            body->AddForce(V2_RIGHT);
        }
        if (game.inputManager.IsKeyJustReleased("Right"))
        {
            body->AddForce(-V2_RIGHT);
        }

        if (game.inputManager.IsKeyJustPressed("Up"))
        {
            body->AddForce(V2_UP);
        }
        if (game.inputManager.IsKeyJustReleased("Up"))
        {
            body->AddForce(-V2_UP);
        }

        if (game.inputManager.IsKeyJustPressed("Down"))
        {
            body->AddForce(V2_DOWN);
        }
        if (game.inputManager.IsKeyJustReleased("Down"))
        {
            body->AddForce(-V2_DOWN);
        }

        while (const std::optional event = game.window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                game.window.close();
        }

        game.window.display();
    }
}