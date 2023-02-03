#include <iostream>
#include <vector>
#include <set>

int main()
{
    int k, it = 0, count = 0;
    std::string s;
    std::vector<std::string> substrs;
    std::set<char> charset;

    std::cin >> s >> k;

    while(s[it + (k - 1)] != '\0')
    {
        substrs.push_back(s.substr(it, k));
        it++;
    }

    for(std::string i : substrs)
    {
        for(char j :  i)
        {
            charset.insert(j);
        }

        if(charset.size() == (k - 1))
        {
            count++;
        }

        charset.clear();
    }

    std::cout << count;
    return 0;
}

/*given a string S and an integer K.find the count of all substrings of length K which have 
exactly K-1 distinct characters*/