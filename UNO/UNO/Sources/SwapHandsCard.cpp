#include "SwapHandsCard.h"

#include "ITurnActionHandler.h"

SwapHandsCard::SwapHandsCard() : Card(card_color::NONE)
{
    display_card_value_ = "Swap";
    can_be_used_any_turn_ = true;
}

void SwapHandsCard::InvokeAction(ITurnActionHandler* turn_handler)
{
    turn_handler->HandleSwapHands();
}
