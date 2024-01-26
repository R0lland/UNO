#pragma once
#include "Card.h"

class DiscardPlusCard : public Card
{
private:
    int number_of_cards_to_draw_ = 0;
public:
    DiscardPlusCard(card_color color, int number_of_cards_to_draw);
    void InvokeAction(ITurnCardActionHandler* turn_handler) override;
};
