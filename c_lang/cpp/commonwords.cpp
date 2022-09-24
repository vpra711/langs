/* get the common words from the three lines/paragraph

input:                                              example:
(string) line1                                      a word is beautiful
(string) line2                                      a word not beautiful
(string) line3                                      the word is attractive

output:
(string) common word form all the three lines       word

*/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>

std::vector<std::string> strsplit(std::string, std::string);

int main()
{
    std::string line1, line2, line3, temp;
    std::vector<std::string> vec;
    std::unordered_map<std::string, int> mp;

    std::getline(std::cin, line1);
    std::getline(std::cin, line2);
    std::getline(std::cin, line3);

    line1 += " " + line2 + " " + line3;

    vec = strsplit(line1, " ");

    for(std::string i : vec)
    {
        if(mp.contains(i))
        {
            mp[i]++;
        }
        else
        {
            mp[i] = 1;
        }
    }

    for(std::pair<std::string, int> it : mp)
    {
        if(it.second >= 3)
        {
            std::cout << it.first << "\n";
        }
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