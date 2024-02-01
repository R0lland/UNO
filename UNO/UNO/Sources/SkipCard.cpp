#include "SkipCard.h"

#include "ITurnActionHandler.h"

SkipCard::SkipCard(const card_color color)
    : Card(color)
{
    display_card_value_ = "Skip";
}

void SkipCard::InvokeAction(ITurnActionHandler* turn_handler)
{
    turn_handler->HandleSkipNextPlayer();
}
