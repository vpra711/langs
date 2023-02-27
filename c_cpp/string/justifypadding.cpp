#include <iostream>

int main()
{
    int pageSize = 17;
    std::string line = "heelo";
    line += " ";
    int i = 0;
    std::string justiPad;

    while(line[i] != '\0')
    {
        if(line[i] != ' ')
        {
            justiPad += line[i];

            if(line[i+1] == ' ')
            {
                justiPad += " ";
            }
        }

        i++;
    }

    justiPad = justiPad.substr(0, justiPad.length()-1);
    int spaceLength = pageSize - justiPad.length();

    if(justiPad.find(' ') == -1)
    {
        for(i = 0; i < spaceLength; i++)
        {
            justiPad += " ";
        }
        
    }
    else
    {
        i = 0;

        while(spaceLength > 0)
        {
            i %= justiPad.length();

            if(justiPad[i] == ' ' && justiPad[i + 1] != ' ')
            {
                justiPad = justiPad.substr(0, i+1) + ' ' + justiPad.substr(i+1, INT_MAX);
                spaceLength--;
                i++;
            }

            i++;
        }
    }

    std::cout << justiPad << std::endl;
    std::cout << justiPad.length() << std::endl;
}