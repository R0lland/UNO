#pragma once
#include <memory>

#include "Card.h"

class CardUtils
{
public:
    template <typename TData>
    static std::shared_ptr<Card> GetCardFromChildType(card_color color, int number);

    template <typename TData>
    static std::shared_ptr<Card> GetCardFromChildType(card_color color);

    template <typename TData>
    static std::shared_ptr<Card> GetCardFromChildType();
};

template <typename TData>
std::shared_ptr<Card> CardUtils::GetCardFromChildType(card_color color, int number)
{
    std::shared_ptr<Card> card = std::make_shared<TData>(color, number);
    return card;
}

template <typename TData>
std::shared_ptr<Card> CardUtils::GetCardFromChildType(card_color color)
{
    std::shared_ptr<Card> card = std::make_shared<TData>(color);
    return card;
}

template <typename TData>
std::shared_ptr<Card> CardUtils::GetCardFromChildType()
{
    std::shared_ptr<Card> card = std::make_shared<TData>();
    return card;
}

