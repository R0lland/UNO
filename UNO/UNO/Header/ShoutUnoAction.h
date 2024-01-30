﻿#pragma once
#include "SpecialAction.h"

class ShoutUnoAction : public SpecialAction
{
public:
    ShoutUnoAction(int id, std::string display_value);
    bool IsActionValidToUse(Player& player) override;
    void InvokeAction(ITurnCardActionHandler* turn_handler) override;
};
