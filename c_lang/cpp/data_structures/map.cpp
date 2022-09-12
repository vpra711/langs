#include <iostream>
#include <iterator>
#include <map>

int main()
{
    std::map<int, int> m1;
    m1[1] = 40;
    m1.insert(std::pair<int, int>(2,50));
    m1.insert({3, 60});
    m1.insert({4, 20});

    for(std::map<int, int>::iterator i = m1.begin(); i != m1.end(); ++i)
    {
        std::cout << i->first << "\t"
        << i->second << std::endl;
    }

    m1.erase(m1.find(1));

    for(std::map<int, int>::iterator i = m1.begin(); i != m1.end(); ++i)
    {
        std::cout << i->first << "\t"
        << i->second << std::endl;
    }
}