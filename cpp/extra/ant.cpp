#include <iostream>

#define ROW 3
#define COL 3

int matrix[ROW][COL];
int antDirection = 0;
int curPosition1 = 1, curPosition2 = 1;

void moveUp();
void rotateLeft();
void rotateRight();
void printMatrix();

int main()
{
    int i = 0, j = 0;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            matrix[i][j] = 1;
        }
    }

    for(i = 0; i < 8; i++)
    {
    
        if(matrix[curPosition1][curPosition2] == 1)
        { 
            matrix[curPosition1][curPosition2] = 0;
            rotateRight();
            moveUp();
        }
        else
        {
            matrix[curPosition1][curPosition2] = 1;
            rotateLeft();
            moveUp();
        }

        printMatrix();
    }

    return 0;
}

void moveUp()
{
    switch(antDirection)
    {
        case 0: curPosition2--; break;
        case 1: curPosition1--; break;
        case 2: curPosition2++; break;
        case 3: curPosition1++; break;
    }
}

void rotateLeft()
{
    antDirection--;

    if(antDirection <= -1)
        antDirection = 3;
}

void rotateRight()
{
    antDirection++;

    if(antDirection >= 4)
        antDirection = 0;
}

void printMatrix()
{
    system("sleep 1");
    system("clear");

    int i = 0, j = 0;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            if((i == curPosition1) && (j == curPosition2))
            {
                std::cout << "x" << " ";
            }
            else
            {
                std::cout << matrix[i][j] << " ";
            }
        }

        std::cout << std::endl;
    }
}