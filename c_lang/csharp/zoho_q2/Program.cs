using System;

int i = 0, j = 0, k = -1, n = 5;

for(i = 1; i <= n*n; i++)
{
    j = ((i+k) % n) + 1;
    Console.Write(j);

    if(i % n == 0)
    {
        Console.WriteLine();
        k++;
    }
}