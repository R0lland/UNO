#pragma once
#include <memory>

#include "Deck.h"
#include "NameGenerator.h"
#include "Player.h"
#include "TurnManager.h"

class GameManager
{
private:
    std::shared_ptr<Deck> deck_ = std::make_shared<Deck>();
    std::vector<std::shared_ptr<Player>> players_{};
    std::unique_ptr<NameGenerator> name_generator_ = std::make_unique<NameGenerator>();
    std::unique_ptr<TurnManager> turn_manager_ = std::make_unique<TurnManager>();

    void PrintPlayerHands() const;
    void InitializePlayers();
    void CreatePlayers(int number_of_players);
    void DealInitialCards() const;
    void DrawCardsForPlayer(const std::shared_ptr<Player>& player, int number_of_cards = 1) const;
    void StartTurns();
    void InitializeData();
public:
    void InitializeGame();
};
