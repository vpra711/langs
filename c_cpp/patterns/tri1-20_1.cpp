#include <iostream>

int main()
{
    int input;
    std::cout << "Enter the number : ";
    std::cin >> input;

    int i, j, count = 1;

    for(i = 0; i < input; i++)
    {
        for(j = i; j < input; j++)
        {
            std::cout << count++ << "\t";
        }

        std::cout << std::endl;
    }
    return 0;
}

/*
    1  2  3  4
    5  6  7
    8  9 
    10
*/