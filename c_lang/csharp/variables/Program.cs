using System;

namespace variables
{
    class Program
    {
        static void Main(int[] args)
        {
            char letter = 'A';
            char digit = '1';
            String firstName = "Bob";
            String lastName = "Smith";
            String filePath = @"C:\users"; // Verbatim string
            String interpolatedString = $"asdf{letter}";
            /*String three types
            literal string - normal string
            verbatim string - prefixed with @ to eliminate escape sequence
            Interpolated string - prefixed with $ for formatted variables */
            uint myNumber = 12;
            int myNUmber1 = -12;
            float floatingPoint = 2.3f;
            int decimalNotation = 2_000_000;
            int hexNotation = 0X_001E_8480;
            int binaryNotation = 0b_0001_1110_1000_0100_1000_0000;
            Console.WriteLine(binaryNotation);
            Console.WriteLine(firstName, lastName, filePath, myNumber, myNUmber1, floatingPoint, decimalNotation, hexNotation);
            digit = '1';
            Console.WriteLine(digit);
        }
    }
}