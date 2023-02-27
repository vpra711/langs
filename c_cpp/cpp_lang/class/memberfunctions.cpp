#include <iostream>

class heelo
{
    int a;
    int c;
    static int b;
    friend class hi; // friend class
    friend void he(); // friend function
    public:
        void h1() // just a normal function
        {
            a = 0;
            hi b;
            b.as = 0; //accessing private member of hi using friend
        }

        static void s1() // static member function
        {
            b = 0;
            //this keyword will not work inside static member functions
            //it only works on static members
        }

        void c1() const //constant function
        {
            b = 10;
            // cannot use non-const variables.
        } 

        //There is also a function called inline function by default all public functions are inline 
        // or we can define a function as inline using inline keyword.
};

void he()
{
    std::cout << "heelo" << std::endl;
    heelo a;
    a.a = 0;
}

class hi
{
    private:
        friend class heelo;
        int g;
        int as;

    hi()
    {
        heelo a;
        a.a = 0; // Accessing class private member using friend functions
    }
};

int main()
{
    std::cout << "Heelo" << std::endl;
    return 0;
}