#include "CardFactory.h"

#include "DiscardPlusCard.h"
#include "NumberCard.h"
#include "PlusCard.h"
#include "ReverseCard.h"
#include "SkipCard.h"
#include "SwapHandsCard.h"
#include "WildPlusCard.h"

std::shared_ptr<Card> CardFactory::CreateWildPlusCard(int cards_to_draw) const
{
    return std::make_shared<WildPlusCard>(cards_to_draw);
}

std::shared_ptr<Card> CardFactory::CreateNumberCard(card_color color, int number) const
{
    return std::make_shared<NumberCard>(color, number);
}

std::shared_ptr<Card> CardFactory::CreateReverseCard(card_color color) const
{
    return std::make_shared<ReverseCard>(color);
}

std::shared_ptr<Card> CardFactory::CreatePlusCard(card_color color, int cards_to_draw) const
{
    return std::make_shared<PlusCard>(color,cards_to_draw);
}

std::shared_ptr<Card> CardFactory::CreateDiscardPlusCard(card_color color, int cards_to_draw) const
{
    return std::make_shared<DiscardPlusCard>(color,cards_to_draw);
}

std::shared_ptr<Card> CardFactory::CreateSkipCard(card_color color) const
{
    return std::make_shared<SkipCard>(color);
}

std::shared_ptr<Card> CardFactory::CreateWildCard() const
{
    return std::make_shared<WildCard>();
}

std::shared_ptr<Card> CardFactory::CreateSwapCard() const
{
    return std::make_shared<SwapHandsCard>();
}
