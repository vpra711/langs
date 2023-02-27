/*

find four element which sum upto the given input

input :
(array) {10, 2, 3, 4, 5, 9, 7, 8}
(int) 23

output:
3 5 7 8

*/

#include <iostream>

int main()
{

    int arr[8] = {10, 2, 3, 4, 5, 9, 7, 8}, x = 23;

    int i, j, k, l;

    for(i = 0; i < 8; i++)
    {
        for(j = i + 1; j < 8; j++)
        {
            for(k = j + 1; k < 8; k++)
            {
                for(l = k + 1; l < 8; l++)
                {
                    if(arr[i] + arr[j] + arr[k] + arr[l] == x)
                    {
                        std::cout << arr[i] << arr[j] << arr[k] << arr[l] << std::endl;
                    }
                }
            }
        }
    }

    return 0;
}