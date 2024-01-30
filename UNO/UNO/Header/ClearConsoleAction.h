#pragma once
#include "SpecialAction.h"

class ClearConsoleAction : public SpecialAction
{
public:
    explicit ClearConsoleAction(int id, std::string display_value);
    bool IsActionValidToUse(Player& player) override;
    void InvokeAction(ITurnCardActionHandler* turn_handler) override;
};
