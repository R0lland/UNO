#pragma once
#include "Card.h"

class WildPlusCard : public Card
{
private:
    int number_of_cards_to_draw_ = 0;

public:
    WildPlusCard(int number_of_cards_to_draw);
    void InvokeAction(ITurnCardActionHandler* turn_handler) override;
};
