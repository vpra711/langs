#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::fstream file1;
    file1.open("temp.txt", std::ios::out); // permission for write

    if(file1.is_open())
    {
        file1 << " Hello world ";
        file1.close();
    }

    file1.open("temp.txt", std::ios::in); // permission for read

    if(file1.is_open())
    {
        std::string name;
        while(getline(file1, name))
            std::cout << name << std::endl;
        file1.close();
    }
    
    return 0;
}