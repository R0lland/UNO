#pragma once
#include "Card.h"

class WildCard : public Card
{
public:
    WildCard();
    void Action() override;
};
