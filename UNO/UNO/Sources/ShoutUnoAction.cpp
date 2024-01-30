#include "ShoutUnoAction.h"

#include "ITurnCardActionHandler.h"
#include "Player.h"

ShoutUnoAction::ShoutUnoAction(const int id, const std::string display_value) : SpecialAction(id, display_value)
{
}

bool ShoutUnoAction::IsActionValidToUse(Player& player)
{
    return player.CanShoutUno() && !player.HasShoutedUno();
}

void ShoutUnoAction::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleShoutUno();
}
