#pragma once
#include <memory>
#include <vector>

#include "Card.h"

class Player
{
private:
    std::shared_ptr<std::vector<Card>> cards_;
public:
    void choose_card();
};
