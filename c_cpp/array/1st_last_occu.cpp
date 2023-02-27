#include <iostream>
#include <array>

int main()
{
    std::array<int, 9> arr = { 1, 3, 5, 5, 5, 5, 67, 123, 125 }; 
    int n = 5;
    int start = 0, mid = 0, end = 8;
    int firstOccurence = -1, lastOccurence = -1;

    while(start <= end)
    {
        mid = start + (end - start) / 2;

        if(arr[mid] == n)
        {
            firstOccurence = mid;
            end = mid - 1;
        }
        else if(arr[mid] < n)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    start = 0, mid = 0, end = 8;

    while(start <= end)
    {
        mid = start + (end - start) / 2;

        if(arr[mid] == n)
        {
            lastOccurence = mid;
            start = mid + 1;
        }
        else if(arr[mid] < n)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }

    std::cout << firstOccurence << " " << lastOccurence << std::endl;

    return 0;
}