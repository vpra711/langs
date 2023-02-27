#include <iostream>

// enum name : datatype optional
// {

// };

// enum myenum1 : unsigned char
// {

// };

enum myenum
{
    a, b, c, d, e,
    min = a,
    max = e // It will increse by one starts A with 0 (default)
};

myenum operator++(myenum& , int);

int main()
{
    myenum me = a;
    
    while(me < 10)
    {
        std::cout << me++;
    }

    return 0;
}

myenum operator++(myenum& me2, int) 
{

    me2 = (myenum) (me2 + 1);

    if(me2 > max)
    {
        me2 = a;
    }

    return me2;
}