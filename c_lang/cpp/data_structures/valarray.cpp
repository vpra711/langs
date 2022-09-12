#include <iostream>
#include <valarray>

int main()
{
    //Valarray is only used in scientific computation. It is possible to modify the elements 
    //cannot add elements or remove elements
    std::valarray<int> va1 ={1,2,3,4,5};
    std::valarray<int> va2;
    va2 = va1.apply([](int x){return x=x*5;}); //apply() returns a valarray
    std::cout << va1.max() <<std::endl;
    std::cout << va2.max() << std::endl;

    std::cout << va1[1];

    for(int i : va1)
        std::cout << i << "\t";

    std::cout << std::endl;

    for(int i : va2)
        std::cout << i << "\t";

    return 0;
}