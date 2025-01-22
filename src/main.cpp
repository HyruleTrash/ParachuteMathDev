#include <SFML/Graphics.hpp>
#include "./Parachute/Game/Game.cpp"
#include "./Parachute/Object/Body/StaticBody/StaticBody.cpp"

int main()
{
    Parachute::Game game{};
    Parachute::StaticBody *body = new Parachute::StaticBody();
    body->size = MathUtil::Vector2{10, 10};
    body->game = &game;
    game.objectManager.Initialize(body, MathUtil::Vector2{10, 10});
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