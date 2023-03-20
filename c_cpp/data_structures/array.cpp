#include <iostream>
#include <array>

int main()
{
    std::array<int, 5> a1 = {1,2,3,4,5};
    int *array = new int[10];
    
    for(int i : a1)
        std::cout << i << "\t";
}
