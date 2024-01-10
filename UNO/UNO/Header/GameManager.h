#pragma once
#include <memory>

#include "Deck.h"
#include "Player.h"

class GameManager
{
private:
    std::unique_ptr<Player> current_player_ = std::make_unique<Player>();
    std::unique_ptr<Deck> deck_ = std::make_unique<Deck>();

    std::shared_ptr<Player> players_ = std::make_shared<Player>();
public:
    void set_current_player_turn();
    void start_game();
};
