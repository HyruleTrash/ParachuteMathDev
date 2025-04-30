#include "Object.h"

namespace Parachute
{
    void Parachute::Object::Update()
    {
        bounds = {size};

        visible = false;
        for (GameState state : activeStates)
        {
            if (state == GetGameState())
            {
                visible = true;
                break;
            }
        }
    }
}