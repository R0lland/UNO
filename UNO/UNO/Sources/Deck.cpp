#include <chrono>
#include <Deck.h>
#include <random>

#include "GameConfig.h"

Deck::Deck()
{
    card_factory_ = std::make_unique<CardFactory>();
}

void Deck::AddCard(std::unique_ptr<Card> card)
{
    cards_.push_back(std::move(card));
}

void Deck::Generate()
{
    const CardFactory card_factory_ref_ = *card_factory_;
    GenerateCardsFromColor(card_color::RED);
    GenerateCardsFromColor(card_color::YELLOW);
    GenerateCardsFromColor(card_color::GREEN);
    GenerateCardsFromColor(card_color::BLUE);
    for (int i = 0; i < GameConfig::NUMBER_OF_WILD_PLUS_CARDS; i++)
    {
        AddCard(card_factory_ref_.CreateWildPlusCard(GameConfig::WILD_CARD_NUMBER_TO_DRAW));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_WILD_CARDS; i++)
    {
        AddCard(card_factory_ref_.CreateWildCard());
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_SWAP_CARDS; i++)
    {
        AddCard(card_factory_ref_.CreateSwapCard());
    }
    
    Shuffle();
}

int Deck::GetSize() const
{
    return cards_.size();
}

void Deck::GenerateCardsFromColor(const card_color color)
{
    const CardFactory card_factory_ref_ = *card_factory_;
    for (int i = GameConfig::MIN_NUMBER_CARD; i < GameConfig::MAX_NUMBER_CARD + 1; i++)
    {
        for (int j = 0; j < GameConfig::NUMBER_OF_CARDS_EQUALS; j++)
        {
            AddCard(card_factory_ref_.CreateNumberCard(color, i));
        }
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_REVERSE_CARDS; i++)
    {
        AddCard(card_factory_ref_.CreateReverseCard(color));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_SKIP_CARDS; i++)
    {
        AddCard(card_factory_ref_.CreateSkipCard(color));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_PLUS_CARDS; i++)
    {
        AddCard(card_factory_ref_.CreatePlusCard(color, GameConfig::PLUS_CARD_NUMBER_TO_DRAW));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_DISCARD_PLUS_CARDS; i++)
    {
        AddCard(card_factory_ref_.CreateDiscardPlusCard(color, GameConfig::PLUS_CARD_NUMBER_TO_DRAW));
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


