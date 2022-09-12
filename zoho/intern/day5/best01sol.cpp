#include <iostream>

std::string itos(int);

int main()
{
    int input = 650307;
    std::string number ;
    std::string subNumber ;
    int i = 0;

    while(input != 0)
    {
        i = 0;
        number = itos(input);
        subNumber = "";

        while(number[i] != '\0')
        {
            if(number[i] == '0')
                subNumber += '0';
            else
                subNumber += '1';
            i++;
        }

        input -= stoi(subNumber);
        std::cout << subNumber << " + ";
    }

    return 0;
}

std::string itos(int input)
{
    std::string value;
    char number;

    while(input != 0)
    {
        number = (input % 10) + 48;
        value = number + value;
        input /= 10;
    }
    
    return value;
}