using System;

class substringpalindrome
{
    static void Main(string[] args)
    {
        Console.WriteLine("Enter the string : ");
        string s = Console.ReadLine(), ts = null;
        int sl = s.Length, count = 0;
        Console.WriteLine("The substrings are : ");

        for (int i = 0; i < sl - 1; i++)
            for(int j = 2; j <= sl - i; j++)
            {
                ts = s.Substring(i, j);
                if(ts == new string(ts.Reverse().ToArray()))
                {
                    Console.WriteLine(ts);
                    count++;
                }
            }

        Console.WriteLine("No of palindrome : {0}", (count));
    }
}