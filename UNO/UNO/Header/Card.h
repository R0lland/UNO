#pragma once
#include "CardColor.h"

class Card
{
private:
    int id_ = 0;
    int number_ = 0;
    card_color color_ = card_color::RED;
    
public:
    Card() = default;
    explicit Card(card_color color, int number);
    card_color GetColor() const;
};
