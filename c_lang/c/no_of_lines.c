#include <stdio.h>

void main()
{
    int count = 0;
    char c = '0';
    FILE *fp  = fopen("no_of_lines.c", "r+");

    while((c = fgetc(fp)) != EOF)
        if(c == '\n')
            count++;
            
    count++;
    printf("\nTotal lines : %d", count);
}