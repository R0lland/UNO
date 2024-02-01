#include "GameManager.h"

#include <Deck.h>

#include "ConsolePrinter.h"
#include "GameConfig.h"
#include "InputOutputHelper.h"

void GameManager::InitializePlayers()
{
    const std::string display_message = "How many player will be joining us, sir? [" + std::to_string(GameConfig::MIN_PLAYERS) + "-" + std::to_string(GameConfig::MAX_PLAYERS) + "]\n";
    const int number_of_players = InputOutputHelper::GetInputNumberInRange(GameConfig::MIN_PLAYERS, GameConfig::MAX_PLAYERS, display_message);
    CreatePlayers(number_of_players);
}

void GameManager::CreatePlayers(const int number_of_players)
{
    name_generator_->GenerateNames();
    for (int i = 0; i < number_of_players; i++)
    {
        players_.emplace_back(std::make_unique<Player>(name_generator_->GetName()));
    }
}

void GameManager::PrintPlayerHands() const
{
    for (const std::shared_ptr<Player>& player : players_)
    {
        ConsolePrinter::ShowMessage(player->GetName());
        player->PrintHand();
        ConsolePrinter::BreakLine(2);
    }
}

void GameManager::DealInitialCards() const
{
    for (const std::shared_ptr<Player>& player : players_)
    {
        DrawCardsForPlayer(player, GameConfig::NUMBER_OF_CARDS_TO_DEAL);
    }
}

void GameManager::DrawCardsForPlayer(const std::shared_ptr<Player>& player, const int number_of_cards) const
{
    for (int i = 0; i < number_of_cards; i++)
    {
        player->AddCardToHand(deck_->DrawTopCard());
    }
}

void GameManager::StartTurns()
{
    PrintPlayerHands();
    turn_manager_->Initialize(std::move(players_),  deck_);
}

void GameManager::InitializeData()
{
    InitializePlayers();
    deck_->Generate();
    DealInitialCards();
}

void GameManager::InitializeGame()
{
    while (!turn_manager_->GetGameEnded())
    {
        InitializeData();
        StartTurns();
    }
}
