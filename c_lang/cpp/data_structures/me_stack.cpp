#include <iostream>

template<typename T>
class node
{
    private:
        T data;
        node* next;
        node* previous;

    public:
        void printData()
        {
            std::cout << data;
        }
};

class sk
{
    private:
        int length;

    public:
        void create()
        {

        }

        
};

int main()
{
    node* newNode = new node();
    return 0;
}