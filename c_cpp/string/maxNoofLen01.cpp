#include <iostream>

int getMaxLength(std::string subStringpair);

int main()
{
    std::string input = "10110110";
    int inputLength = input.length();
    int i = 0, j = 0, count = 0, max = 0;

    for(i = 0; i < inputLength / 2; i++)
    {
        for(j = 0; j < inputLength; j++)
        {
            count = getMaxLength(input.substr());
        }
    }
    return 0;
}

int getMaxLength(std::string pair)
{
    if(pair == "")
        return 0;
    if(pair == "01" || pair == "10")
        return 2;
    else
        return(getMaxLength(pair.substr(0, 2)) + getMaxLength(pair));
}