#include <iostream>

int getRowSize();
int getColoumnSize();

int main()
{
    
    int arr[2][3];
    int i, j;

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            arr[i][j] = 0;
        }
    }

    for (i = 0; i < getRowSize(); i++)
    {
        for (j = 0; j < getColoumnSize(); j++)
        {
            std::cout << arr[i][j];
        }

        std::cout << std::endl;
    }


    return 0;
}

int getRowSize()
{
    std::cout << "in row size" << std::endl;
    return 2;
}

int getColoumnSize()
{
    std::cout << "in coloumn size" << std::endl;
    return 3;
}