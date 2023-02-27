#include <iostream>

int main()
{
    int m  = 3, n = 3;

    int matrix[][3] = {{1, 2, 3}
                    , {6, 7, 8}
                    , {11, 12, 13}};

    int i = 0, j = 0, x = 0, y = 0, c = 0, it = 0, it1;
    x = n-1, y = m-1;

    while(x >= 0 && y >= 0)
    {
        if(c % 2 == 0)
        {
            it1++;
            for(it = 0; it <= x; it++, j++)
                std::cout << matrix[i][j] << ",";

            j--, i++;

            for(it = it1; it <= y; it++, i++)
                std::cout << matrix[i][j] << ",";

            i--;
            std::cout << "\n";
        }
        else
        {
            j--;
            for(it = it1; it <= x; it++, j--)
                std::cout << matrix[i][j] << ",";

            for(it = 0; it <= y; it++, i--)
                std::cout << matrix[i][j] << ",";
            std::cout << "\n";
            i++, j++;
        }
        c++, x--, y--;
    }

    return 0;
}