#include <iostream>

int mul(int a, int b)
{
    return a*b;
}

int main()
{
    //return Datatype (*pointername) (parameters/arguments)
    int(*ptomul)(int, int);
    ptomul = mul;
    std::cout << ptomul(2, 2) << std::endl;
    return 0;
}