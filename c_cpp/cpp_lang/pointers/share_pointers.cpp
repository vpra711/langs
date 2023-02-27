#include <iostream>
#include <memory>

int main()
{
    std::shared_ptr<int> shptr1 = std::make_shared<int> (56);
    std::cout << "Shared pointer : " << shptr1.use_count() << std::endl;

    std::shared_ptr<int> shptr2 = shptr1;
    std::cout << "Shared pointer : " << shptr2.use_count() << std::endl;

    std::cout << "Value : " << *shptr1 << std::endl; 
    return 0;
}