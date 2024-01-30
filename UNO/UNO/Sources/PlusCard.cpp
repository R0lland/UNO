#include "PlusCard.h"

#include "ITurnCardActionHandler.h"

PlusCard::PlusCard(const card_color color, const int number_of_cards_to_draw)
    : Card(color), number_of_cards_to_draw_(number_of_cards_to_draw)
{
    display_card_value_ = "+" + std::to_string(number_of_cards_to_draw);
}

void PlusCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleDrawCardForNextPlayer(number_of_cards_to_draw_);
    turn_handler->HandleSkipNextPlayer();
}