#pragma once
#include "Card.h"

class PlusCard : public Card
{
public:
    explicit PlusCard(card_color color);
    void Action() override;
};
