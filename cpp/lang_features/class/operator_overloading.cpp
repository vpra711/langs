#include <iostream>

class myclass
{
    int a;
    float b;
    
    public:
        myclass() = default;
        
        myclass(int a, float b)
            :a(a), b(b) {}

        myclass operator+(myclass &other) const
        {
            return myclass(a + other.a, b + other.b);
        }

        void print()
        {
            std::cout << a << std::endl;
            std::cout << b << std::endl;
        }
};

int main()
{
    myclass a = myclass(1, 2.0f);
    myclass b = myclass(2, 4.0f);
    myclass c = a + b;
    c.print();
    return 0;
}