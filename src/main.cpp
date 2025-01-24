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
            body->AddImpulse(MathUtil::Vector2{-100, 0});
        }
        if (game.inputManager.IsKeyJustReleased("Left"))
        {
            body->AddImpulse(MathUtil::Vector2{100, 0});
        }

        if (game.inputManager.IsKeyJustPressed("Right"))
        {
            body->AddImpulse(MathUtil::Vector2{100, 0});
        }
        if (game.inputManager.IsKeyJustReleased("Right"))
        {
            body->AddImpulse(MathUtil::Vector2{-100, 0});
        }

        if (game.inputManager.IsKeyJustPressed("Up"))
        {
            body->AddImpulse(MathUtil::Vector2{0, -100});
        }
        if (game.inputManager.IsKeyJustReleased("Up"))
        {
            body->AddImpulse(MathUtil::Vector2{0, 100});
        }

        if (game.inputManager.IsKeyJustPressed("Down"))
        {
            body->AddImpulse(MathUtil::Vector2{0, 100});
        }
        if (game.inputManager.IsKeyJustReleased("Down"))
        {
            body->AddImpulse(MathUtil::Vector2{0, -100});
        }

        while (const std::optional event = game.window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                game.window.close();
        }

        game.window.display();
    }
}