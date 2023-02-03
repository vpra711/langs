#pragma pack(1) // tells the compiler to turn off structure padding
#include <stdio.h>

struct computer
{
    char cpu;
    int a;
}c1;

void main()
{
    c1.a = 23;
    c1.cpu = 'a';
    struct computer c2 = {.a = 10, .cpu = 'b'};
    printf("%d\t%d", sizeof(c1), sizeof(int));
}