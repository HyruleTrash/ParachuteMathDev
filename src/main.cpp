#include <SFML/Graphics.hpp>
#include "./Parachute/Game/Game.cpp"

int main()
{
    sf::RenderWindow window(sf::VideoMode({400, 400}), "Midnight Motorist");

    Parachute::Game game{};
    while (window.isOpen())
    {
        window.clear();
        game.Update();
        while (const std::optional event = window.pollEvent())
        {
            if (event->is<sf::Event::Closed>())
                window.close();
        }

        window.display();
    }
}