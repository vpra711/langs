#include <iostream>

int main()
{
    int zigZag = 5;
    
    //std::cout << "Enter the zigzag : " << "\t";
    //std::cin >> zigZag;

    int i = 0, j = 0, row = 0, previousRowVal = 0, col = 0, rowCounter = 1;

    for(i = 0; i <= zigZag; i++)
    {
        if(i % 2 == 0)
        {
            row = 1;
        }
        else
        {
            row = 2 * rowCounter;
            rowCounter += 2;
        }

        previousRowVal += row;
        std::cout << previousRowVal << std::endl;

    }
    

    return 0;
}