#include "CardFactory.h"

#include "NumberCard.h"
#include "PlusCard.h"
#include "ReverseCard.h"
#include "SkipCard.h"
#include "WildCard.h"

std::unique_ptr<Card> CardFactory::CreateWildCard() const
{
    return std::make_unique<WildCard>();
}

std::unique_ptr<Card> CardFactory::CreateNumberCard(card_color color, int number) const
{
    return std::make_unique<NumberCard>(color, number);
}

std::unique_ptr<Card> CardFactory::CreateReverseCard(card_color color) const
{
    return std::make_unique<ReverseCard>(color);
}

std::unique_ptr<Card> CardFactory::CreatePlusCard(card_color color, int cards_to_draw) const
{
    return std::make_unique<PlusCard>(color, cards_to_draw);
}

std::unique_ptr<Card> CardFactory::CreateSkipCard(card_color color) const
{
    return std::make_unique<SkipCard>(color);
}
