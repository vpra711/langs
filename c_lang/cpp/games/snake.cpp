#include <iostream>
#include <thread>
#include <Windows.h>

#define setCurPos(x, y) SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), COORD(x, y))

const int groundHeight = 30;
const int groundWidth = 20;
char ground[groundHeight][groundWidth];

class Food
{
    public:
        int x, y;

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

Food f;

using position = struct coordinate;
struct coordinate
{
    int x, y;
};

class Snake
{
    public:
        char direction;
        int score, length;
        position body[groundHeight * groundWidth];

        void move()
        {

            setCurPos(body[0].x, body[0].y);
            std::cout << '*';

            switch(direction)
            {
                case 'w': body[0].x--; break;
                case 'a': body[0].y--; break;
                case 's': body[0].y++; break;
                case 'd': body[0].x++; break;
            }

            setCurPos(body[0].x, body[0].y);
            std::cout << '{';

            if(!this->ifFood())
            {
                setCurPos(body[length].x, body[length].y);
                std::cout << ' ';
            }
            
        }

        bool ifFood()
        {
            if(body[0].x == f.x && body[0].y == f.y)
            {
                f.generateFood(nagini);
                score++;
                length++;
                return true;
            }

            return false;
        }
};

Snake nagini;

int main()
{
    int i = 0;
    system("clear");
    std::thread input(getInput);
    do
    {
        nagini.move();
    }while(nagini.direction != 'e');
    
    return 0;
}

void getInput()
{
    do
    {
        std::cin >> nagini.direction;
    }while(nagini.direction != 'e');
}