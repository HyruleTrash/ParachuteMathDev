#include <SFML/Graphics.hpp>
#include "MathUtil/Util.h"
#include "Parachute/Game.h"

int main()
{
    Parachute::Game game{};

    while (game.window.isOpen())
    {
        game.window.clear();
        game.Update();
        game.window.display();
    }
}