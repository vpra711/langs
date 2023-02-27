#include <iostream>
#include <vector>

int main()
{
    int n, s, temp;

    std::cin >> n >> s;

    std::vector<int> vec;

    for(int i = 0; i < n; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
    }

    for(int i = 0; i < n; i++)
    {
        temp = 0;
        
        for(int j = i; j < n; j++)
        {
            temp += vec[j];

            if(temp == s)
            {
                std::cout << i + 1 << " " << j + 1;
                return 0;
            }
        }
    }

    return 0;
}