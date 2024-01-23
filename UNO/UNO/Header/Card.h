#pragma once
#include <string>

#include "CardData.h"

class ITurnCardActionHandler;

class Card
{
protected:
    card_color color_ = card_color::WILD;
    card_type type_ = card_type::NUMBER;
    std::string display_card_value_;
public:
    explicit Card(card_color color, card_type type);
    card_color GetColor() const;
    card_type GetType() const;
    std::string GetDisplayValue() const;
    void Print();
    void Print(int id);
    virtual void InvokeAction(ITurnCardActionHandler* turn_handler);
};
