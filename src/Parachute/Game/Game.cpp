#include "./Game.h"
#include "../Object/Body/StaticBody/StaticBody.cpp"

using namespace Parachute;

Game::Game()
{
    time = Time();
    // temp
    StaticBody *body = new StaticBody();
    objectManager.Initialize(body, Vector2{10, 10});
}

Game::~Game()
{
}

void Game::Update()
{
    time.Update();
    objectManager.Update();
}