#include<iostream>

void comparestring(std::string str);

int count;

int main()
{
    int i, j, stringlength;
    std::string str;
    std::cout << "Enter the String : ";
    std::cin >> str;
    stringlength = str.length();

    for(i = 0; i < stringlength-1; i++)
        for(j = 2; j <= stringlength-i; j++)
            comparestring(str.substr(i,j));

    std::cout << "No of palindrome in " << str << " is : " << count << std::endl;
    return 0;
}

void comparestring(std::string str)
{
    std::string str1 = str;
    reverse(str1.begin(), str1.end());
    if( str.compare(str1) == 0 )
    {
        std::cout << str << std::endl;
        count++;
    }
}