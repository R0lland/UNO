#pragma once
#include "Card.h"

class ReverseCard : public Card
{
public:
    explicit ReverseCard(card_color color);
    void Action() override;
};
