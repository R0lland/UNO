#include "ColorUtils.h"

#include <iostream>

#include "color.hpp"

std::string& ColorUtils::GetColorName(const card_color color)
{
    colors_info_.find(color);
    return colors_info_[color]->name;
}

std::string& ColorUtils::GetColorDyeId(card_color color)
{
    colors_info_.find(color);
    return colors_info_[color]->color_dye_id;
}

void ColorUtils::PrintColor(const card_color color)
{
    if (color == card_color::WILD)
    {
        std::cout << dye::colorize("W", GetColorDyeId(card_color::RED)) << dye::colorize("i", GetColorDyeId(card_color::GREEN)) <<
            dye::colorize("l", GetColorDyeId(card_color::YELLOW)) << dye::colorize("d", GetColorDyeId(card_color::BLUE));
    }
    else
    {
        std::cout << dye::colorize(GetColorName(color), GetColorDyeId(color));
    }
}

void ColorUtils::PrintAllColorsWithId()
{
    PrintColorWithId(card_color::RED);
    PrintColorWithId(card_color::GREEN);
    PrintColorWithId(card_color::BLUE);
    PrintColorWithId(card_color::YELLOW);
    std::cout << std::endl;
}

void ColorUtils::PrintColorWithId(card_color color)
{
    std::cout << "[" << static_cast<int>(color) << "] ";
    PrintColor(color);
    std::cout << " | ";
}

void ColorUtils::PrintTextWithColor(const std::string& message, const std::string color_id)
{
    std::cout <<  dye::colorize(message, color_id);
}

std::map<card_color, std::shared_ptr<ColorInfo>> ColorUtils::colors_info_{
                        {card_color::RED, std::make_shared<ColorInfo>("Red", "Red")},
                        {card_color::YELLOW, std::make_shared<ColorInfo>("Yellow", "Yellow")},
                        {card_color::GREEN, std::make_shared<ColorInfo>("Green", "Green")},
                        {card_color::BLUE, std::make_shared<ColorInfo>("Blue", "Blue")},
                        {card_color::WILD, std::make_shared<ColorInfo>("Wild", "White")}};
