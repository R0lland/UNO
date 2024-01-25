#include "ConsolePrinter.h"

#include <iostream>
#include <vector>

class Player;

void ConsolePrinter::ShowMessage(std::string message)
{
    std::cout << message << std::endl;
}

void ConsolePrinter::ShowActionMessage(std::string message)
{
    std::cout << "- " << message << std::endl;
}

void ConsolePrinter::ShowMessage(const std::vector<std::string>& lines)
{
    std::string fullMessage { };
    for (const std::string& msg : lines)
    {
        fullMessage += msg;
        fullMessage += "\n";
    }

    ShowMessage(fullMessage);
}

void ConsolePrinter::ClearConsole()
{
    system("CLS");
}
