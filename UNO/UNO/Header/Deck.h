#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class Deck
{
    typedef std::shared_ptr<std::vector<Card>> cards_map_pointer;
private:
    cards_map_pointer cards_ = std::make_shared<std::vector<Card>>();
public:
    Deck() = default;
    void Generate() const;
    void Shuffle() const;
};
