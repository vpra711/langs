#include <iostream>
#include <cstdlib>
#include <cmath>

double mysqrt(double);

int main()
{
    int a, b = 9876;
    a = sqrt(b);
    std::cout << a << std::endl;
    std::cout << mysqrt(b) << std::endl;
    return 0;
}

double mysqrt(double value)
{
    int count = 0;
    double v1 = value;

    while(value > 1)
    {
        value /= 10;
        count++;
    }
    int v2 = v1;
    v2++;
    std::cout << "value : "<< v1 << "\tcount : " << count << std::endl;
    count++;
    double a = v2 >> count;
    return a;
}
