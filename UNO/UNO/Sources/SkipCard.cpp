#include "SkipCard.h"

#include "ITurnCardActionHandler.h"

SkipCard::SkipCard(const card_color color)
    : Card(color)
{
    display_card_value_ = "Skip";
}

void SkipCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleSkipNextPlayer();
}
