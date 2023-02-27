#include <iostream>
using namespace std;

int main()
{
    std::string input = "eabeabjab";
    std::string str = "abiabel";

    int i = 0, j = 0;
    int inputLength = input.length();
    int strLength = str.length();
    bool matchFound = false;
    int index = -1;

    while(i < inputLength)
    {
        j = 0;
        if(input[i] == str[j])
        {
            index = i;
            for(j = 1; j < strLength; j++)
            {
                int indexNumber = (i + j) % inputLength;
                if(input[indexNumber] == str[j])
                    matchFound = true;
                else
                    matchFound = false;
            }

            if(!matchFound)
                index = -1;
            else
                break;
        }
        else
        {
            index = -1;
        }
        i++;
    }

    std::cout << index << std::endl;

    return 0;
}