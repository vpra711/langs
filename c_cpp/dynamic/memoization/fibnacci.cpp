#include <iostream>
#include <unordered_map>

long long fibnacci(long long);

std::unordered_map<long long, long long> memory;

int main()
{
    std::cout << fibnacci(50) << "\n";
    return 0;
}

long long fibnacci(long long n)
{
    if(memory.contains(n))
    {
        return memory[n];
    }

    if(n <= 2)
    {
        return 1;
    }
    
    memory[n] = fibnacci(n-1) + fibnacci(n-2);
    return memory[n];
}