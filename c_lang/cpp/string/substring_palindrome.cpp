#include <iostream>
#include <string>
#include <set>

int main()
{
    int stringLength {0}, setLength {0}, count {0}, subStringPalindrome {0};
    std::set<int> numberSet;
    std::string str, subStringStr, tempStr;
    std::cout << "String length : ";
    std::cin >> stringLength;
    std::cout << "Enter the string : ";
    std::cin >> str;
    std::cout << "Set Length : ";
    std::cin >> setLength;
    std::cout << "Enter the elements (set) : ";

    for (int i = 0; i < setLength; i++)
    {
        std::cin >> count;
        numberSet.insert(count);
    }

    for(int i = 0; i < stringLength-1; i++)
    {
        for(int j = 2; j <= stringLength-i; j++)
        {
            subStringStr = str.substr(i, j);
            tempStr = std::string(subStringStr.rbegin(), subStringStr.rend());

            if(subStringStr.compare(tempStr) == 0)
            {
                count = subStringStr.length();
                
                for (int item : numberSet)
                {
                    if (item == count)
                    {
                        subStringPalindrome++;
                        break;
                    }
                }
            }
        }
    }

    count = 1;
    for (int item : numberSet)
    {
        if(item == count)
        {
            subStringPalindrome += stringLength;
            break;
        }
    }

    std::cout << subStringPalindrome;
    return 0;
}