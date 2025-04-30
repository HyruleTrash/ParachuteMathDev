#include "./InputManager.h"
#include "InputManager.h"
#include <iostream>

namespace Parachute
{
    InputManager::~InputManager()
    {
        for (auto input : this->inputs)
        {
            delete input;
        }
    }

    /// @brief A opperator for easily printing the inputs found within the input manager. For debugging purposes
    /// @param os
    /// @param manager
    /// @return
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

    /// @brief Adds a input class to a list of current inputs, if it doesnt contain it already. if it does it will set the relevant input data instead.
    /// @param input
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

    /// @brief Loops through the input list to see if the id/name of a input is already being looked after or not
    /// @param name
    /// @return
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

    /// @brief Checks if the input is being looked after, and returns if it is being pressed or not
    /// @param name
    /// @return
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

    /// @brief Depending on the threshold and timestamp found inside the input class, returns if it was only just pressed or not
    /// Usefull for when you only want to detect the button once
    /// @param name
    /// @return
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

    /// @brief If you want a avverse effect after having pushed a button on your keyboard. This function does just that. Barely any difference in functionality. except when the time stamps are set
    /// @param name
    /// @return
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
}