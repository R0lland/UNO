#include <Deck.h>

#include "GameConfig.h"

void Deck::Generate()
{
    GenerateCardsFromColor(card_color::RED);
    GenerateCardsFromColor(card_color::YELLOW);
    GenerateCardsFromColor(card_color::GREEN);
    GenerateCardsFromColor(card_color::BLUE);
    for (int i = 0; i < GameConfig::NUMBER_OF_WILD_PLUS_CARDS; i++)
    {
        AddCard(card_factory_->CreateWildPlusCard(GameConfig::WILD_CARD_NUMBER_TO_DRAW));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_WILD_CARDS; i++)
    {
        AddCard(card_factory_->CreateWildCard());
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_SWAP_CARDS; i++)
    {
        AddCard(card_factory_->CreateSwapCard());
    }
    
    Shuffle();
}

void Deck::GenerateCardsFromColor(const card_color color)
{
    for (int i = GameConfig::MIN_NUMBER_CARD; i < GameConfig::MAX_NUMBER_CARD + 1; i++)
    {
        for (int j = 0; j < GameConfig::NUMBER_OF_CARDS_EQUALS; j++)
        {
            AddCard(card_factory_->CreateNumberCard(color, i));
        }
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_REVERSE_CARDS; i++)
    {
        AddCard(card_factory_->CreateReverseCard(color));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_SKIP_CARDS; i++)
    {
        AddCard(card_factory_->CreateSkipCard(color));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_PLUS_CARDS; i++)
    {
        AddCard(card_factory_->CreatePlusCard(color, GameConfig::PLUS_CARD_NUMBER_TO_DRAW));
    }

    for (int i = 0; i < GameConfig::NUMBER_OF_DISCARD_PLUS_CARDS; i++)
    {
        AddCard(card_factory_->CreateDiscardPlusCard(color, GameConfig::PLUS_CARD_NUMBER_TO_DRAW));
    }
}


