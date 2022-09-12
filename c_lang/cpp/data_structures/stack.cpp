#include <iostream>
#include <stack>

int main()
{
    std::stack<int> s1;
    s1.push(1);
    s1.push(2);

    while(!s1.empty())
    {
        std::cout << s1.top();
        s1.pop();
    }
}