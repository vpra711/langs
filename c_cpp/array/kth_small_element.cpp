/*

in a given array find the kth smallest element

input: {23, 4, 7, 1, 2, 5, 6, 25, 67, 43, 10}
8

output: 23

*/

#include <iostream>
#include <vector>
#define MAX 11

int arr[MAX] = {23, 4, 7, 1, 2, 5, 6, 25, 67, 43, 10}, i;
std::vector<int> vec;

int findElement(int);

int main()
{
    int k = 8;

    for(i = 0; i < k; i++)
    {
        vec.push_back(arr[0]);
    }

    k--;

    for(i = 0; i < MAX; i++)
    {
        findElement(k);
    }

    std::cout << vec[k] << std::endl;

    return 0;
}

int findElement(int k)
{
    int value, temp;

    if(vec[k] > arr[i] && k > -1)
    {
        value = findElement(k-1);
        temp = vec[k];

        if(value)
        {
            vec[k] = value;
        }
        else
        {
            vec[k] = arr[i];
        }

        return temp;
    }
    else
    {
        return 0;
    }
}