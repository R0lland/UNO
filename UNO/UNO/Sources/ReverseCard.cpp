#include "ReverseCard.h"

#include <iostream>

#include "ITurnActionHandler.h"


ReverseCard::ReverseCard(const card_color color) 
        : Card(color)
{
        display_card_value_ = "Reverse";
}

void ReverseCard::InvokeAction(ITurnActionHandler* turn_handler)
{
        turn_handler->HandleChangeGameDirection();
}
