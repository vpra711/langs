#include <stdio.h>

void print(int, int);

void main()
{
    void(*print1)(int, int) = print;
    (*print1)(10,20);
}

void print(int a, int b)
{
    printf("%d",a+b);
}