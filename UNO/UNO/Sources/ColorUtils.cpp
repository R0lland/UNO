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

void ColorUtils::PrintAllColors()
{
    PrintColorWithId(card_color::RED);
    PrintColorWithId(card_color::BLUE);
    PrintColorWithId(card_color::YELLOW);
    PrintColorWithId(card_color::GREEN);
}

void ColorUtils::PrintColor(card_color color)
{
    std::cout << dye::colorize(GetColorName(color), GetColorDyeId(color));
}

void ColorUtils::PrintAllColorsWithId()
{
}

void ColorUtils::PrintColorWithId(card_color color)
{
    std::cout << "[" << static_cast<int>(color) << "] " << dye::colorize(GetColorName(color), GetColorDyeId(color)) << " | ";
}

std::map<card_color, std::shared_ptr<ColorInfo>> ColorUtils::colors_info_{
                        {card_color::RED, std::make_shared<ColorInfo>("Red", "Red")},
                        {card_color::YELLOW, std::make_shared<ColorInfo>("Yellow", "Yellow")},
                        {card_color::GREEN, std::make_shared<ColorInfo>("Green", "Green")},
                        {card_color::BLUE, std::make_shared<ColorInfo>("Blue", "Blue")},
                        {card_color::WILD, std::make_shared<ColorInfo>("Wild", "White")}};
