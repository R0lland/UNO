#pragma once
#include <memory>

#include "Deck.h"
#include "Player.h"

class GameManager
{
private:
    std::unique_ptr<Deck> deck_ = std::make_unique<Deck>();
    std::vector<std::shared_ptr<Player>> players_{};
public:
    void InitializeGame();
    void InitializePlayers();
    void CreatePlayers(int number_of_players);
    void DealInitialCards() const;
    void DrawCardsForPlayer(const std::shared_ptr<Player>& player, int number_of_cards = 1) const;
    void StartGame();
};
