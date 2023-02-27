#include<iostream>

class asdf
{
    int a,b,c;
    public:
        void set(int a, int b, int c)
        {
            this->a = a;
            this->b = b;
            this->c = c;
        }

        void get()
        {
            std::cout << a << std::endl;
            std::cout << b << std::endl;
            std::cout << c << std::endl;
        }
};

class methodChainnig
{
    int number;
    float fl;
    public:
        methodChainnig & assign(int number,float fl)
        {
            this->number = number;
            this->fl = fl;
            return *this;
        }

        void display()
        {
            std::cout << number << std::endl;
        }
};

int main()
{
    asdf ob;
    ob.set(1,2,3);
    ob.get();
    methodChainnig  mC;
    mC.assign(222,4.5).display();
    return 0;
}