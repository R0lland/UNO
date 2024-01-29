#pragma once
#include <string>
#include <vector>

class ConsolePrinter
{
public:
    static void ShowMessage(std::string message, const bool break_line = true);
    static void ShowActionMessage(std::string message, bool break_line = true);
    static void ShowMessage(const std::vector<std::string>& lines);
    static void BreakLine(const int lines_to_break = 1);
    static void ClearConsole();
};
