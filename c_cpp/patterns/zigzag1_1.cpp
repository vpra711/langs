#include <iostream>

int main()
{
    int zigZag = 0;
    std::cin >> zigZag;
    int col = 1, temp = 0;
    int ans = 0;
    int count = 1;
    int i = 0;

    for(i = 1; i <= zigZag; i++)
    {
        col = col + i - 1;
        temp = col;
        std::cout << col << "\t";
        count = 1;
        int j = 0;
        
        for(j = 2; j <= zigZag; j++)
        {        
            temp = temp + i + j - 1;

            if(i + j - 1 > zigZag)
            { 
                temp = temp - count;
                count = count + 2;
            }
            std::cout << temp << "\t";
        }
        std::cout << std::endl;
    }
    
    return 0;
}