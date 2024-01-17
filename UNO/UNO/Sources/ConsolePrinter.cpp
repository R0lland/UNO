#include "ConsolePrinter.h"

#include <iostream>

class Player;

void ConsolePrinter::ShowMessage(std::string message)
{
    std::cout << message << std::endl;
}