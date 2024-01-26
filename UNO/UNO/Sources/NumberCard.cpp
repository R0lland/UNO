#include "NumberCard.h"

#include <iostream>

#include "ITurnCardActionHandler.h"

NumberCard::NumberCard(const card_color color, const int number)
    : Card(color), number_(number)
{
    display_card_value_ = std::to_string(number);
}

int NumberCard::GetNumber() const
{
  return number_;
}

void NumberCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    
}
