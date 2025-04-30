#include "Object.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;
    
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