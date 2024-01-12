#pragma once
#include "Card.h"

class WildCard final : public Card
{
public:
    WildCard();
    void Action() override;
};
