#include <stdio.h>

void happening(int *p, int *q, int **r)
{
    (*p)++;
    ++(*q);
    printf("\n&q = %u\t *r = %u\t *q = %u\t **r = %u",--q,++(*r),*q,**r);
}

void main()
{
    int a = 0, b = 1, c = 2, *p = &c;
    void(*happening1)(int *, int *, int **) = happening;
    (*happening1)(&a, &b, &p);
    printf("\na = %u\tc = %u\tb = %u",a,*p,b);
}