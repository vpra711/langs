#include <iostream>

int checkBal(int [], int, int);

int main()
{
    //int input[] = {1, 0, 1, 1, 0, 1, 1, 0};
    int input[] = {1, 0, 1, 1, 1, 1};
    int inputLength = sizeof(input) / sizeof(int);

    int i = 0, j = 0, k = 0, max = 0, count = 0;

    for(i = 0; i < inputLength-1; i++)
    {
        k = 1;
        for(j = k; j < inputLength; j += k)
        {
            count = checkBal(input, i, j);
            if(max < count)
            {
                max = count;
            }
        }
        k += 2;
    }

    std::cout << max;
    return 0;
}

int checkBal(int input[], int startIndex, int endIndex)
{
    int i = 0, j = 0;
    int zero = 0, one = 0;

    for(i = startIndex; i <= endIndex; i++)
    {
        if(input[i] == 0)
            zero++;
        else
            one++;
    }

    int total = zero + one;

    if(zero == one)
        return total;
    else
        return 0;
}