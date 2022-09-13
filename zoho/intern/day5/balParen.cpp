#include <iostream>
#include <stack>
#include <list>
int count;
bool isBalanced(std::string);
void genParenthesis(std::string, int);
int inputLength;
std::list<std::string> validList;

int main()
{
    int input = 4;
    inputLength = input + input;
    genParenthesis("", inputLength);
    std::cout << count << std::endl;

    for(std::string i : validList)
    {
        std::cout << i << std::endl;
    }

    return 0;
}

bool isBalanced(std::string input)
{
    if(input[0] != ')')
    {
        std::stack <char> parenthesis;
        int inputLength = input.length();
        int i = 0;

        while(i < inputLength)
        {
            if(input[i] == '(')
            {
                parenthesis.push(input[i]);
            }
            else
            {
                if(!parenthesis.empty())
                    parenthesis.pop();
                else
                    return false;
            }

            i++;
        }

        if(parenthesis.empty())
        {
            return true;
        }

    }

    return false;
}

void genParenthesis(std::string st, int len)
{
    if(st.length() == inputLength)
    {
        count++;
        if(isBalanced(st))
        {
            validList.push_back(st);
        }
        
        return ;
    }

    if(len <= 0)
    {
        return ;
    }

    genParenthesis(st + "(", len-1);
    genParenthesis(st + ")", len-1);
}