#include "GameManager.h"

#include <Deck.h>

#include "GameConfig.h"
#include "InputOutputHelper.h"

bool NumberOfPlayersIsValid(const int number_of_players)
{
    if (number_of_players < GameConfig::MIN_PLAYERS || number_of_players > GameConfig::MAX_PLAYERS)
    {
        return false;
    }

    return true;
}

void GameManager::InitializePlayers()
{
    int number_of_players = 0;
    const std::string display_message = "How many player will be joining us, sir? [" + std::to_string(GameConfig::MIN_PLAYERS) + "-" + std::to_string(GameConfig::MAX_PLAYERS) + "]\n";
    while (!NumberOfPlayersIsValid(number_of_players))
    {
        number_of_players = InputOutputHelper::force_get_input<int>(display_message);
    }
    CreatePlayers(number_of_players);
}

void GameManager::CreatePlayers(const int number_of_players)
{
    for (int i = 0; i < number_of_players; i++)
    {
        players_.emplace_back(std::make_unique<Player>(name_generator_->GetName()));
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
    for (const std::unique_ptr<Player>& player : players_)
    {
        std::cout << player->GetName() << std::endl;
        player->PrintHand();
        std::cout << std::endl;
    }
}

void GameManager::InitializeGame()
{
    InitializePlayers();
    deck_->Generate();
    DealInitialCards();
    StartGame();
    int a;
    std::cin >> a;
}
