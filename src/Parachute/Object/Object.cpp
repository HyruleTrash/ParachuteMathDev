#pragma once
#include "./Object.h"

using namespace Parachute;

void Parachute::Object::Update()
{
    bounds = {size};

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