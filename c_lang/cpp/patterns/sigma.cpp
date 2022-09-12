#include <iostream>

using namespace std;

int main()
{
    int i, j;
    for(i = 0; i < 10; i++)
    {
        for(j = 0; j < 10; j++)
        {
            if( i == 0 || i == 9)
            {
                cout << "- " ;
            }
            else
            {
                if(i < 5)
                {
                    if( j == 10 - i)
                        cout << "/" ; 
                    else
                        cout << "  ";
                }
                else
                {
                    if( 1 + i == j )
                        cout << "\\"  ;
                    else
                        cout << "  ";
                }
            }
        }
        cout << endl;
    }
}