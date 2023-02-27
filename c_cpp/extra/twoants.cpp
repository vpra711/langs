#include <iostream>

#define ROW 5
#define COL 5

int grid[ROW][COL];

class ant
{
    public:
        std::string id;
        int direction;
        int currPosRow;
        int currPosCol;

    ant(std::string id, int direction, int currPosRow, int currPosCol)
    {
        this->id = id;
        this->direction = direction;
        this->currPosRow = currPosRow;
        this->currPosCol = currPosCol;
    }

    void changeDirection()
    {
        if(grid[currPosRow][currPosCol] == 0)
        {
            grid[currPosRow][currPosCol] = 1;
            direction++;

            if(direction >= 4)
            {
                direction = 0;
            }
        }
        else
        {
            grid[currPosRow][currPosCol] = 0;
            direction--;

            if(direction <= 0)
            {
                direction = 3;
            }
        }
    }

    void move()
    {
        switch(direction)
        {
            case 0: currPosCol--; break;
            case 1: currPosRow--; break;
            case 2: currPosCol++; break;
            case 3: currPosRow++;
        }
    }

    bool checkCurrPos(int i, int j)
    {
        if(currPosRow == i && currPosCol == j)
        {
            return true;
        }

        return false;
    }
};

void printMatrix(ant a1, ant a2);

int main()
{

    ant a1 = ant("a1", 0, 2, 2);
    ant a2 = ant("a2", 0, 2, 2);
    int i = 0;

    for(i = 0; i < 8; i++)
    {
        printMatrix(a1, a2);
        a1.changeDirection();
        a1.move();
        a2.changeDirection();
        a2.move();
    }


    return 0;
}

void printMatrix(ant a1, ant a2)
{
    system("sleep 0.5");
    system("clear");
    std::cout << std::endl;

    int i = 0, j = 0;

    for(i = 0; i < ROW; i++)
    {
        for(j = 0; j < COL; j++)
        {
            if(a1.checkCurrPos(i, j))
            {
                std::cout << a1.id << "\t";
            }
            else if(a2.checkCurrPos(i, j))
            {
                std::cout << a2.id << "\t";
            }
            else
            {
                std::cout << grid[i][j] << "\t";
            }
        }

        std::cout << std::endl;
    }
}