#include <iostream>

int main()
{
    int i = 0, j = 0, n = 5;

    for(i = 0; i < n; i++)
    {
        for(j = 0; j < n; j++)
        {
            std::cout << ((j + i) % 5) + 1;
        }
        std::cout << std::endl;
    }
    return 0;
}

/*
12345
23451
34512
45123
51234
*/