#include <iostream>

int getBinaryValue(int);

int main()
{
    int A = 'A';
    int a = 'a';

    for(int i = 0; i < 26; i++)
    {
        std::cout << char(A + i) << " : " << getBinaryValue(A + i) << std::endl;
        std::cout << char(a + i) << " : " << getBinaryValue(a + i) << std::endl;
    }


    return 0;
}

int getBinaryValue(int value)
{
    int bit = 0;

    while(value != 1)
    {
        bit += value % 2; 
        bit *= 10;
        value /= 2;
    }

    return bit + 1;
}