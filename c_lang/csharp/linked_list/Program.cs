using System;
using System.Collections.Generic;

class linked_list
{
    static void Main()
    {
        String name;
        LinkedList<string> ll = new LinkedList<string>();
        ll.AddFirst("heelo");
        ll.AddLast("heeelo");
        ll.AddAfter(ll.Find("heelo"), "value");
        
        foreach (var item in ll)
        {
            Console.WriteLine(item);
        }

    }
}