#pragma once
#include "Card.h"

class NumberCard : public Card
{
private:
    int number_ = -1;
public:
    NumberCard(card_color color, int number);
    int GetNumber() const;
    void InvokeAction(ITurnActionHandler* turn_handler) override;
};
