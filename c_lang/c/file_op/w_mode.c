#include <stdio.h>

void main()
{
    FILE *file_pointer;
    char *fp, c;
    file_pointer = fopen("me1.txt","w");
    while((c = getchar()) != '0') { fputc(c, file_pointer); }  
    fclose(file_pointer);
}