#pragma once
#include <iostream>
#include <string>
#include <vector>

class InputOutputHelper
{
public:
    template <typename TData>
    static TData ForceGetInput(const std::string& message);

    static bool InputNumberInRange(int min, int max, int number);
    static int GetInputNumberInRange(int min, int max, const std::string& message);
    static int GetInputNumberInRanges(std::vector<std::tuple<int, int>> ranges, const std::string& message);
};

template <typename TData>
TData InputOutputHelper::ForceGetInput(const std::string& message)
{
    TData input{};
    std::cout << message;
    std::cin >> std::ws >> input;
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore();
        return ForceGetInput<TData>(message);
    }
    return input;
}
