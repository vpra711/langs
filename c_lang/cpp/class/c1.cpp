#include <iostream>
#include <string>

class myname
{
    std::string _name;
    public : 
        myname() 
        {
            std::cout << "Deafult Constructor " << std::endl;
        }
        myname(std::string name)
        {
            _name = name;
            std::cout << "Parameterized Constructor" << std::endl;
        }
        ~myname()
        {
            std::cout << _name << std::endl;
            std::cout << "Default Destrctor" << std::endl;
        }  
        void input(std::string name)
        {
            _name = name;
        }      
        void print()
        {
            std::cout << _name << std::endl;
        }
};

int main()
{
    myname mn;
    std::cout << "step 1" << std::endl;
    mn.print();
    std::cout << " --------------------------------------" << std::endl;

    myname mn1 = myname("me");
        std::cout << "step 2" << std::endl;

    mn1.print();
    std::cout << " --------------------------------------" << std::endl;

    myname mn2;
        std::cout << "step 3" << std::endl;

    mn2.input("me2");
    mn2.print();
    std::cout << " --------------------------------------" << std::endl;

    return 0;
}