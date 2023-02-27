/*

you are given array.you need to print no-repeated elements

Input: n = 10 arr[] = {1,1,2,2,3,3,4,5,6,7}
Output: 4 5 6 7 
Explanation: 4, 5, 6 and 7 are the only elements which is having only 1 frequency and hence, Non-repeating.

*/

#include <iostream>
#include <unordered_map>
#define MAX 10

void print(std::unordered_map<int, int>);

int main()
{
    int arr[] = {1, 1, 2, 2, 3, 3, 4, 5, 6, 7}, i;

    std::unordered_map<int, int> mp;

    for(i = 0; i < MAX; i++)
    {
        mp[arr[i]]++;
    }

    mp.reserve(mp.size());

    for(auto it : mp)
    {
        if(it.second == 1)
        {
            std::cout << it.first;
        }
    }

    return 0;
}