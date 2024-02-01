#pragma once
#include <string>

#include "CardData.h"

class ITurnActionHandler;

class Card
{
protected:
    card_color color_ = card_color::WILD;
    std::string display_card_value_;
    bool can_be_used_any_turn_ = false;
public:
    explicit Card(card_color color);
    card_color GetColor() const;
    bool GetCanBeUsedAnyTurn() const;
    std::string& GetDisplayValue();
    void Print() const;
    void Print(int id) const;
    virtual void InvokeAction(ITurnActionHandler* turn_handler);
};
