﻿#include "../Header/Card.h"

#include "color.hpp"
#include "ColorUtils.h"
#include "ConsolePrinter.h"

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
    ColorUtils::PrintColor(color_);
    ConsolePrinter::ShowMessage(" " + display_card_value_, false);
}

void Card::Print(int id)
{
    ConsolePrinter::ShowMessage("[" + std::to_string(id) + "] ", false);
    ColorUtils::PrintColor(color_);
    ConsolePrinter::ShowMessage(" " + display_card_value_ + " | ", false);
}

void Card::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    
}
