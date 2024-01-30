#include "DrawCardAction.h"

#include "ITurnCardActionHandler.h"

DrawCardAction::DrawCardAction(const int id, const std::string display_value)  : SpecialAction(id, display_value)
{
}

bool DrawCardAction::IsActionValidToUse(Player& player)
{
    return SpecialAction::IsActionValidToUse(player);
}

void DrawCardAction::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleDrawCardForCurrentPlayer(1);
    turn_handler->HandleEndTurn();
}
