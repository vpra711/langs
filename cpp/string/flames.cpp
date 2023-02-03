#include <iostream>

int main()
{
    const char zero = '0';
    std::string firstName = "abc";
    std::string secondName = "acccb";
    std::string flames = "flames";

    int firstNameLength = firstName.length();
    int secondNameLength = secondName.length();
    int i = 0, j = 0;

    for(i = 0; i < firstNameLength; i++)
    {
        for(j = 0; j < secondNameLength; j++)
        {
            if(firstName[i] == secondName[j])
            {
                firstName[i] = zero;
                secondName[j] = zero;
                break;
            }
        }
    }
     
    std::string flameString = firstName + secondName;

    int flamesLength = 0;
    int flameStringLen = flameString.length();
    j = flameStringLen;

    for(i = 0; i < j; i++)
    {
        if(!(flameString[i] == zero))
            flamesLength++;
    }

    int k = 0;

    for(i = 0; i < 5; i++)
    {
        j = 0;
        while(j < flamesLength)
        {
            if(k > 5)
            {
                k %= 6;
            }
            else if(flames[k] == zero)
            {
                k++;
            }
            else if(flames[k] != zero)
            {
                j++;
                k++;
            }
        }
        k--;
        flames[k] = zero;

    }

    char relation = zero;

    for(i = 0; i < flameStringLen; i++)
    {
        if(flames[i] != '0')
        {
            std::cout << flames[i] << std::endl;
            relation = flames[i];
        }
    }

    std::string fri = "friend";
    std::string love = "love";
    std::string affec = "affection";
    std::string marriage = "marriage";
    std::string enemy = "enemy";
    std::string sibling = "sibling";
    std::string relation1;
    
    switch(relation)
    {
        case 'f' : relation1 = fri; break;
        case 'l' : relation1 = love; break;
        case 'a' : relation1 = affec; break;
        case 'm' : relation1 = marriage; break;
        case 'e' : relation1 = enemy; break;
        case 's' : relation1 = sibling; break;
    }

    std::cout << relation1 << std::endl;

    return 0;
}