#include <iostream>
#include <cmath>
#include <algorithm>

int min(int, int, int, int);

int main()
{
    int square = 0;
    std::cout << "Enter the number : " ;
    std::cin >> square;
    int absValueOfSquare = std::abs(square);
    int squareSize = 2 * absValueOfSquare - 1;    
    int i = 0, j = 0, result = 0, len = 0;

    for(i = 0; i < squareSize; i++)
    {
        for(j = 0; j < squareSize; j++)
        {
            if(square < 0)
                result = square - min(squareSize - j - 1, squareSize - i - 1, j - 0, i - 0);
            else
                result = square + min(squareSize - j - 1, squareSize - i - 1, j - 0, i - 0);
            std::cout << result << '\t';
        }
        
        std::cout << '\n' <<std::endl;
    }

    return 0;
}

int min(int first, int second, int third, int fourth)
{
    if((first < second) && (first < third) && (first < fourth))
    {
        return first;
    }
    else if((second < third) && (second < fourth))
    {
        return second;
    }
    else if(third < fourth)
    {
        return third;
    }
    else
    {
        return fourth;
    }
}

/*
sample:
    3 3 3 3 3
    3 2 2 2 3
    3 2 1 2 3
    3 2 2 2 3
    3 3 3 3 3
*/