#pragma once
#include "Card.h"

class NumberCard : public Card
{
private:
    int number_ = -1;
public:
    NumberCard(card_color color, card_type type, int number);
    int GetNumber() const;
    void Action() override;
};
