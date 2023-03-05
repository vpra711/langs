#include <iostream>

int main()
{

    std::string postfix;
    std::cin >> postfix;

    int len = postfix.length();
    int half = len / 2;

    int i = 0, result = postfix[0] - 48;

    char oprter, oprand;

    for(i = 1; i <= half; i++)
    {
        oprand = postfix[i] - 48;
        oprter = i + half;

        switch (postfix[oprter])
        {
            case '+': result += oprand; break;
            case '-': result -= oprand; break;
            case '*': result *= oprand; break;
            case '/': result /= oprand; break;
        }
    }

    std::cout << result;

    return 0;
}