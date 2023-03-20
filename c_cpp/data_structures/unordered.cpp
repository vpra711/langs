#include <iostream>
#include <unordered_map>
#include <unordered_set>

int main()
{
    std::unordered_map<int, int> um1;
    std::unordered_set<int> us1;
    std::unordered_multimap<int, int> umm1;
    std::unordered_multiset<int> ums1;
    um1.insert({{1,2},{2,3},{3,4},{3,4}});
    us1.insert({2,3,4,5,6,7});
    umm1.insert({{1,2},{1,2},{2,4}}); //multimap and set allows multiple same value and maintain a count 
    ums1.insert({1,2,3,4,4,3,5,6});

    for(auto i = um1.begin(); i != um1.end(); i++)   
        std::cout << i->first << "\t" << i->second << "\n";

    std::cout << std::endl;

    for(auto i = umm1.begin(); i != umm1.end(); i++)
        std::cout << i->first << "\t" << i->second << "\n";

    std::cout << std::endl;

    for(auto i = us1.begin(); i != us1.end(); i++)
        std::cout << *i << "\n";

    std::cout << std::endl;

    for(auto i = ums1.begin(); i != ums1.end(); i++)
        std::cout << *i << "\n";

    std::cout << std::endl;
    return 0;
}