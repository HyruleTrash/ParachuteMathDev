#pragma once
#include "./Object.h"

using namespace Parachute;

void Parachute::Object::Update()
{
    // update bounds
    bounds = {size};

    // sets the object's visibility depending on the game state
    if (checkGameState)
    {
        visable = false;
        for (GameState state : activeStates)
        {
            if (state == GetGameState())
            {
                visable = true;
                break;
            }
        }
    }
}