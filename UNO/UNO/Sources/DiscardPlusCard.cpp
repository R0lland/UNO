#include "DiscardPlusCard.h"

#include "ITurnCardActionHandler.h"

DiscardPlusCard::DiscardPlusCard(const card_color color, const int number_of_cards_to_draw) : Card(color), number_of_cards_to_draw_(number_of_cards_to_draw)
{
    display_card_value_ = "Discard +" + std::to_string(number_of_cards_to_draw);
}

void DiscardPlusCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleDrawFromDiscardPileForNextPlayer(number_of_cards_to_draw_);
    turn_handler->HandleSkipNextPlayer();
}
