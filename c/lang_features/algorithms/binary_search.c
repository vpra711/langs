#include <stdio.h>

void main()
{
    int a[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}, start = 0, end = 10, mid = 0, target = 7;
    while(start <= end)
    {
        mid = start + (end - start) / 2;
        
        if( a[mid] == target )
        {
            printf("The element was found");
            break;
        }
        else if ( target > a[mid] )
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
}