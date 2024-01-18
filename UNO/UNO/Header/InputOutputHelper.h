#pragma once
#include <iostream>
#include <string>

class InputOutputHelper
{
public:
    template <typename TData>
    static TData GetInput(const std::string& message);

    template <typename TData>
    static TData ForceGetInput(const std::string& message);

    static bool InputNumberInRange(int min, int max, int number);
};

template <typename TData>
TData InputOutputHelper::GetInput(const std::string& message)
{
    TData return_value;
    std::cout << message;
    std::cin >> return_value;
    std::cout << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    return return_value;
}

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
