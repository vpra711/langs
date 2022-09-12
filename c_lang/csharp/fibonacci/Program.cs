using System;
using System.Collections.Generic;

var fibonnaci = new List<int>{0, 1};

int i = 0, j = 0, k = 0;

for(i = 2; i < 22; i++)
{
    j = fibonnaci[fibonnaci.Count-1];
    k = fibonnaci[fibonnaci.Count-2];
    fibonnaci.Add(j + k);
}

foreach(int z in fibonnaci)
{
    Console.WriteLine(z);
}

