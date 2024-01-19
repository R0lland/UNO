#pragma once
#include <string>

#include "CardData.h"

class Card
{
protected:
    card_color color_ = card_color::NONE;
    card_type type_ = card_type::NUMBER;
    std::string display_card_value_;
public:
    explicit Card(card_color color, card_type type);
    card_color GetColor() const;
    card_type GetType() const;
    void Print();
    void Print(int id);
    virtual void Action() = 0;
};
