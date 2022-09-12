#include <stdio.h>

void main()
{
    int a[] = {1, 9, 7, 36, 91, 101, 45, 8, 14, 102, 1, 4};
    int length = sizeof(a) / sizeof(int);
    int i = 0, j = 0, min = 0, max = 0;

    for(i = 0; i < length; i++)
        printf("%d\t", a[i]);
    
    printf("\n");

    for(i = 0; i < length; i++)
    {
        min = -1, max = -1;

        for(j = i+1; j < length; j++)
        {
            if(a[j] > a[i])
            {
                if(min == -1)
                    min = a[j];
                else if(a[j] < min)
                    min = a[j], max = a[j];
            }
        }
        
        a[i] = (max == -1)? min : max;
    }

    for(i = 0; i < length; i++)
        printf("%d\t", a[i]);
}