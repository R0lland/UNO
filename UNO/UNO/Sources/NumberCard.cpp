#include "NumberCard.h"

#include <iostream>

NumberCard::NumberCard(const card_color color, const card_type type, const int number)
    : Card(color, type), number_(number)
{
    display_card_value_ = std::to_string(number);
}

int NumberCard::GetNumber() const
{
  return number_;
}

void NumberCard::Action()
{
}
