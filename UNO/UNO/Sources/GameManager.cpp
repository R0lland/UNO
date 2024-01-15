#include "GameManager.h"

#include <Deck.h>

#include "GameConfig.h"
#include "InputOutputHelper.h"

bool NumberOfPlayersIsValid(const int number_of_players)
{
    if (number_of_players < GameConfig::MIN_PLAYERS || number_of_players > GameConfig::MAX_PLAYERS)
    {
        std::cout << "You cannot add that amount of players, it needs to be between " << GameConfig::MIN_PLAYERS << " and " << GameConfig::MAX_PLAYERS << std::endl;
        return false;
    }

    return true;
}

void GameManager::InitializePlayers()
{
    int number_of_players = 0;
    const std::string display_message = "How many player will be joining us? ";
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
        players_.emplace_back(std::make_shared<Player>());
    }
    std::cout << players_.size() << std::endl;
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
        player->AddCardToHand(deck_->DrawCard());
    }
}

void GameManager::StartGame()
{
    InitializePlayers();
    deck_->Generate();
    DealInitialCards();
}
