#include <iostream>

int main()
{
    int arr[] = {7, 11, 14, 9, 3, 2, 9};
    int arraySize = sizeof(arr) / sizeof(int);
    int indexArray[] = {0, 1, 2, 3, 4, 5, 6, 7};

    int i = 0, j = 0, temp = 0;

    for(i = 0; i < arraySize; i++)
    {
        for(j = 0; j < arraySize - 1-i; j++)
        {
            if(arr[j] > arr[j+1])
            {
                temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp; 

                temp = indexArray[j+1];
                indexArray[j+1] = indexArray[j];
                indexArray[j] = temp;
            }
        }
    } 

    for(i = 0; i < arraySize; i++)
    {
        std::cout << indexArray[i];
    }

    return 0;
}