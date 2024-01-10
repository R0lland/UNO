#pragma once
#include "CardColor.h"

class Card
{
private:
    card_color color_ = card_color::NONE;
    
public:
    Card() = default;
    Card(card_color new_color);
};
