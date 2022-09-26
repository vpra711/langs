/*
find the given parameters values in the url if found print the value otherwise print -1

input:                                                  examples:
(string) url                                                    https://www.bing.com/careers?heelo=hi&param_1=hi_1
(int) no of parameters: n                                       3
(string) parameter 1 to n                                       heelo param_1 param

output:
(string) value of the parameters in separate lines              hi
                                                                hi_1
                                                                -1
*/

#include <iostream>
#include <string>
#include <vector>

void printParam(std::string, int);

int main()
{
    std::string url;
    std::vector<std::string> param;
    std::string temp;
    int n, index, length;

    std::cin >> url;
    std::cin >> n;

    int i = 0;

    for(i = 0; i < n; i++)
    {
        std::cin >> temp;
        param.push_back(temp);
    }

    for(std::string i : param)
    {
        index = url.find(i);
        length = i.length();

        if(index != -1)
        {
            printParam(url, index + length + 1);
        }
        else
        {
            std::cout << "-1\n";
        }
    }
  
    return 0;
}

void printParam(std::string url, int index)
{
    int i = 0;
    std::string param;

    for(i = index; url[i] != '&' && url[i] != '\0'; i++)
    {
        if(url[i] == '=')
        {
            std::cout << "-1\n";
            return ;
        }

        param += url[i];
    }

    param += '\n';

    std::cout << param;
}