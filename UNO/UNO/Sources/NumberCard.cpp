﻿#include "NumberCard.h"

#include <iostream>

#include "ITurnActionHandler.h"

NumberCard::NumberCard(const card_color color, const int number)
    : Card(color), number_(number)
{
    display_card_value_ = std::to_string(number);
}

int NumberCard::GetNumber() const
{
  return number_;
}

void NumberCard::InvokeAction(ITurnActionHandler* turn_handler)
{
    
}
