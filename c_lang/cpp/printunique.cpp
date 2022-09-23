// eliminate duplicates 
// "geeks", "geek", "ab", "geek", "code", "karega"

#include <iostream>
#include <vector>

int main()
{
    int n, i, j;
    bool found;

    std::cin >> n;
    std::vector<std::string> vec;
    std::string temp;

    for(i = 0; i < n; i++)
    {
        std::cin >> temp;
        vec.push_back(temp);
    }

    for(i = 0; i < n; i++)
    {
        found = false;

        for(j = 0; j < n; j++)
        {
            if(i == j)
            {
                continue;
            }

            if(vec[i] == vec[j])
            {
                found  = true;
                break;
            }
        }

        if(!found)
        {
            std::cout << vec[i] << "\t";
        }
    }
    
    return 0;
}