#include "SpecialActionsCollection.h"

#include "ClearConsoleAction.h"
#include "DrawCardAction.h"
#include "GameConfig.h"
#include "ShoutUnoAction.h"

SpecialActionsCollection::SpecialActionsCollection()
{
    special_actions_.push_back(std::make_unique<DrawCardAction>(GameConfig::BASE_SPECIAL_ACTIONS_ID, "Draw Card"));
    special_actions_.push_back(std::make_unique<ClearConsoleAction>(GameConfig::BASE_SPECIAL_ACTIONS_ID + 1, "Clear Console"));
    special_actions_.push_back(std::make_unique<ShoutUnoAction>(GameConfig::BASE_SPECIAL_ACTIONS_ID + 2, "Shout UNO"));
}

int SpecialActionsCollection::GetStartingSpecialActionsId()
{
    return GameConfig::BASE_SPECIAL_ACTIONS_ID;
}

int SpecialActionsCollection::GetLastSpecialActionsId() const
{
    return GameConfig::BASE_SPECIAL_ACTIONS_ID + (static_cast<int>(special_actions_.size()) - 1);
}

int SpecialActionsCollection::GetNumberOfSpecialAction() const
{
    return static_cast<int>(special_actions_.size());
}

void SpecialActionsCollection::UseAction(ITurnCardActionHandler* turn_handler, const int id) const
{
    for (const std::unique_ptr<SpecialAction>& special_action : special_actions_)
    {
        if (special_action->GetId() == id)
        {
            special_action->InvokeAction(turn_handler);
            break;
        }
    }
}

void SpecialActionsCollection::PrintActions(Player& player) const
{
    for (const std::unique_ptr<SpecialAction>& action : special_actions_)
    {
        if (action->IsActionValidToUse(player))
        {
            action->Print();
        }
    }
}
