#include "GameManager.h"

#include <Deck.h>

#include "ConsolePrinter.h"
#include "GameConfig.h"
#include "InputOutputHelper.h"

void GameManager::InitializePlayers()
{
    int number_of_players = 0;
    const std::string display_message = "How many player will be joining us, sir? [" + std::to_string(GameConfig::MIN_PLAYERS) + "-" + std::to_string(GameConfig::MAX_PLAYERS) + "]\n";
    while (!InputOutputHelper::InputNumberInRange(GameConfig::MIN_PLAYERS, GameConfig::MAX_PLAYERS, number_of_players))
    {
        number_of_players = InputOutputHelper::ForceGetInput<int>(display_message);
    }
    CreatePlayers(number_of_players);
}

void GameManager::CreatePlayers(const int number_of_players)
{
    players_.reserve(number_of_players);
    for (int i = 0; i < number_of_players; i++)
    {
        players_.emplace_back(std::make_unique<Player>(name_generator_->GetName()));
    }
}

void GameManager::PrintPlayerHands() const
{
    for (const std::unique_ptr<Player>& player : players_)
    {
        std::cout << player->GetName() << std::endl;
        player->PrintHand();
        std::cout << std::endl << std::endl;
    }
}

void GameManager::DealInitialCards() const
{
    for (const std::unique_ptr<Player>& player : players_)
    {
        DrawCardsForPlayer(player, GameConfig::NUMBER_OF_CARDS_TO_DEAL);
    }
}

void GameManager::DrawCardsForPlayer(const std::unique_ptr<Player>& player, const int number_of_cards) const
{
    for (int i = 0; i < number_of_cards; i++)
    {
        player->AddCardToHand(deck_->DrawCard());
    }
}

void GameManager::StartGame()
{
    PrintPlayerHands();

    ConsolePrinter::ShowMessage("------GAME STARTED-------");
    
    turn_manager_ = std::make_unique<TurnManager>(std::move(players_),  std::move(deck_));
    turn_manager_->InitializeTurns();
}

void GameManager::InitializeGame()
{
    InitializePlayers();
    deck_->Generate();
    DealInitialCards();
    StartGame();
}