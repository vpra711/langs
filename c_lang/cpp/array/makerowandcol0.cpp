#include <iostream>

void makeZero(int, int);

const int r = 3, c = 3;
int arr[r][c] = {0, 1, 1, 1, 1, 1, 1, 1, 0};
int col[c] = {0, 1, 2};

int main()
{
    int i, j;

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            if(col[j] != -1 && arr[i][j] == 0)
            {
                col[j] = -1;
                makeZero(i, j);
                break;
            }
        }
    }

    for(i = 0; i < r; i++)
    {
        for(j = 0; j < c; j++)
        {
            std::cout << arr[i][j];
        }

        std::cout << std::endl;
    }

    return 0;
}

void makeZero(int i, int j)
{
    int k;

    for(k = 0; k < c; k++)
    {
        arr[i][k] = 0;
    }

    for(k = 0; k < r; k++)
    {
        arr[k][j] = 0;
    }
}