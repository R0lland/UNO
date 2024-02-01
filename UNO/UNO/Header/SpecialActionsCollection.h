#pragma once
#include <memory>
#include <vector>

#include "SpecialAction.h"

class SpecialActionsCollection
{
private:
    std::vector<std::unique_ptr<SpecialAction>> special_actions_;
public:
    SpecialActionsCollection();
    static int GetStartingSpecialActionsId();
    int GetLastSpecialActionsId() const;
    int GetNumberOfSpecialAction() const;
    void UseAction(ITurnActionHandler* turn_handler, int id) const;
    void PrintActions(Player& player) const;
};
