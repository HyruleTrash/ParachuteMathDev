#include "./Game.h"
#include <iostream>

using namespace Parachute;

Game::Game()
{
    time = Time();
}

Game::~Game()
{
}

void Game::Update(){
    time.Update();
    std::cout << "delta: " << time.deltaTime << std::endl;
}