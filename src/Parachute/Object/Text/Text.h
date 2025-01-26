#pragma once
#include <SFML/Graphics.hpp>
#include <algorithm>
#include <string>
#include "../Object.h"
#include "../../Game/Game.h"

namespace Parachute
{
    class Text : public Object
    {
    private:
        constexpr static auto DEFAULT_FONT_LOCATION{"Assets/Fonts/AldotheApache.ttf"};
        constexpr static sf::Color DEFAULT_COLOR{sf::Color::White};
        constexpr static float DEFAULT_TEXT_SIZE{20};

    public:
        Text();
        Text(sf::Color, float, std::string, Game *);
        ~Text() = default;
        void Update() override;
        GameState GetGameState() override { return game->gameState; };
        void SetTextData();
        sf::Font font;
        std::unique_ptr<sf::Text> textObj;
        sf::Color color;
        float textSize;
        std::string text{};
    };
}