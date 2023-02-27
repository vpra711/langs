/*
sort array according to other 

Given two arrays a1[] and a2[] of size N and M respectively
sort the first array a1[] such that all the relative positions 
of the elements in the first array are the same as the elements in the 
second array a2[].
Note : if elements are repeated in the second array,consider
their first occurance only

N = 11 M = 4 
A1[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8} 
A2[] = {2, 1, 8, 3} 
Output: 2 2 1 1 8 8 3 5 6 7 9 

*/

#include <iostream>
#include <map>

int main()
{

    int arr[] = {2, 1, 2, 5, 7, 1, 9, 3, 6, 8, 8};
    int arr2[] = {2, 1, 8, 3};
    int arrLen = sizeof(arr)/sizeof(int), arr2Len = sizeof(arr2)/sizeof(int);
    std::map<int, int> mp;

    int i, j;

    for(i = 0; i < arrLen; i++)
    {
        mp[arr[i]]++;
    }

    for(i = 0; i < arr2Len; i++)
    {
        while(mp[arr2[i]]-- > 0)
        {
            std::cout << arr2;
        }
    }

    for(auto i : mp)
    {
        if(i.second != 0)
        {
        
        }
    }
    

    return 0;
}