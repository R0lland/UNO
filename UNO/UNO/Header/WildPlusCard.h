#pragma once
#include "WildCard.h"

class WildPlusCard : public WildCard
{
private:
    int number_of_cards_to_draw_ = 0;

public:
    WildPlusCard(int number_of_cards_to_draw);
    void InvokeAction(ITurnCardActionHandler* turn_handler) override;
};
