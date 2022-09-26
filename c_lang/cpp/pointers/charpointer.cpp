/*

guess the output and run the program

*/

#include <iostream>

int main()
{
    char a = 'z';
    char b = a;
    char *c = &a, *d = &b;
    
    std::cout << a << "\n" << c << std::endl;
    std::cout << b << "\n" << d << std::endl;

    std::string aa = "me";
    std::string bb = aa;
    std::string *cc = &aa, *dd = &bb;

    std::cout << aa << "\n" << cc << std::endl;
    std::cout << bb << "\n" << dd << std::endl;

    return 0;
}