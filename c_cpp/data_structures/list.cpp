#include <iostream>
#include <list>

int main()
{
    std::list<int> l1;
    l1.push_front(1);
    l1.push_back(2);

    for(int i : l1)
        std::cout << i << "\t";

    return 0;
}