#include "../Header/Card.h"

#include "color.hpp"
#include "ColorUtils.h"

Card::Card(const card_color color) : color_(color)
{}

card_color Card::GetColor() const
{
    return color_;
}

void Card::Print(int id)
{
    std::cout << "[" << id << "] " << dye::colorize(ColorUtils::GetColorName(color_), ColorUtils::GetColorDyeId(color_)) << " " << display_card_value_ << std::endl;
}