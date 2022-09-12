#include <iostream>
#include <fstream>

int main()
{
    std::string str {};
    std::ifstream file("data.txt", std::ios::in); // file is the variable name

    if(!file)
        std::cout << "Cannot open the file" << std::endl;
    else
    {
        file >> str; // stroing all data into str from data.txt
        if("heelo" == str)
            std::cout << "The two strings are same" << std::endl;
    }
    return 0;
}