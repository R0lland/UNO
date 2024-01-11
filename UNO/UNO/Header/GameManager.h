#pragma once
#include <memory>

#include "Deck.h"
#include "Player.h"

class GameManager
{
private:
    std::unique_ptr<Deck> deck_ = std::make_unique<Deck>();
    std::shared_ptr<std::vector<Player>> players_ = std::make_shared<std::vector<Player>>();
    
public:
    void StartGame();
    void InitializePlayers();
    void CreatePlayers(int number_of_players);
};
