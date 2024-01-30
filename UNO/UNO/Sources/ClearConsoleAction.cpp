#include "ClearConsoleAction.h"

#include "ITurnCardActionHandler.h"

ClearConsoleAction::ClearConsoleAction(const int id, const std::string display_value) : SpecialAction(id, display_value)
{}

bool ClearConsoleAction::IsActionValidToUse(Player& player)
{
    return true;
}

void ClearConsoleAction::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleClearConsole();
}
