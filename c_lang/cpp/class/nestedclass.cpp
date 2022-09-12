#include <iostream>

class i1
{
    public:
        class i2
        {
            public:
                int i2a;
                double i2b;
                char i2c;

                i2()
                {
                    i2a = 0;
                    i2b = 0;
                    i2c = NULL;
                }

                i2(int a, double b, char c)
                {
                    i2a = a;
                    i2b = b;
                    i2c = c;
                }
        };
    
        int a;
        double b;
        char c;
        i2 i2q;

    i1()
    {
        a = 0;
        b = 0;
        c = NULL;
        i2q = i2();
    }

    i1(int a, double b, char c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
        this->i2q = i2(a, b, c);
    }

};

int main()
{
    i1 i = i1(1, 2.5, 'c');
    return 0;
}