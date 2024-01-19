#include "ReverseCard.h"

#include <iostream>

#include "ITurnCardActionHandler.h"


ReverseCard::ReverseCard(const card_color color, const card_type type) 
        : Card(color, type)
{
        display_card_value_ = "Reverse";
}

void ReverseCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
        turn_handler->HandleChangeGameDirection();
}
