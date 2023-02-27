#include <iostream>

int main()
{
    // lamda function - return type is not necessory
    // [capture_list] (parameters) -> return_type
    // {
    // };

    auto lamda = []() -> int
    {
        std::cout << "Hello from lamda function" << std::endl;
        return 0;
    };

    []() -> int
    {
        std::cout << "Hello from unassigned lamda function " << std::endl;
        return 0;
    }();

    [](int a, int b)
    {
        std::cout << "The sum is : " << a + b << std::endl;
    }(5, 6);

    auto lamda1 = [](int a, int b) -> double
    {
        std::cout << "the sum is : " << a + b << std::endl;
        return a + b;
    };

    double a {lamda1(34, 56)};

    std::cout << "The result : " << a << std::endl;

    auto lamda2 = [a]() 
    {
        std::cout << a << std::endl;
    }; // capture by value

    lamda2();

    double b {10};

    auto lamda3 = [&]()
    {
        std::cout << a << std::endl;
        std::cout << b << std::endl;
    }; // all variables are captured by reference

    lamda3();

    auto lamda4 = [=]()
    {
        std::cout << a << std::endl;
        if(true)
        {
            
        }
    }; // all variables are captured by copy

    return 0;
}