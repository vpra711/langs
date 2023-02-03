#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m = 0, n = 0;
    printf("\nEnter the m and n: ");
    scanf("%d%d", &m, &n);
    int **mn = (int**) malloc(sizeof(int*) * m);
    int i = 0, j = 0;

    for(i = 0; i < n; i++)
    {
        *(mn + i) = (int*) malloc(sizeof(int) * n);
    }

    for(i = 0; i < m; i++)
    {
        for(j = 0; j < n; j++)
        {
            *(*(mn + i) + j) = i;
            printf("%d", *(*(mn + i) + j));
        }
    }

    return 0;
}