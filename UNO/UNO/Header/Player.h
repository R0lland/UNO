#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class Player
{
private:
    std::shared_ptr<std::vector<Card>> cards_ = std::make_shared<std::vector<Card>>();
public:
    Player() = default;
    void choose_card();
};
