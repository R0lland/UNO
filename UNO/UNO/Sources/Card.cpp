#include "../Header/Card.h"

#include "color.hpp"
#include "ColorUtils.h"
#include "ConsolePrinter.h"

Card::Card(const card_color color) : color_(color)
{}

card_color Card::GetColor() const
{
    return color_;
}

bool Card::GetCanBeUsedAnyTurn() const
{
    return can_be_used_any_turn_;
}

std::string Card::GetDisplayValue() const
{
    return display_card_value_;
}

void Card::Print() const
{
    ColorUtils::PrintColor(color_);
    ConsolePrinter::ShowMessage(" " + display_card_value_, false);
}

void Card::Print(const int id) const
{
    ConsolePrinter::ShowMessage("[" + std::to_string(id) + "] ", false);
    ColorUtils::PrintColor(color_);
    ConsolePrinter::ShowMessage(" " + display_card_value_ + " | ", false);
}

void Card::InvokeAction(ITurnActionHandler* turn_handler)
{
    
}
