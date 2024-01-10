#include "../Header/GameManager.h"

int main(int argc, char* argv[])
{
    const auto game_manager = std::make_unique<GameManager>();
    game_manager->start_game();
    
    return 0;
}

