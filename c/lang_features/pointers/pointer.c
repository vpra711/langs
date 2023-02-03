#include <stdio.h>

void f(int *p, int *q)
{
    p = q;
    *p = 2;
}

int i = 0, j = 1;

void main()
{
    f(&i, &j);
    printf("%d\t%d",i,j);
}