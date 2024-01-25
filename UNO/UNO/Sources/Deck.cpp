#include <chrono>
#include <Deck.h>
#include <random>

#include "GameConfig.h"

void Deck::AddCard(std::unique_ptr<Card> card)
{
    cards_.push_back(std::move(card));
}

void Deck::Generate()
{
    cards_.reserve(GameConfig::TOTAL_CARDS);
    
    GenerateCardsFromColor(card_color::RED);
    GenerateCardsFromColor(card_color::YELLOW);
    GenerateCardsFromColor(card_color::GREEN);
    GenerateCardsFromColor(card_color::BLUE);
    for (int i = 0; i < GameConfig::NUMBER_OF_WILD_CARDS; i++)
    {
        AddCard(card_factory_->CreateWildCard(GameConfig::WILD_CARD_NUMBER_TO_DRAW));
    }
    
    Shuffle();
}

int Deck::GetSize() const
{
    return cards_.size();
}

void Deck::GenerateCardsFromColor(const card_color color)
{
    for (int i = GameConfig::MIN_NUMBER_CARD; i < GameConfig::MAX_NUMBER_CARD + 1; i++)
    {
        for (int j = 0; j < GameConfig::NUMBER_OF_CARDS_EQUALS; j++)
        {
            AddCard(card_factory_->CreateNumberCard(color, card_type::NUMBER, i));
        }
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_REVERSE_CARDS; i++)
    {
        AddCard(card_factory_->CreateReverseCard(color, card_type::REVERSE));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_SKIP_CARDS; i++)
    {
        AddCard(card_factory_->CreateSkipCard(color, card_type::SKIP));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_PLUS_CARDS; i++)
    {
        AddCard(card_factory_->CreatePlusCard(color, card_type::PLUS_TWO, GameConfig::PLUS_CARD_NUMBER_TO_DRAW));
    }
}

void Deck::Shuffle()
{
    const unsigned int seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    auto rng = std::default_random_engine {seed};
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

void Deck::ClearDeck()
{
    cards_.clear();
}

std::unique_ptr<Card> Deck::DrawCard()
{
    std::unique_ptr<Card> card = std::move(cards_.back());
    cards_.pop_back();
    return card;
}


