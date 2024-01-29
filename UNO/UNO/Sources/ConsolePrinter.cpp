#include "ConsolePrinter.h"

#include <iostream>
#include <vector>

class Player;

void ConsolePrinter::ShowMessage(std::string message, const bool break_line)
{
    std::cout << message;
    if (break_line)
    {
        BreakLine();
    }
}

void ConsolePrinter::ShowActionMessage(std::string message, const bool break_line)
{
    std::cout << "- ";
    ShowMessage(message, break_line);
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

void ConsolePrinter::BreakLine(const int lines_to_break)
{
    for (int i = 0; i < lines_to_break; i++)
    {
        std::cout << std::endl;
    }
}

void ConsolePrinter::ClearConsole()
{
    system("CLS");
}
