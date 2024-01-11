#include <Deck.h>
#include <iostream>
#include <random>

#include "GameConfig.h"

void Deck::Generate() const
{
    cards_->clear();
    //TODO MIN_NUMBER_CARD must always be lower then MAX_NUMBER_CARD
    for (int i = GameConfig::MIN_NUMBER_CARD; i < GameConfig::MAX_NUMBER_CARD + 1; i++)
    {
        cards_->emplace_back(card_color::RED, i);
        cards_->emplace_back(card_color::YELLOW, i);
        cards_->emplace_back(card_color::GREEN, i);
        cards_->emplace_back(card_color::BLUE, i);
    }
    std::cout << cards_->size();
}

void Deck::Shuffle() const
{
    //std::shuffle(std::begin(*cards_), std::end(*cards_), rand());
}


