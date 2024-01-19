#include "CardFactory.h"

#include "NumberCard.h"
#include "PlusCard.h"
#include "ReverseCard.h"
#include "SkipCard.h"
#include "WildCard.h"

std::unique_ptr<Card> CardFactory::CreateWildCard(int cards_to_draw) const
{
    return std::make_unique<WildCard>(cards_to_draw);
}

std::unique_ptr<Card> CardFactory::CreateNumberCard(card_color color, card_type type, int number) const
{
    return std::make_unique<NumberCard>(color, type, number);
}

std::unique_ptr<Card> CardFactory::CreateReverseCard(card_color color, card_type type) const
{
    return std::make_unique<ReverseCard>(color, type);
}

std::unique_ptr<Card> CardFactory::CreatePlusCard(card_color color, card_type type, int cards_to_draw) const
{
    return std::make_unique<PlusCard>(color, type,cards_to_draw);
}

std::unique_ptr<Card> CardFactory::CreateSkipCard(card_color color, card_type type) const
{
    return std::make_unique<SkipCard>(color, type);
}
