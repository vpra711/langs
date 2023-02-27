/*

given a string find longest substring without repeating character.

input: abcabcab

ouput: abc

*/

#include <iostream>
#include <unordered_map>

int main()
{

    std::string input = "abcabcbb";

    int strLen = input.length();

    int i, j, subStrLen = 0;

    std::unordered_map<char, bool> mp;

    if(input == "")
    {
        return -1;
    }

    for(i = 0; i < strLen; i++)
    {
        mp.clear();

        for(j = i; j < strLen; j++)
        {
            if(mp.contains(input[j]))
            {
                break;
            }
            else
            {
                mp.insert(std::pair(input[j], true));
            }
        }

        if(j - i > subStrLen)
        {
            subStrLen = j - i;
        }
    }

    std::cout << subStrLen << std::endl;    

    return 0;
}