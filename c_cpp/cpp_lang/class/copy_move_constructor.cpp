#include <iostream>

class myclass
{
    int a;
    double b;
    char *c;
    std::string v;

    public:
    
        myclass()
        {
            std::cout << "Default Constructor" << std::endl;
        }

        myclass(int a, double b, std::string v)
        {
            std::cout << "Parameterized Constructor" << std::endl;
            this->a = a;
            this->b = b;
            this->c = c;
        }

        myclass(myclass &copy)
        {
            std::cout << "Copy Constructor" << std::endl;
            this->a = copy.a;
            this->b = copy.b;
            this->c = copy.c;
        }

        myclass(myclass &&move)
        {
            std::cout << "Move Constractor" << std::endl;
            this->a = move.a;
            this->b = move.b;
            this->c = move.c;
            move.a = 0;
            move.b = 0;
            move.c = nullptr;
        }

        ~myclass()
        {
            std::cout << "Default Destructor" << std::endl;
        }

        void print()
        {
            std::cout << "Integer : " << a << std::endl;
            std::cout << "Double : " << b << std::endl;
            std::cout << "char array : " << c << std::endl;  
        }
};

class myclass2
{
    myclass hello;

    public:
        myclass2()
        {
            std::cout << "Default Constractor from class2" << std::endl;
        }

        myclass2(myclass &&move) : hello(move)
        {
            std::cout << "Move Constrcutor from myclass2" << std::endl;
        }

        ~myclass2()
        {
            std::cout << "Destructor from myclass2" << std::endl;
        }

        void print()
        {
            hello.print();  
        }
};

int main()
{
    myclass c1 = myclass(1, 2.5, "me");
    std::cout << "----------------------------------" << std::endl;

    myclass c2 = myclass(c1);
    std::cout << "----------------------------------" << std::endl;

    myclass2 c21 = myclass2(myclass(1, 2.5, "me from myclass2"));
    std::cout << "----------------------------------" << std::endl;

    c1.print();
    std::cout << "----------------------------------" << std::endl;

    c2.print();
    std::cout << "----------------------------------" << std::endl;

    c21.print();
    
    return 0;
}