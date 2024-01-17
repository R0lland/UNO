#include "ReverseCard.h"

#include <iostream>

ReverseCard::ReverseCard(const card_color color) 
        : Card(color)
{
        display_card_value_ = "Reverse";
}

void ReverseCard::Action()
{
}
