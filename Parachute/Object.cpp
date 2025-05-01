#include "Object.h"

namespace Parachute
{
    using Vector2 = MathUtil::Vector2;

    bool Object::ShouldRun()
    {
        return !shouldBeDeleted;
    }

    void Object::Update()
    {
        if (shouldBeDeleted){
            delete this;
            return;
        }
            
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

    void Object::Delete()
    {
        shouldBeDeleted = true;
    }
}
