using System;
using System.Collections.Generic;

class queue
{
    static void Main()
    {
        Queue<int> q = new Queue<int>();
        q.Enqueue(1);
        q.Enqueue(2);
        q.Enqueue(3);
        q.Enqueue(4);

        foreach (var item in q)
        {
            Console.WriteLine(item);
        }
    }
}