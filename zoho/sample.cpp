#include <iostream>

int main()
{
    for(int i = 0; i < 256; i++)
    {
        std::string n = "";
        n += i;
        std::cout << n  << " " << i << std::endl;
    }
    return 0;
}