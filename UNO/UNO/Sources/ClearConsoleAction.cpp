#include "ClearConsoleAction.h"

#include "ITurnActionHandler.h"

ClearConsoleAction::ClearConsoleAction(const int id, const std::string display_value) : SpecialAction(id, display_value)
{}

bool ClearConsoleAction::IsActionValidToUse(Player& player)
{
    return true;
}

void ClearConsoleAction::InvokeAction(ITurnActionHandler* turn_handler)
{
    turn_handler->HandleClearConsole();
}
