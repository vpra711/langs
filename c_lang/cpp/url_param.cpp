#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::string url;
    std::vector<std::string> param;
    std::string temp;
    int n, index, length;

    std::getline(std::cin, url);
    std::cin >> n;

    length = url.length();
    int i = 0;

    for(i = 0; i < n; i++)
    {
        std::getline(std::cin, temp);
        param.push_back(temp);
    }

    for(std::string i : param)
    {
        index = url.find(i);
        
        if(index < n)
        {
            temp = url
        }
    }

    

    return 0;
}