#include "CardCollection.h"

#include <chrono>
#include <random>

void CardCollection::AddCard(std::unique_ptr<Card> card)
{
    cards_.push_back(std::move(card));
}

std::unique_ptr<Card> CardCollection::DrawTopCard()
{
    std::unique_ptr<Card> card = std::move(cards_.back());
    cards_.pop_back();
    return card;
}

std::unique_ptr<Card> CardCollection::DrawRandomCard()
{
    const int card_id = rand() % GetSize();
    std::unique_ptr<Card> card = std::move(cards_[card_id]);
    cards_.erase(cards_.begin() + card_id);
    return card;
}

std::unique_ptr<Card> CardCollection::DrawCard(const int id)
{
    std::unique_ptr<Card> card = std::move(cards_[id]);
    cards_.erase(cards_.begin() + id);
    return card;
}

Card& CardCollection::GetCard(const int id)
{
    return *cards_[id];
}

Card& CardCollection::GetTopCard()
{
    return *cards_.back();
}

int CardCollection::GetSize() const
{
    return static_cast<int>(cards_.size());
}

bool CardCollection::IsEmpty() const
{
    return cards_.empty();
}

void CardCollection::Shuffle()
{
    const unsigned int seed = static_cast<unsigned>(std::chrono::system_clock::now().time_since_epoch().count());
    auto rng = std::default_random_engine {seed};
    std::shuffle(cards_.begin(), cards_.end(), rng);
}

void CardCollection::ClearCollection()
{
    cards_.clear();
}
