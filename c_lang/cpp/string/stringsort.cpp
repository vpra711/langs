#include <iostream>
#include <array>
#define N 7

int main()
{
    std::array<std::string, N> strNoArray = {"1", "17", "12", "32", "0", "4", "25"};
    std::string temp = " ";
    int i = 0, j = 0;

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(strNoArray[j] > strNoArray[j+1])
            {
                temp = strNoArray[j];
                strNoArray[j] = strNoArray[j+1]; 
                strNoArray[j+1] = temp;
            }
        }
    }

    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(strNoArray[j].length() > strNoArray[j+1].length())
            {
                temp = strNoArray[j];
                strNoArray[j] = strNoArray[j+1]; 
                strNoArray[j+1] = temp;
            }
        }
    }

    for(std::string i : strNoArray)
        std::cout << i << std::endl;

    return 0;
}