#include "InputOutputHelper.h"

#include <tuple>
#include <vector>

bool InputOutputHelper::InputNumberInRange(const int min, const int max, const int number)
{
    if (number > max || number < min)
    {
        return false;
    }

    return true;
}

int InputOutputHelper::GetInputNumberInRanges(const std::vector<std::tuple<int, int>> ranges, const std::string& message)
{
    int id = -1;
    const int ranges_size = static_cast<int>(ranges.size());
    bool id_is_valid = false;
    while (!id_is_valid)
    {
        id = ForceGetInput<int>(message);
        for (int i = 0; i < ranges_size; i++)
        {
            if (InputNumberInRange(std::get<0>(ranges[i]), std::get<1>(ranges[i]), id))
            {
                id_is_valid = true;
            }
        }
    }
    
    return id;
}

int InputOutputHelper::GetInputNumberInRange(const int min, const int max, const std::string& message)
{
    int id = min - 1;
    while (!InputNumberInRange(min, max, id))
    {
        id = ForceGetInput<int>(message);
    }
    return id;
}
