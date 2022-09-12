#include <stdio.h>

void main()
{
    FILE *myFile;
    myFile = fopen("test.txt", "r+");
    fseek(myFile, 2, SEEK_SET);
    char *c ;
    fscanf(myFile, "%s", c);
    printf("%s", c);
    fclose(myFile);    
}