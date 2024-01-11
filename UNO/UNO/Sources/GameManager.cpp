#include "GameManager.h"

#include <Deck.h>

#include "GameConfig.h"
#include "../Header/InputOutputHelper.h"

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
        players_->push_back(Player{});
    }
    std::cout << players_->size();
}

void GameManager::StartGame()
{
    InitializePlayers();
    Deck deck{};
    deck.Generate();
}
