#include "ReverseCard.h"

#include <iostream>

ReverseCard::ReverseCard(const card_color color, const card_type type) 
        : Card(color, type)
{
        display_card_value_ = "Reverse";
}

void ReverseCard::Action()
{
}
