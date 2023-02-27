#include <iostream>
#include <memory>

int main()
{
    std::unique_ptr<int> uniptr = std::make_unique<int> (56);//allocating the address of 56 to uniptr
    std::cout << uniptr << std::endl;

    std::unique_ptr<int> uniptr1 = move(uniptr); //moving the address to another pointer called uniptr1
    // uniptr automatically deallocated to NULL.

    return 0;
}