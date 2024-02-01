#pragma once
#include "Card.h"

class WildCard : public Card
{
public:
    WildCard();
    void InvokeAction(ITurnActionHandler* turn_handler) override;
};
