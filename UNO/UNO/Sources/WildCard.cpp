#include "WildCard.h"

#include "ColorUtils.h"
#include "InputOutputHelper.h"
#include "ITurnActionHandler.h"

WildCard::WildCard() : Card(card_color::WILD)
{
    display_card_value_ = "";
    can_be_used_any_turn_ = true;
}

void WildCard::InvokeAction(ITurnActionHandler* turn_handler)
{
    ColorUtils::PrintAllColorsWithId();
    std::string display_message = "Choose one of the colors: ";
    int color_id = InputOutputHelper::GetInputNumberInRange(1, 4, display_message);
    turn_handler->HandleSetNewTurnColor(static_cast<card_color>(color_id), true);
}
