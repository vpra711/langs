#include <stdio.h>

int fibnacci(int);

void main()
{
    int a = fibnacci(40);
    printf("%d", a);
}

int fibnacci(int n)
{
    if(n < 2)  
        return n;
    else
        return fibnacci(n-1) + fibnacci(n-2);
}