﻿#pragma once
#include "Card.h"

class SkipCard : public Card
{
public:
    explicit SkipCard(card_color color);
    void Action() override;
};
