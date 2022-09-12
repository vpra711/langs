using System;

namespace program
{
    public static class program
    {
        public static void Main(String[] args)
        {
            int a = int.MaxValue;
            int b = int.MinValue;
            int intsize = sizeof(int);
            float fa = float.MaxValue;
            float fb = float.MinValue;
            int floatsize = sizeof(float);
            char ca = char.MaxValue;
            char cb = char.MinValue;
            int charsize = sizeof(char);
            double da = double.MaxValue;
            double db = double.MinValue;
            int doublesize = sizeof(double);
            decimal dea = decimal.MaxValue;
            decimal deb = decimal.MinValue;
            int decimalsize = sizeof(decimal);
            long lia = long.MaxValue;
            long lib = long.MinValue;
            int longsize = sizeof(long);
            Console.WriteLine($"short max: {short.MaxValue} min: {short.MinValue} size: {sizeof(short)}");
            Console.WriteLine($"int max: {a} min: {b} size: {intsize}");
            Console.WriteLine($"float max: {fa} min: {fb} size: {floatsize}");
            Console.WriteLine($"char max: {(int)ca} min: {(int)cb} size: {charsize}");
            Console.WriteLine($"double max: {da} min: {db} size: {doublesize}");
            Console.WriteLine($"decimal max: {dea} min: {deb} size: {decimalsize}");
            Console.WriteLine($"long max: {lia} min: {lib} size: {longsize}");

            double aa = 1.0;
            double ab = 3.0;
            Console.WriteLine(aa / ab);

            decimal ac = 1.0M;
            decimal ad = 3.0M;
            Console.WriteLine(ac / ad);
        }
    }
}