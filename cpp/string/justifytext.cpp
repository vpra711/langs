#include <iostream>

std::string justifyLine(std::string line, int pageSize);

int main()
{
    int pageSize = 25;
    std::string text = "what's new in madurai? zoho started in madurai.";
    text += " ";
    int i = 0;
    std::string justifiedText;

    while(1)
    {
        if(text.length() > pageSize)
        {
            i = pageSize;

            while(i >= 0)
            {
                if(text[i] == ' ')
                {
                    justifiedText += justifyLine(text.substr(0, i), pageSize);
                    break;
                }

                i--;
            }

            text = text.substr(i, INT_MAX);
        }
        else
        {
            justifiedText += justifyLine(text, pageSize);
            break;
        }
    }

    std::cout << justifiedText << std::endl;
}

std::string justifyLine(std::string line, int pageSize)
{
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

    return justiPad + '\n';
}