#include "WildPlusCard.h"

#include "ColorUtils.h"
#include "InputOutputHelper.h"
#include "ITurnCardActionHandler.h"

WildPlusCard::WildPlusCard(const int number_of_cards_to_draw)
    : Card(card_color::WILD, card_type::WILD), number_of_cards_to_draw_(number_of_cards_to_draw)
{
    display_card_value_ = "+" + std::to_string(number_of_cards_to_draw_);
}

void WildPlusCard::InvokeAction(ITurnCardActionHandler* turn_handler)
{
    ColorUtils::PrintAllColorsWithId();
    int color_id = -1;
    while (!InputOutputHelper::InputNumberInRange(1, 4, color_id))
    {
        color_id = InputOutputHelper::ForceGetInput<int>("Choose one of the colors");
    }
    turn_handler->HandleSetNewTurnColor(static_cast<card_color>(color_id));
    turn_handler->HandleDrawCardForNextPlayer(number_of_cards_to_draw_);
}