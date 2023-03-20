#include <iostream>
#include <vector>

int main()
{
    std::vector<int> v1;
    v1.push_back(2);
    v1.push_back(3);
    v1.push_back(4);
    std::cout << v1.max_size() <<std::endl;
    std::cout << v1.size() << std::endl;

    for(int i : v1)
        std::cout << i << "\t";

    std::cout << std::endl;
    v1.pop_back();

    for(int i : v1)
        std::cout << i << "\t";
}