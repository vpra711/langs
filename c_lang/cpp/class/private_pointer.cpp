#include <iostream>

class myclass
{
    int a;

    public:
        int* getinfo()
        {
            return &a;
        }
        void print()
        {
            std::cout << a << std::endl;
        }
};

int main()
{
    myclass mc;
    int *b = mc.getinfo(); 
    *b = 100;
    mc.print();
    *b = 123;
    mc.print();
    return 0;
}