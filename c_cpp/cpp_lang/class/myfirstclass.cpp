#include <iostream>

class Computer
{
    struct cpu
    {
        std::string _name;
        float _speed;
        int _architecture;
        int _l1Cache, _l2Cache, _l3Cache;
        int _coreCount;
        int _theardCount;

    };

    cpu s1;

    public:
    
        void setinfocpu(std::string name, float speed, int others[])
        {
            s1._name = name;
            s1._speed = speed;
            s1._architecture = others[0];
            s1._l1Cache = others[1];
            s1._l2Cache = others[2];
            s1._l3Cache = others[3];
            s1._coreCount = others[4];
            s1._theardCount = s1._coreCount * 2;
        }

        void getinfocpu()
        {
            std::cout << "Name of the cpu is " << s1._name << std::endl;
            std::cout << "Which runs at " << s1._speed << " GHz "<< std::endl;
            std::cout << "and the architecture is " << s1._architecture << " bit "<< std::endl;
            std::cout << "has this amount of " << s1._l1Cache << " MB L1 cache, ";
            std::cout << s1._l2Cache << " MB L2 cache, ";
            std::cout << s1._l3Cache << " MB L3 cache "<< std::endl;
            std::cout <<"And has a core count of " << s1._coreCount;
            std::cout <<" with hyper therading support.The theard cout is " << s1._theardCount << std::endl;
        }
        
};

int main()
{
    Computer computer;
    int more[5] = {64, 64, 128, 512, 16};
    computer.setinfocpu("intel core i9 12900k", 5.00, more);
    computer.getinfocpu();

    return 0;
}