#include <iostream>

template <typename t1>

void swap(t1 *a,t1 *a2)
{
    t1 temp = *a;
    std::cout << std::type_info()
    *a = *a2;
    *a2 = temp;
}


int main()
{
    int a = 10, b = 20;
    std::cout << "Before swapping : " << a << " and " << b << std::endl;
    swap(&a, &b);
    std::cout << "After swapping : " << a << " and " << b << std::endl;
    int *array = new int[a];
    
    for(int i = 0; i < 10; i++)
        std::cin >> array[i];

    for(int i = 0; i < 10; i++)
        std::cout << array[i];

    delete[] array;
    array = NULL;
    return 0;
}