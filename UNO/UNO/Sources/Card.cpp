#include "../Header/Card.h"

#include "color.hpp"
#include "ColorUtils.h"

Card::Card(const card_color color, const card_type type) : color_(color), type_(type)
{}

card_color Card::GetColor() const
{
    return color_;
}

card_type Card::GetType() const
{
    return type_;
}

std::string Card::GetDisplayValue() const
{
    return display_card_value_;
}

void Card::Print()
{
    std::cout << dye::colorize(ColorUtils::GetColorName(color_), ColorUtils::GetColorDyeId(color_)) << " " << display_card_value_ << std::endl;
}

void Card::Print(int id)
{
    std::cout << "[" << id << "] " << dye::colorize(ColorUtils::GetColorName(color_), ColorUtils::GetColorDyeId(color_)) << " " << display_card_value_ << " | ";
}

void Card::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    
}
