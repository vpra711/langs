#include <iostream>
#include <set>

void genParenthesis(std::string parenthesis, int len);

std::set<std::string> validParenthesis;
int totalLength;

int main()
{
    int input = 5;
    totalLength = input + input;
    std::string initPanrenthesis = "()";

    genParenthesis(initPanrenthesis, totalLength);

    for(std::string i : validParenthesis)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

void genParenthesis(std::string parenthesis, int len)
{
    if(parenthesis.length() == totalLength)
    {
        validParenthesis.insert(parenthesis);
        return ;
    }

    if(len <= 0)
    {
        return ;
    }

    genParenthesis("()" + parenthesis, len - 2);
    genParenthesis("(" + parenthesis + ")", len - 2);
    genParenthesis(parenthesis + "()", len - 2);
}