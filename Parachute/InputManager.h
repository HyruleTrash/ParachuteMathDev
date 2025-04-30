#pragma once
#include <vector>
#include <optional>
#include <string>
#include "Input.h"

namespace Parachute
{
    /// @brief The input manager keeps track of all inputs used in the game
    class InputManager
    {
    public:
        InputManager() = default;
        ~InputManager();
        void AddInput(Input);
        std::optional<Input *> HasInput(std::string);
        bool IsKeyBeingPressed(std::string);
        bool IsKeyJustPressed(std::string);
        bool IsKeyJustReleased(std::string);
        std::vector<Input *> inputs{};
    };
}
