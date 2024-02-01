#pragma once
#include "Card.h"

class SwapHandsCard : public Card
{
public:
    SwapHandsCard();
    void InvokeAction(ITurnActionHandler* turn_handler) override;
};
