#pragma once
#include "Card.h"

class SkipCard : public Card
{
public:
    explicit SkipCard(card_color color, card_type type);
    void InvokeAction(ITurnCardActionHandler* turn_handler) override;
};
