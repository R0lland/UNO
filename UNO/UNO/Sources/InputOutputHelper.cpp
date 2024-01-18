#include "InputOutputHelper.h"

bool InputOutputHelper::InputNumberInRange(const int min, const int max, const int number)
{
    if (number > max || number < min)
    {
        return false;
    }

    return true;
}
