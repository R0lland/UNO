#include "ReverseCard.h"

#include <iostream>

#include "ConsolePrinter.h"
#include "ITurnCardActionHandler.h"


ReverseCard::ReverseCard(const card_color color, const card_type type) 
        : Card(color, type)
{
        display_card_value_ = "Reverse";
}

void ReverseCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
        turn_handler->HandleChangeGameDirection();
        ConsolePrinter::ShowMessage("Game direction has been changed");
}
