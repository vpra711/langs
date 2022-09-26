/*

array decalration in other function and passing 
the arrat to calling function


*/

#include <iostream>

int* arrfun()
{
    static int b[3] = {1,2,3};
    return b;
}

int main()
{
    int *a, i = 0;
    a = arrfun();

    for(i = 0; i < 3; i++)
        std::cout << a[i] << std::endl;

    return 0;
}