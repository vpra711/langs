#include <iostream>

int main()
{
    int a = 0, iLength = 0, hLength = 0, cp = 0, fn = 0, mn = 0, ln = 0, i = 0;
    std::cin >> a;
    cp = a;

    while(a > 1)
    {
        iLength++;
        a /= 10;        
    }
    iLength++;

    a = cp;
    hLength = iLength / 2 + 1;

    for(i = iLength; i > 0; i--)
    {
        if(i == hLength)
            mn = a % 10;
        else if (i > hLength)
            ln += a % 10;
        else
            fn += a % 10;

        a /= 10;
    }    

    if(fn == ln)
        std::cout << fn << "" << mn << "" << ln << std::endl;
    else
        std::cout << "The number is not same at the first and the last" << std::endl;
        
    return 0;
}