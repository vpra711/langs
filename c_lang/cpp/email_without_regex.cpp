#include <iostream>
#include <string>
#include <vector>

bool isValidEmail(std::string);
bool isValidChar(char);

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
            std::cout << "\nTrue";
        }
        else
        {
            std::cout << "\nFalse";
        }
    }

    return 0;
}

bool isValidEmail(std::string email)
{
    int i = 0, count = 0;
    std::string firstPart;
    std::string secondPart;

    for(i = 1; i < email.length(); i++)
    {
        if(isValidChar(email[i]))
        {
            if(email[i] == '@')
            {
                count++;
                if(count > 1)
                {
                    return 0;
                }

                firstPart = email.substr(0, i+1);
                secondPart = email.substr(i+2, INT_MAX);
            }
        }
        else
        {
            return false;
        }
    }

    count = 0;

    for(char i : secondPart)
    {
        if(i == '@')
        {
            return false;
        }
        else if(i == '.')
        {
            count++;
        }
    }

    if(count > 0)
    {
        return true;
    }

    return false;
 
}

bool isValidChar(char c)
{
    if((c > 96 && c < 123) || c == '@' || c == '.')
    {
        return true;
    }

    return false;
}