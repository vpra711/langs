#include <iostream>

int main()
{
    std::string post = "12345+-+-";
    int totalLength = post.length() / 2 + 1;
    int temp = post[0] - 48;

    int i = 0;

    for(i = 1; i <= totalLength; i++)
    {
        char op = post[i + totalLength - 1];
        int data = post[i] - 48;
        
        switch(op)
        {
            case '+': temp += data; break;
            case '-': temp -= data; break;
            case '*': temp *= data; break;
            case '/': temp /= data;
        }
    }

    std::cout << "The result : " << temp;
    return 0;
}