/*
checks whether the email valid or not. if valid print True otherwise print false
this program uses regex

input:                                                          example:
(int) no of emails                                              2
(string) array of emails                                        abc@abc.com
                                                                abc@abc

output:                                                             
(string) True or False in separate lines                        True
                                                                False
*/

#include <iostream>
#include <vector>
#include <regex>

bool isValidEmail(std::string);

int main()
{
    int n;
    std::vector<std::string> emails;
    std::string temp;

    int i = 0;

    std::cin >> n;

    for(i = 0; i < n; i++)
    {
        std::cin >> temp;
        emails.push_back(temp);
    }

    for(std::string i : emails)
    {
        if(isValidEmail(i))
        {
            std::cout << "True\n";
        }
        else
        {
            std::cout << "False\n";
        }
    }

    return 0;
}

bool isValidEmail(std::string email)
{
    const std::regex pattern("(\\w+)(\\.|_)?(\\w*)@(\\w+)(\\.(\\w+))+");
    return std::regex_match(email, pattern);
}