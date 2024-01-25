#pragma once
#include <string>
#include <vector>

class ConsolePrinter
{
public:
    static void ShowMessage(std::string message);
    static void ShowActionMessage(std::string message);
    static void ShowMessage(const std::vector<std::string>& lines);
    static void ClearConsole();
};
