#pragma once
#include "./InputManager.h"
#include "InputManager.h"
#include <iostream>

using namespace Parachute;

InputManager::InputManager()
{
}

InputManager::~InputManager()
{
    for (auto input : this->inputs)
    {
        delete input;
    }
}

std::ostream &operator<<(std::ostream &os, const InputManager &manager)
{
    std::string result{};

    for (auto input : manager.inputs)
    {
        result += "[" + input->name + ", " + (input->isPressed ? "true" : "false") + "],\n";
    }

    return os << "[\n"
              << result << "]";
}

void InputManager::AddInput(Input input)
{
    std::optional<Input *> search = this->HasInput(input.name);
    if (!search.has_value())
    {
        if (input.isPressed)
            input.pressTimeStamp = std::chrono::high_resolution_clock::now();
        Input *n_input = new Input(input);
        inputs.push_back(n_input);
    }
    else
    {
        Input *foundInput = search.value();
        if (input.isPressed && input.isPressed != foundInput->isPressed)
            foundInput->pressTimeStamp = std::chrono::high_resolution_clock::now();
        else if (!input.isPressed && input.isPressed != foundInput->isPressed)
            foundInput->releaseTimeStamp = std::chrono::high_resolution_clock::now();
        foundInput->isPressed = input.isPressed;
    }
}

std::optional<Input *> InputManager::HasInput(std::string name)
{
    for (auto input : inputs)
    {
        if (input->name == name)
        {
            return input;
        }
    }

    return {};
}

bool InputManager::IsKeyBeingPressed(std::string name)
{
    std::optional<Input *> search = this->HasInput(name);
    if (!search.has_value())
    {
        return false;
    }
    else
    {
        Input *foundInput = search.value();
        if (foundInput->isPressed)
            return true;
        else
            return false;
    }
}

bool InputManager::IsKeyJustPressed(std::string name)
{
    std::optional<Input *> search = this->HasInput(name);
    if (!search.has_value())
    {
        return false;
    }
    else
    {
        Input *foundInput = search.value();
        auto now = std::chrono::high_resolution_clock::now();
        double t_runTime = std::chrono::duration_cast<std::chrono::duration<double>>(now - foundInput->pressTimeStamp).count();
        if (t_runTime <= foundInput->JUSTPRESSED_THRESHOLD)
        {
            foundInput->pressTimeStamp = std::chrono::time_point<std::chrono::high_resolution_clock>{};
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool InputManager::IsKeyJustReleased(std::string name)
{
    std::optional<Input *> search = this->HasInput(name);
    if (!search.has_value())
    {
        return false;
    }
    else
    {
        Input *foundInput = search.value();
        auto now = std::chrono::high_resolution_clock::now();
        double t_runTime = std::chrono::duration_cast<std::chrono::duration<double>>(now - foundInput->releaseTimeStamp).count();
        if (t_runTime <= foundInput->JUSTPRESSED_THRESHOLD)
        {
            foundInput->releaseTimeStamp = std::chrono::time_point<std::chrono::high_resolution_clock>{};
            return true;
        }
        else
        {
            return false;
        }
    }
}
