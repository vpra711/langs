#include <iostream>

int main()
{
    int input;
    std::cout << "Enter the number : ";
    std::cin >> input;
    int i, j, lastValue;
    int count;

    for(i = 1; i <= input; i++)
    {
        count = input;
        lastValue = i;
        for(j = i; j <= input; j++)
        {
            std::cout << lastValue << "\t";
            lastValue = lastValue + count--;
        }
        std::cout << std::endl;
    }
}

/*
    1 5 8 10
    2 6 9
    3 7
    4
*/
