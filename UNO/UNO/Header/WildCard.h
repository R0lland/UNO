#pragma once
#include "Card.h"

class WildCard : public Card
{
public:
    WildCard();
    void InvokeAction(ITurnCardActionHandler* turn_handler) override;
};
