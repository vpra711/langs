#include <stdio.h>
#include <time.h>
#define MAX 100

void main()
{
    int A[MAX] , ii , jj , temp;
    clock_t t;  
    float ms;
    jj = MAX;

    for(ii = 0 ; ii < MAX ; ii++)
        A[ii] = jj--;

    t = clock(); // Timer is set 

    for(ii = 0 ; ii < MAX ; ii++)
        for(jj = 0 ; jj < MAX ; jj++)
            if(A[jj] > A[jj+1])
            {
                temp = A[jj+1];
                A[jj+1] = A[jj];
                A[jj] = temp;
            }      

    t = clock() - t; // Timer ending     

    printf("\nThe elements are : ");

    for(ii = 0 ; ii < MAX ; ii++)
        printf("%d\t",A[ii]);

    ms = (float) t / CLOCKS_PER_SEC; //calculating time and storing it to ms
    printf("\nTime taken (CPU) %.2f miliseconds",(ms*1000));
}