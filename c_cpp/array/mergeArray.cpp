#include <iostream>

int main()
{
    int input1[] = {6, 11, 11, 11, 14}, input2[] = {1, 7, 8};
    int input1Size = sizeof(input1) / sizeof(int);
    int input2Size = sizeof(input2) / sizeof(int);
    int sumOfArrayLength = input1Size + input2Size;
    int *result = new int[sumOfArrayLength];
    int i = 0, j = 0, k = 0, element = 0;

    for(i = 0; i < sumOfArrayLength; i++)
        result[i] = 0;
        
    i = 0, j = 0;

    while((i < input1Size) || (j < input2Size))
    {
        if(j >= input2Size)
        {
            element = input1[i];
            i++;
        }
        else if(i >= input1Size)
        {
            element = input2[j];
            j++;
        }
        else
        {
            if(input1[i] < input2[j])
            {
                element = input1[i];
                i++;
            }
            else if(input2[j] < input1[i])
            {
                element = input2[j];
                j++;
            }
        }

        if(k > 0)
            if(element == result[k-1])
                continue;

        result[k] = element;
        k++;
    }

    for(i = 0; i < sumOfArrayLength; i++)
        std::cout << result[i] << "\t";

    return 0;
}