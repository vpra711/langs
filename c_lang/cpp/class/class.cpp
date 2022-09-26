#include <iostream>

class instrument
{
    public:
        virtual void sound()
        {
            std::cout << "An intrument is playing" << std::endl;
        }
};

class piano:public instrument
{
    public:
        void sound()
        {
            std::cout << "piano is playing " << std::endl;
        }
};

int main()
{
    instrument *i1 = new piano;
    i1->sound();
    return 0;
}