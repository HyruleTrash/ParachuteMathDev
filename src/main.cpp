#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "./MathUtil/Util.cpp"
#include "./Parachute/Game/Game.cpp"
#include "./Parachute/Object/Body/StaticBody/StaticBody.cpp"

int main()
{
    Parachute::Game game{};

    Parachute::StaticBody *body = new Parachute::StaticBody();
    body->size = MathUtil::Vector2{10, 10};
    body->game = &game;
    game.objectManager.Initialize(body, game.GetResolution() / 2);

    Parachute::StaticBody *bodyC = new Parachute::StaticBody();
    bodyC->size = MathUtil::Vector2{10, 10};
    bodyC->game = &game;
    game.objectManager.Initialize(bodyC, game.GetResolution() / 2);

    Parachute::StaticBody *bodyR = new Parachute::StaticBody();
    bodyR->size = MathUtil::Vector2{10, 10};
    bodyR->game = &game;
    game.objectManager.Initialize(bodyR, (game.GetResolution() / 2) + MathUtil::DegreeToNormalVector(0) * 100);
    Parachute::StaticBody *bodyU = new Parachute::StaticBody();
    bodyU->size = MathUtil::Vector2{10, 10};
    bodyU->game = &game;
    game.objectManager.Initialize(bodyU, (game.GetResolution() / 2) + MathUtil::DegreeToNormalVector(90) * 100);
    Parachute::StaticBody *bodyL = new Parachute::StaticBody();
    bodyL->size = MathUtil::Vector2{10, 10};
    bodyL->game = &game;
    game.objectManager.Initialize(bodyL, (game.GetResolution() / 2) + MathUtil::DegreeToNormalVector(180) * 100);
    Parachute::StaticBody *bodyB = new Parachute::StaticBody();
    bodyB->size = MathUtil::Vector2{10, 10};
    bodyB->game = &game;
    game.objectManager.Initialize(bodyB, (game.GetResolution() / 2) + MathUtil::DegreeToNormalVector(-90) * 100);

    double degree = 0;
    double speed = 30;
    while (game.window.isOpen())
    {
        game.window.clear();

        degree += game.time.deltaTime * speed;
        if (degree >= 360)
            degree -= round(fmod(degree, 360)) * 360;
        body->position = (game.GetResolution() / 2) + MathUtil::DegreeToNormalVector(degree) * 100;

        game.Update();
        while (const std::optional event = game.window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                game.window.close();
        }

        game.window.display();
    }
}