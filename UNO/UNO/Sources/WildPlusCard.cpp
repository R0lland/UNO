#include "WildPlusCard.h"

#include "ColorUtils.h"
#include "InputOutputHelper.h"
#include "ITurnActionHandler.h"

WildPlusCard::WildPlusCard(const int number_of_cards_to_draw)
    : WildCard(), number_of_cards_to_draw_(number_of_cards_to_draw)
{
    display_card_value_ = "+" + std::to_string(number_of_cards_to_draw_);
}

void WildPlusCard::InvokeAction(ITurnActionHandler* turn_handler)
{
    WildCard::InvokeAction(turn_handler);
    turn_handler->HandleDrawCardForNextPlayer(number_of_cards_to_draw_);
    turn_handler->HandleSkipNextPlayer();
}