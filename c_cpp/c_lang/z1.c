#include <stdio.h>

int main()
{
    int x, y;

    for(x = 0; x < 100; x++)
    {
        for(y = 0; y < 20; y++)
        {
            printf("*");
        }

        printf("\n");
    }
    return 0;
}