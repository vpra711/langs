#include <iostream>

int main()
{
    std::string input = "abcefs";
    std::string find = "def";
    int result = -1;
    int inputLen = input.length();
    int findLen = find.length();
    bool matchFound = false;
    int i = 0, j = 0, k = 0;

    for(i = inputLen - 1; i > -1; i--)
    {
        j = findLen - 1;

        if(input[i] == find[j])
        {
            k = i-1;
            result = i;

            for(j = j - 1; j > -1; j--)
            {
                if(input[k--] == find[j])
                {
                    matchFound = true;
                }
                else
                {
                    matchFound = false;
                    break;
                }
            }
                                
            if(matchFound)
                break;
            else
                result = -1;
        }   
    }

    std::cout << result;
    return 0;
}