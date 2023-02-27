#include <stdio.h>

void main()
{
    int array[10] = {10, 9 , 8, 7, 6, 5, 4, 3, 2, 1}, i, min = array[0], min1 = array[1];

    for(i = 0; i < 10; i++)
    {
        if(array[i] < min1)
        {
            if(array[i] < min)
            {
                min1 = min;
                min = array[i];
            }
            else
                min1 = array[i];
        }
    }

    printf("The value is min = %d and min2 = %d", min, min1);
}