#pragma once
#include <string>

#include "CardColor.h"

class Card
{
protected:
    card_color color_ = card_color::NONE;
    std::string display_card_value_;
public:
    explicit Card(card_color color);
    card_color GetColor() const;
    void Print(int id);
    virtual void Action() = 0;
};
