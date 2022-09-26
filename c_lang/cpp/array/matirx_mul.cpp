#include <iostream>

#define ROW 2
#define COL 2

int main()
{
    int mat1[ROW][COL];
    int mat2[ROW][COL];
    int res[ROW][COL];

    int i, j, k;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            std::cin >> mat1[i][j];
        }
    }

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            std::cin >> mat2[i][j];
        }
    }

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            std::cout << mat1[i][j] << '\t';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            std::cout << mat2[i][j] << '\t';
        }

        std::cout << std::endl;
    }

    std::cout << std::endl;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            res[i][j] = 0;

            for(k = 0; k < COL; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            std::cout << res[i][j] << '\t';
        }

        std::cout << std::endl;
    }

    return 0;
}