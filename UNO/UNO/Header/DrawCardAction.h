#pragma once
#include "SpecialAction.h"

class DrawCardAction : public SpecialAction
{
public:
    DrawCardAction(int id, std::string display_value);
    bool IsActionValidToUse(Player& player) override;
    void InvokeAction(ITurnActionHandler* turn_handler) override;
};
