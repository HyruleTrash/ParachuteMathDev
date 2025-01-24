#pragma once
#include <vector>
#include <optional>
#include <string>
#include "./Input/Input.cpp"

namespace Parachute
{
    class InputManager
    {
    public:
        InputManager();
        ~InputManager();
        void AddInput(Input);
        std::optional<Input *> HasInput(std::string);
        bool IsKeyBeingPressed(std::string);
        bool IsKeyJustPressed(std::string);
        bool IsKeyJustReleased(std::string);
        std::vector<Input *> inputs{};
    };
}
