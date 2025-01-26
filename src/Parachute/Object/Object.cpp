#pragma once
#include "./Object.h"

using namespace Parachute;

void Parachute::Object::Update()
{
    bounds = {size};

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