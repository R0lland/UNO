﻿#pragma once
#include <memory>

#include "Deck.h"
#include "NameGenerator.h"
#include "Player.h"

class GameManager
{
private:
    std::unique_ptr<Deck> deck_ = std::make_unique<Deck>();
    std::vector<std::unique_ptr<Player>> players_{};
    std::unique_ptr<NameGenerator> name_generator_ = std::make_unique<NameGenerator>();
public:
    void InitializeGame();
    void InitializePlayers();
    void CreatePlayers(int number_of_players);
    void DealInitialCards() const;
    void DrawCardsForPlayer(const std::unique_ptr<Player>& player, int number_of_cards = 1) const;
    void StartGame();
};
