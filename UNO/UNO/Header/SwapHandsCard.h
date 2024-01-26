#pragma once
#include "Card.h"

class SwapHandsCard : public Card
{
public:
    SwapHandsCard();
    void InvokeAction(ITurnCardActionHandler* turn_handler) override;
};
