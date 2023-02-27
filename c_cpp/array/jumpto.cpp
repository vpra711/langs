/*
minimum number of jumps
Given an array arr[] where each element represents the max number of steps that can be made forward from that index. 
find the minimum number of jumps to reach the end of the array. If the end isn’t reachable, return -1.

Input:
N = 11 
arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9} 

Output: 
3 

*/

#include <iostream>

void noofjumps(int, int);

int arr[] = {2, 3, 1, 1, 2, 4, 2, 0, 1, 1};
int min = INT_MAX;
int arrSize = sizeof(arr) / sizeof(int) - 1;

int main()
{
    noofjumps(0, 0);

    if(min == INT_MAX)
    {
        std::cout << -1;
    }
    else
    {
        std::cout << min;
    }

    return 0;
}

void noofjumps(int n, int sum)
{
    int i;
    
    if(sum < min)
    {

        if(n == arrSize)
        {
            min = sum;
            return ;
        }
    }
    else
    {
        return ;
    }

    for(i = 1; i <= arr[n]; i++)
    {
        noofjumps(n + i, sum + 1);
    }
}