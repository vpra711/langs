#include <iostream>

int getSpaceLength(std::string str, int i);
int getWordLength(std::string, int);
int getNoOfWords(std::string);
std::string justifyLength(std::string, int);

int main()
{
    std::string a = justifyLength("  asdf ghy ", 10);
    std::cout << a << std::endl;
    return 0;
}

std::string justifyLength(std::string input, int pageSize)
{
    std::string output;
    int inputLength = input.length();
    int noOfWords = 0;
    int wordLength = 0;
    int i = 0, j = 0;


    while(input[i] != '\0')
    {
        while(input[i] == ' ')
        {
            i++;
        }

        noOfWords++;
        wordLength = getWordLength(input, i);
        output += input.substr(i, wordLength) + ' ';
        pageSize -= wordLength + 1;
        i += wordLength + 1;
        j++;
    }

    if(noOfWords == 1)
    {
        for(j = 0; j < pageSize; i++)
        {
            output[i] += ' ';
        }
    }
    else
    {
        int outputLength = output.length();
        int extraSpace = pageSize;
        i = 0, j = 0;
        int  indexValue = 0;

        j = 2;
        while(extraSpace > 0)
        {
            for(i = 0; i < output.length() && extraSpace > 0; i++)
            {
                if(output[i] == ' ')
                {
                    if(getSpaceLength(input, i))
                    {
                        output = output.substr(0, i) + ' ' + output.substr(i, output.length());
                        extraSpace--;
                    }
                    i += getSpaceLength(input, i);
                }
            }
            j++;
        }
    }

    return output;
}

int getWordLength(std::string str, int i)
{
    int len = 0;
    int strLength = str.length();

    for(; str[i] != ' ' && i < strLength; i++)
    {
        len++;
    }

    return len;
}

int getNoOfWords(std::string str)
{
    int len = 0;
    int i = 0;
    int wordLength = 0;

    for(i = 0; i < str.length(); i++)
    {
        if(str[i] != ' ')
        {
            wordLength = getWordLength(str, i);
            i += wordLength;
            len++;
        }
    }

    return len;
}

int getSpaceLength(std::string str, int i)
{
    int len = 0;
    int strLength = str.length();

    for(; str[i] == ' ' && i < strLength; i++)
    {
        len++;
    }

    return len;
}