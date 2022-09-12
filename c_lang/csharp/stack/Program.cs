using System;
using System.Collections;
class Program
{
    static void Main(String[] args)
    {
        Stack s = new Stack();
        s.Push(1);
        s.Push("Hello");
        foreach (var item in s)
        {
            Console.WriteLine(item);
        }
    }
}