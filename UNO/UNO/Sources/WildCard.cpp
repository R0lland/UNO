﻿#include "WildCard.h"

WildCard::WildCard(int number_of_cards_to_draw)
    : Card(card_color::NONE, card_type::WILD), number_of_cards_to_draw_(number_of_cards_to_draw)
{
    display_card_value_ = "+" + std::to_string(number_of_cards_to_draw_);
}

void WildCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
}