#include <iostream>
#include <memory>

int main()
{
    std::weak_ptr<int> wptr ;

        std::shared_ptr<int> sptr = std::make_shared<int> (56);
        wptr = sptr; 
        //weak pointer does not hold the pointer like unique and shared its only for referencing
    std::cout << sptr << std::endl;
    return 0;
}