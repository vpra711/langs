/*

Reverse the string and replace the space by $ (or given symbol)

input: this string is used to testing

output: testing$to$used$is$string$this

*/

#include <iostream>

int main()
{
    std::string str = "this string is used to testing";
    char symbol = '$';
    int strLength = str.length(), i = strLength, j = 0;

    while(i > -1)
    {
        if(str[i] == ' ')
        {
            std::cout << symbol;
        }
        else if(str[i - 1] == ' ' || i == 0)
        {
            j = i;

            do
            {
                if(str[j] != ' ')
                {
                    std::cout << str[j];
                }

                j++;

            }while(str[j] != ' ' && j <= strLength);
        }

        i--;
    }

    return 0;
}