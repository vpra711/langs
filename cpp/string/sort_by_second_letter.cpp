/*

Given a string you have to sort the string based on the 2nd letter

Input : success consists of  eefort without using enthusiastics

Output :  eEfort oF wIthout eNthusiastics cOnsists uSing sUccess

*/

#include <iostream>
#include <map>

int main()
{
    std::multimap<char, std::string> mp;
    std::string sentance = "success consists of lot eesforts";

    int it;

    while(it != -1)
    { 
        it = sentance.find(' ');

        if(it != -1)
        {
            mp.insert({sentance[1], sentance.substr(0, it)});
            sentance = sentance.substr(it + 1);
        }
    }

    mp.insert({sentance[1], sentance.substr(0, INT_MAX)});

    for(auto ij = mp.begin(); ij != mp.end(); ij++)
    {
        std::cout << ij->first << " " << ij->second << std::endl;
    }

    return 0;
}

/*      method - 2

#include <iostream>
#include <algorithm>
#include <vector>

bool compare(std::string, std::string);

int main()
{
    std::vector<std::string> vec;
    std::string sentance = "success consists of lot eesforts";

    int it;

    while(it != -1)
    { 
        it = sentance.find(' ');

        if(it != -1)
        {
            vec.push_back(sentance.substr(0, it));
            sentance = sentance.substr(it + 1);
        }
    }

    vec.push_back(sentance.substr(0, INT_MAX));

    std::sort(vec.begin(), vec.end(), compare);

    for(std::string jt : vec)
    {
        std::cout << jt << std::endl;
    }

    return 0;
}

bool compare(std::string a, std::string b)
{
    if(a[1] < b[1])
    {
        return true;
    }

    return false;
}

*/