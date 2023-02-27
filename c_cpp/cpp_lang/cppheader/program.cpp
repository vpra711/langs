#include <iostream>
#include "header.hpp"

int main()
{
    std::cout << add(1, 2) << std::endl;
    std::cout << add(1.2f, 3.4f) << std::endl;
    std::cout << subract(100, 50) << std::endl;
    std::cout << subract(10.10f, 5.5f) << std::endl;
    return 0;
}