#include <stdio.h>
#include <stdlib.h>

void main()
{
    int A[100] , ii ;

    for(ii = 0 ; ii < 100 ; ii++)
        A[ii] = rand() % 500;

    for(ii = 0 ; ii < 100 ; ii++)
        printf("%d\t",A[ii]);
}