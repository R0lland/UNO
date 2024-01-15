#include <chrono>
#include <Deck.h>
#include <iostream>
#include <random>

#include "CardUtils.h"
#include "GameConfig.h"
#include "NumberCard.h"
#include "PlusCard.h"
#include "ReverseCard.h"
#include "SkipCard.h"
#include "WildCard.h"

void Deck::AddCard(const std::shared_ptr<Card>& card)
{
    cards_.emplace_back(card);
}

void Deck::Generate()
{
    GenerateCardsFromColor(card_color::RED);
    GenerateCardsFromColor(card_color::YELLOW);
    GenerateCardsFromColor(card_color::GREEN);
    GenerateCardsFromColor(card_color::BLUE);
    for (int i = 0; i < GameConfig::NUMBER_OF_WILD_CARDS; i++)
    {
        AddCard(CardUtils::GetCardFromChildType<WildCard>());
    }
    
    Shuffle();
}

void Deck::GenerateCardsFromColor(const card_color color)
{
    for (int i = GameConfig::MIN_NUMBER_CARD; i < GameConfig::MAX_NUMBER_CARD + 1; i++)
    {
        for (int j = 0; j < GameConfig::NUMBER_OF_CARDS_EQUALS; j++)
        {
            AddCard(CardUtils::GetCardFromChildType<NumberCard>(color, i));
        }
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_REVERSE_CARDS; i++)
    {
        AddCard(CardUtils::GetCardFromChildType<ReverseCard>(color));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_SKIP_CARDS; i++)
    {
        AddCard(CardUtils::GetCardFromChildType<SkipCard>(color));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_PLUS_CARDS; i++)
    {
        AddCard(CardUtils::GetCardFromChildType<PlusCard>(color, GameConfig::PLUS_CARD_NUMBER_TO_DRAW));
    }
}

void Deck::Shuffle() const
{
    const unsigned int seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    auto rng = std::default_random_engine {seed};
    std::shuffle(std::begin(cards_), std::end(cards_), rng);

    std::cout << cards_.size();
}


