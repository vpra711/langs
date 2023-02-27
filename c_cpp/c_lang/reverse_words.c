#include <stdio.h>
#include <string.h>

int main()
{
    char nameBuffer[100];

    if(!gets(nameBuffer))
        gets(nameBuffer);

    int i = 0, j = 0, check = -1, len = strlen(nameBuffer) + 1;
    
    for(i = 0; i < len; i++)
    {
        if((nameBuffer[i] != ' ' && nameBuffer[i+1] == ' ') || nameBuffer[i] == '\0')
        {
            j = i;

            while(j > -1 && nameBuffer[j] != ' ')
            {
                printf("%c", nameBuffer[j]);
                j--;
            }
        }

        if(nameBuffer[i] == ' ')
            printf("%c", ' ');
    }

    return 0;
}