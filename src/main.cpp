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
    body->AddForce(MathUtil::Vector2{2, 2});

    while (game.window.isOpen())
    {
        game.window.clear();
        game.Update();
        while (const std::optional event = game.window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                game.window.close();
        }

        game.window.display();
    }
}