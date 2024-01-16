#include "GameManager.h"

int main(int argc, char* argv[])
{
    const auto game_manager = std::make_unique<GameManager>();
    game_manager->InitializeGame();
    return 0;
}


