#include <iostream>

bool isInRange(char character);

int main()
{
    std::string input = "bahahab";
    int inputLen = input.length();
    int i = 0, j = 0;
    bool match = false;
    i = 0, j = inputLen - 1;

    while(i <= j)
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

    if(match)
        std::cout << "Yes" << std::endl;
    else
        std::cout << "no" << std::endl;

    return 0;
}