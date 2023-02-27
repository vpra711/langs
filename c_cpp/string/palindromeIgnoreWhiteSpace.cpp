#include <iostream>

bool isInRange(char character);

int main()
{
    std::string input = "a+b#ccba";
    int inputLen = input.length();
    int i = 0, j = 0;
    bool match = false;
    i = 0, j = inputLen - 1;

    while(i <= j)
    {
        if(isInRange(input[i]))
        {
            if(isInRange(input[j]))
            {
                if(input[i] == input[j])
                {
                    match = true;
                }
                else
                {
                    match = false;
                    break;
                }
                
                i++, j--;
            }
            else
            {
                j--;
            }
        }
        else
        {
            i++;
        }
    }

    if(match)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "no" << std::endl;

    return 0;
}

bool isInRange(char character)
{
    if((character >= 'a' && character <= 'z')  || (character >= 'A' && character <= 'Z') || character == ' ' || (character >= '0' && character <= '9'))
        return true;
        
    return false;
}