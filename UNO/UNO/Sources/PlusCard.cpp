#include "PlusCard.h"

PlusCard::PlusCard(card_color color, card_type type, int numberOfCardsToDraw)
    : Card(color, type), number_of_cards_to_draw_(numberOfCardsToDraw)
{
    display_card_value_ = "+" + std::to_string(numberOfCardsToDraw);
}

void PlusCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
}