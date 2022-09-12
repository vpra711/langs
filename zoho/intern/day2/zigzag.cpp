#include <iostream>

int main()
{
    int zigZagLength;
    std::cout << "Enter the zigzag : ";
    std::cin >> zigZagLength;

    int i = 0, j = 0, rowCounter = 1, rowVal = 0, colCounter = 0, result = 0;

    for(i = 1; i <= zigZagLength; i++)
    {
        colCounter = i + 1;
        result = rowCounter;

        for(j = 0; j <= zigZagLength - i; j++)
        {
            std::cout << result << "\t";
            result += colCounter++;
        }

        rowCounter += ++rowVal;
        colCounter--;
        result -= --colCounter;

        for(; j < zigZagLength; j++)
        {
            result += colCounter--;
            std::cout << result - 1 << "\t";
        }

        std::cout << std::endl;
    }
    
    return 0;
}