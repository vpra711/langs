#include <iostream>

int main()
{
    int i = 0, j = 0, n = 5;

    for(i = 1; i < n+1; i++)
    {
        for(j = n; j > 0; j--)
        {
            if(j > i)
                std::cout << " ";
            else
                std::cout << j;
        }
        std::cout << std::endl;
    }
}

/*
    5
   45
  345
 2345
12345
*/