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

    while (game.window.isOpen())
    {
        game.window.clear();
        game.Update();
        game.window.display();
    }
}