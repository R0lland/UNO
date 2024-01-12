#pragma once
#include "CardColor.h"

class Card
{
private:
    int id_ = 0;
protected:
    card_color color_ = card_color::NONE;
public:
    virtual ~Card() = default;
    explicit Card(card_color color);
    card_color GetColor() const;
    virtual void Action() = 0;
};
