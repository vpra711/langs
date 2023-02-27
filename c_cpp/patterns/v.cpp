#include <iostream>

int main()
{
    int i, j, k = 1, l = 11, r = 4;
    for( i = 0; i < r; i++)
    {
        for(j = 0; j < l ; j++)
        {
            if( k > j || (k + j >= l))
                std::cout << "* ";
            else
                std::cout << "  ";
        }
        std::cout << "\n";
        k += 2;
    }
}