#pragma once
#include "./Text.h"
#include "Text.h"

using namespace Parachute;

Text::Text()
{
    this->color = DEFAULT_COLOR;
    this->textSize = DEFAULT_TEXT_SIZE;
    if (!this->font.openFromFile(DEFAULT_FONT_LOCATION))
    {
        std::cout << "ERROR: Font file could not be found" << std::endl;
    }
    else
    {
        textObj = std::make_unique<sf::Text>(this->font);
        SetTextData();
    }
}

Text::Text(sf::Color color, float textSize, std::string text, Game *game)
{
    this->color = color;
    this->textSize = textSize;
    this->text = text;
    this->game = game;
    if (!this->font.openFromFile(DEFAULT_FONT_LOCATION))
    {
        std::cout << "ERROR: Font file could not be found" << std::endl;
    }
    else
    {
        textObj = std::make_unique<sf::Text>(this->font);
        SetTextData();
    }
}

void Text::Update()
{
    Object::Update();

    if (visable)
    {
        SetTextData();
        sf::Text &ref = *textObj;
        Vector2 origin{size / 2};
        ref.setOrigin({(float)origin.x, (float)origin.y});
        sf::Vector2f pos{(float)position.x, (float)position.y};
        ref.setPosition(pos);
        game->window.draw(ref);
    }
}

void Text::SetTextData()
{
    textObj->setString(text);
    textObj->setCharacterSize(textSize);
    textObj->setFillColor(color);
    sf::Vector2<float> temp{textObj->getLocalBounds().getCenter()};
    this->size = Vector2{temp.x, temp.y} * 2;
}