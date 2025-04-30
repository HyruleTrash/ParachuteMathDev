#include "Input.h"

namespace Parachute
{
    Input::Input(std::string name)
    {
        this->name = name;
    }

    Input::Input(std::string name, bool isPressed) : Input(name)
    {
        this->isPressed = isPressed;
    }
}