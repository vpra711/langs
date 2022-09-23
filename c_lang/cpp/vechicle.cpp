#include <iostream>

int main()
{
    int totalVechicles = 0, twoWheelers = 0, fourWheelers = 0, wheels = 0;

    std::cout << "Enter the no of vechicles (two wheelers + four wheelers): ";
    std::cin >> totalVechicles;

    std::cout << "Enter the total no of wheels (two wheelers + four wheelers): ";
    std::cin >> wheels;
    
    fourWheelers = (wheels - (totalVechicles * 2)) / 2;
    twoWheelers = (wheels - fourWheelers * 4) / 2;

    std::cout << "Two wheelers: " << twoWheelers << std::endl;
    std::cout << "Four wheelers: "<< fourWheelers << std::endl;

    return 0;
}