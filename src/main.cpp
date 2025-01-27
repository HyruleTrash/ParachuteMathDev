#include <SFML/Graphics.hpp>
#include <iostream>
#include <cmath>
#include "./MathUtil/Util.cpp"
#include "./Parachute/Game/Game.cpp"
#include "./Parachute/Object/Body/RigidBody/RigidBody.cpp"
#include "./Parachute/Object/Body/StaticBody/StaticBody.cpp"

int main()
{
    // Create game
    Parachute::Game game{};

    // Make a loop that is run, alwaysm until the game closes
    while (game.window.isOpen())
    {
        game.window.clear();
        game.Update();
        game.window.display();
    }
}