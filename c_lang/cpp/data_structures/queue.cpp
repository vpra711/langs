#include <iostream>
#include <queue>

int main()
{
    std::queue<int> q1;
    q1.push(1);
    q1.push(2);

    while(!q1.empty())
    {
        std::cout << q1.front();
        q1.pop();
    }
}