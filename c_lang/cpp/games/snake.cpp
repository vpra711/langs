#include <iostream>
#include <thread>
#include <Windows.h>

#define setCurPos(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD(x, y))

const int groundHeight = 30;
const int groundWidth = 20;
char ground[groundHeight][groundWidth];

class Food
{
    int x, y;

    public:
        void generateFood(Snake s)
        {
            x = rand() % groundHeight;
            y = rand() % groundWidth;

            if(ground[x][y] != ' ')
            {
                generateFood(s);
            }
        }
};

enum Direction
{
    UP = 'w', LEFT = 'a', DOWN = 's', RIGHT = 'd'
};

using position = struct coordinate;
struct coordinate
{
    int x, y;
};

class Snake
{
    
    Direction currentDirection;
    int score, length;
    position body[groundHeight * groundWidth];

    public:
        void move()
        {
            switch(currentDirection)
            {
                case UP: body[0].x--; break;
                case LEFT: body[0].y--; break;
                case DOWN: body[0].y++; break;
                case RIGHT: body[0].x++; break;
            }

            
        }

        bool ifFood()
        {
            if(foodX == headX && foodY == headY)
            {
                foodX = foodY = 0;
                score++;
                return true;
            }

            return false;
        }
};

int main()
{
    int i = 0;
    system("clear");
    for(i = 0; i < 100; i++)
    {
        std::cout << "Heelo a" << std::endl;

        if(i % 5 == 0)
        {
            
            setCurPos(i, 0);
            SetPhysicalCursorPos(i, 0);
        }
    }
    return 0;
}

void updateScreen()
{
    
}