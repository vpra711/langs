/*

The string str consists of binary digits separated with an alphabet as follows:

– A denotes AND operation
– B denotes OR operation
– C denotes XOR Operation

calculate the result of the string str, scanning the string to right taking one opearation at a time, and return the same.

str: 1C0C1C1A0B1

Output:

1

*/

#include <iostream>

int main()
{
    std::string exp = "0C1A1B1C1C1B0A0";
    int result = exp[0] - 48, expLen = exp.length(), i;
    char c;

    for(i = 1; i < expLen; i += 2)
    {
        c = exp[i + 1] - 48;

        switch (exp[i])
        {
            case 'A': result &= c; break;
            case 'B': result |= c; break;
            case 'C': result ^= c;
        }
    }

    std::cout << result;

    return 0;
}