#include "ConsolePrinter.h"

#include <iostream>
#include <vector>

#include "ColorUtils.h"

class Player;

void ConsolePrinter::ShowMessage(std::string message, const bool break_line)
{
    std::cout << message;
    if (break_line)
    {
        BreakLine();
    }
}

void ConsolePrinter::ShowActionMessage(const std::string message, const bool break_line)
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

void ConsolePrinter::ShowCenterMessage(std::string turn_message)
{
    std::string dots = "---------------------------------------------------";
    std::string full_message = dots + " " + turn_message + " " + dots;
    ColorUtils::PrintTextWithColor(full_message, "grey");
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
