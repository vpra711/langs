#include <iostream>
#include <unordered_map>

int main()
{
    std::unordered_map<std::string, int> mp;

    mp["heelo"] = 1;
    mp["heelo"]++;

    if(mp.contains("heelo"))
    {
        std::cout << mp["heelo"];
    }
    return 0;
}