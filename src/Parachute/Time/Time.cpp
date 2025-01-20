#include "./Time.h"

using namespace Parachute;

Time::Time()
{
    sf::Clock* n_clock = new sf::Clock();
    clock = n_clock;
}

Time::~Time()
{
    delete clock;
}

void Time::Update()
{
    sf::Time temp = clock->restart();
    deltaTime = temp.asSeconds();
}