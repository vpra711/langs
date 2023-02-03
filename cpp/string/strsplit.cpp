#include <iostream>
#include <vector>

std::vector<std::string> strsplit(std::string str, std::string delimeter);

int main()
{
    if(!NULL)
    {
        std::cout << "heelo from not null" << std::endl;
    }

    return 0;
}

std::vector<std::string> strsplit(std::string str, std::string delimeter)
{
    std::vector<std::string> parts;
    int index = str.find(delimeter);
    int deliLength = delimeter.length();

    if(index == -1 || deliLength == 0 || str.length() == 0)
    {
        return parts;
    }

    while(index != -1)
    {
        parts.push_back(str.substr(0, index));
        str = str.substr(index + deliLength);
        index = str.find(delimeter);
    }

    parts.push_back(str);

    return parts;
}