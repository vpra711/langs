/*

find all pairs in the array that sum to a number K.if no such pair exits then output will be -1.the elements of the array distinct and sorted order.
Note :(a,b) and (b,a) are considered same .also, an element cannot pair with itself.i.e,(a,a) is invalid 

Input:
n = 7
arr[] = {1, 2, 3, 4, 5, 6, 7}
K = 8
Output:
3
Explanation:
We find 3 such pairs that
sum to 8 (1,7) (2,6) (3,5)

*/

#include <iostream>
#include <unordered_set>

int main()
{
    std::unordered_set<int> st;
    
    int arr[] = {1, 2, 3, 4, 5, 6, 7}, input = 8, i = 0, count = -1;
    int size = sizeof(arr) / sizeof(int);

    for(i = 0; i < size; i++)
    {
        st.insert(arr[i]);
    }

    for(i = 0; i < size; i++)
    {
        if(st.contains(input - arr[i]) && input - arr[i] != arr[i])
        {
            count++;
        }
        
        st.erase(arr[i]);
    }

    if(count != -1)
    {
        std::cout << ++count;
    }
    else
    {
        std::cout << count;
    }
}