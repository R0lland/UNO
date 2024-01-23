#include <ctime>

#include "GameManager.h"

int main(int argc, char* argv[])
{
    const auto game_manager = std::make_unique<GameManager>();
    srand(time(0));
    game_manager->InitializeGame();
    return 0;
}


