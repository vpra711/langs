/* find 4 elements which adds to input x
*/

#include <iostream>
#include <vector>

int main()
{
    int n, i, j, temp;

    std::cin >> n;

    std::vector<int> vec;

    for(i = 0; i < n; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
    }

    
    
    return 0;
}