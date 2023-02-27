#include <stdio.h>
#include <stdlib.h>

void main()
{
    FILE *myFile = NULL;
    char c = 0;
    myFile = fopen("r_mode.c", "r");
    if(myFile == NULL)
    {
        printf("File Not Found!");
        exit(1);
    }
    while((c = fgetc(myFile)) && c != EOF) { printf("%c", c); }
    fclose(myFile);
}