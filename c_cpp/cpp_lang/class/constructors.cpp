#include <iostream>

class heelo
{
    int a;
    public:
        heelo()
        {
            std::cout << "Default Constructor" << std::endl;
            a = 0;
        }

        heelo(int a)
        {
            std::cout << "Parameterized Constructor" << std::endl;
            this->a = a;
        }

        heelo(heelo &h)
        {
            std::cout << "Copy Constructor" << std::endl;
            this->a = h.a;
        }

        heelo(heelo &&h)
        {
            std::cout << "Move Constructor" << std::endl;
            this->a = h.a;
            h.a = 0;
        }

        ~heelo()
        {
            std::cout << "Default Destructor" << std::endl;
        }
};

int main()
{
    heelo a;
    return 0;
}