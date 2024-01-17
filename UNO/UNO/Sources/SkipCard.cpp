#include "SkipCard.h"

SkipCard::SkipCard(const card_color color)
    : Card(color)
{
    display_card_value_ = "Skip";
}

void SkipCard::Action()
{
}
