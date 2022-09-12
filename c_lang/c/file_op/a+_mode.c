#include <stdio.h>

void main()
{
    FILE *myFile;
    myFile = fopen("test.txt", "a+");
    fseek(myFile, 2, SEEK_SET);
    fprintf(myFile, "%s", "asdf");
    fclose(myFile);    
}