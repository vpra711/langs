#include <iostream>
#include <string>
#include <vector>

int main()
{
    int noOfStrings {6}, totalLength {}, rank {2}, i {}, j {}, k {};
    std::vector<std::string> strCollection;
    std::string str = "";
    std::cout << "begin : " << std::endl;
    //std::cin >> noOfStrings >> rank >> str;
    std::cin >> str;
    strCollection.push_back("");
    totalLength = str.length();

    for(i = 0; i <= totalLength; i++, k++)
    {
        if(str[i] == ',' || str[i] == '\0')
        {
            strCollection.push_back(str.substr(j, k));
            j = i + 1;
            k = -1;
        }
    }

    int l {};

    for (i = 1; i < noOfStrings + 1; i++)
        for (j = i + 1; j < noOfStrings + 1; j++)
            strCollection.push_back(strCollection.at(i) + strCollection.at(j));

    for(std::string it_str : strCollection)
        std::cout << it_str << std::endl;

    std::cout << strCollection.size() << std::endl;
    return 0;
}