#include "SwapHandsCard.h"

#include "ITurnCardActionHandler.h"

SwapHandsCard::SwapHandsCard() : Card(card_color::NONE, card_type::SWAP)
{
    display_card_value_ = "Swap";
    can_be_used_any_turn_ = true;
}

void SwapHandsCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    turn_handler->HandleSwapHands();
}
