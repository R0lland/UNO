#include "PlusCard.h"

#include "ITurnCardActionHandler.h"

PlusCard::PlusCard(card_color color, int numberOfCardsToDraw)
    : Card(color), number_of_cards_to_draw_(numberOfCardsToDraw)
{
    display_card_value_ = "+" + std::to_string(numberOfCardsToDraw);
}

void PlusCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleDrawCardForNextPlayer(number_of_cards_to_draw_);
    turn_handler->HandleSkipNextPlayer();
}