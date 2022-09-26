#include <iostream>

int main()
{
    int expLength = 0, noLength = 0, total = 0, i = 0, value = 0;
    char operater = ' ';
    std::string postfixExp = " ";
    std::cin >> postfixExp;
    expLength = postfixExp.length();
    noLength = (expLength / 2) + 1;
    total = postfixExp[0] - 48;

    for(i = 0; i < noLength; i++)
    {
        value = postfixExp[i+1] - 48;
        operater = postfixExp[noLength+i];

        switch (operater)
        {
            case '+': total += value; break;
            case '-': total -= value; break;
            case '*': total *= value; break;
            case '/': total /= value; break;
        }
    }

    std::cout << "Result: " << total << std::endl;
    return 0;
}