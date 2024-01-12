#include "NumberCard.h"

NumberCard::NumberCard(const card_color color, const int number)
    : Card(color), number_(number)
{ }

int NumberCard::GetNumber() const
{
  return number_;
}

void NumberCard::Action()
{
}
