#include "WildCard.h"

#include "ColorUtils.h"
#include "InputOutputHelper.h"
#include "ITurnCardActionHandler.h"

WildCard::WildCard() : Card(card_color::WILD, card_type::WILD)
{
    display_card_value_ = "";
}

void WildCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    ColorUtils::PrintAllColorsWithId();
    int color_id = -1;
    while (!InputOutputHelper::InputNumberInRange(1, 4, color_id))
    {
        color_id = InputOutputHelper::ForceGetInput<int>("Choose one of the colors: ");
    }
    turn_handler->HandleSetNewTurnColor(static_cast<card_color>(color_id), true);
}
