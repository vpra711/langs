#include <stdio.h>

void main()
{
    const int a = 0;
    int *p = &a;
    *p = 10;
    printf("%d", a);
}