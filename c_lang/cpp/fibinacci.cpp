#include <iostream>

int print(int);

int main()
{
    std::cout << print(6);
    return 0;
}

int print(int n1)
{
    if(n1 <= 1)
    {
        return 1;
    }
    
    return print(n1-1) + print(n1-2);

}