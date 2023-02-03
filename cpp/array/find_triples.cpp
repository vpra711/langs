/*

given an array[] of distinct integers of size N and a value sum,the task is to find the count of triplets (i,j,k) having (i<j<k) with sum of (arr[i]+arr[j]+arr[k]) smaller than  the given value sum                                                                                                                                                                             example 1
Input: N = 4, sum = 2
arr[] = {-2, 0, 1, 3}
Output:  2
Explanation: Below are triplets with 
sum less than 2 (-2, 0, 1) and (-2, 0, 3). 

*/

#include <iostream>

int main()
{
    int arr[] = {-2, 0, 1, 3};
    int size = sizeof(arr) / sizeof(int);
    int input = 2, sum = 0, temp = 0, i = 0, j = 0;

    for(i = 0; i < size; i++)
    {
        sum = arr[i];
        temp = arr[i + 1];

        for(j = i + 2; j < size; j++)
        {
        
            if(arr[j] < temp)
            {
                if(sum + arr[j] < input)
                {
                    sum += arr[j];
                    temp = arr[j];
                } 
            }
        }
    }

    return 0;
}