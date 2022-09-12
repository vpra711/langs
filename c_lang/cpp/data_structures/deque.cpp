#include <iostream>
#include <deque>

int main()
{
    std::deque<int> dq1;
    dq1.push_front(1);
    dq1.push_back(2);

    for(int i : dq1)
        std::cout << i << "\t";
}  