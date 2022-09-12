#include <stdio.h>

int countVowel(char[]);
int isVowel(char);

int main(void)
{
    char buffer[100];

    if(!gets(buffer))
        gets(buffer);
    
    printf("%d", countVowel(buffer));

    return 0;
}

int countVowel(char str[])
{
    int i = 0, count = 0;

    while(str[i] != '\0')
    {
        if(isVowel(str[i]))
            count++;
        i++;
    }

    return (count, i);
}

int isVowel(char c)
{
    if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        return 1;

    return 0;
}