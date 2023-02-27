#include <stdio.h>

void main()
{
    FILE *myFile = NULL;
    char *c;
    myFile = fopen("me1.txt", "a");
    while((c = getchar()) != '0') { fputc(c, myFile); }
    fclose(myFile);
}