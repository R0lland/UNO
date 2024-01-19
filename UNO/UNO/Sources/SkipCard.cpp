#include "SkipCard.h"

SkipCard::SkipCard(const card_color color, const card_type type)
    : Card(color, type)
{
    display_card_value_ = "Skip";
}

void SkipCard::Action()
{
}
