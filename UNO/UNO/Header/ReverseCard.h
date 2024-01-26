#pragma once
#include "Card.h"

class ReverseCard : public Card
{
public:
    explicit ReverseCard(card_color color);
    void InvokeAction(ITurnCardActionHandler* turn_handler) override;
};
