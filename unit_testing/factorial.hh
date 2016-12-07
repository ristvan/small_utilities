#pragma once

int factorial(int input)
{
    int result = 1;
    for (int index = 1; index <= input; ++index)
    {
       result *= index;
    }
    return result;
}
