#include "Object.h"

namespace Parachute
{
    void Object::Update()
    {
        // update bounds
        bounds = {size};

        // sets the object's visibility depending on the game state
        if (checkGameState)
        {
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
}