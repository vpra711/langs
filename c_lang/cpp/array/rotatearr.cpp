#include <iostream>

int main()
{
    int a[] = {1, 2, 3}, noofElements {3}, lastToFirst {}, noofRotation {};
    std::cout << "Enter the no to rotate : ";
    std::cin >> noofRotation;

    for(int i = 0; i < noofRotation; i++)
    {
        lastToFirst = a[noofElements-1];

        for(int j = noofElements-1; j > -1; j--)
            a[j] = a[j-1];

        a[0] = lastToFirst;
    }

    for(int i = 0; i < noofElements; i++)
        std::cout << a[i];

    return 0;
}