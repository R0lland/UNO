#pragma once
#include "Card.h"

class WildCard : public Card
{
private:
    int number_of_cards_to_draw_ = 0;
public:
    WildCard(int number_of_cards_to_draw);
    void Action() override;
};
