using System;
using System.Collections.Generic;

var names = new List<int>();

names.Add(10);
names.Add(1);
names.Add(2);
names.Add(6);
names.Sort();
foreach(var id in names)
{
    Console.WriteLine(id);
}
