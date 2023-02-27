#include<stdio.h>

void main()
{
    FILE *fp;
    int n,i;
    long c;
    fp=fopen("new.txt","r");
    while((c=getc(fp)) != EOF)
        printf("%c",c);
    c=ftell(fp);
    printf("\nThe current position of the pointer is : %1d",c);
    fclose(fp);
}