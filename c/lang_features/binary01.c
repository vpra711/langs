#include <stdio.h>

int main()
{
    int input, one = 0, zero = 0;

    scanf("%d", &input);

    while(input != 0)
    {
        if(input % 2 == 1)
            one++;

        input /= 2;
    }

    zero = sizeof(int) * 8 - one;

    printf("%d, %d", zero, one);
    return 0;
}