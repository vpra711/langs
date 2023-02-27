#include <iostream>

class screensaver
{
    public:
        std::string name;
        int length;
        int screenHeight;
        int screenWidth;
        int currPosHeight;
        int currPosWidth;
        bool incDecHeight;
        bool incDecWidth;
        bool checkRowTop;
        bool checkColBottom;
        
        screensaver(std::string name, int screenHeight, int screenWidth, int startPosHeight, int startPosWidth, bool incDecHeight, bool incDecWidth)
        {
            this->name = name;
            this->length = name.length();
            this->screenHeight = screenHeight;
            this->screenWidth = screenWidth;
            this->currPosHeight = startPosHeight;
            this->currPosWidth = startPosWidth;
            this->incDecHeight = incDecHeight;
            this->incDecWidth = incDecHeight;
        }

        void move()
        {

            if(currPosHeight <= 0 || currPosHeight >=  screenHeight)
            {
                incDecHeight = !incDecHeight;
            }

            if(currPosWidth <= 0 || currPosWidth >= screenWidth - length)
            {
                incDecWidth = !incDecWidth;
            }

            if(incDecHeight)
            {
                currPosHeight++;
            }
            else
            {
                currPosHeight--;
            }

            if(incDecWidth)
            {
                currPosWidth++;
            }
            else
            {
                currPosWidth--;
            }
        }

        screensaver check(screensaver box)
        {
            if(currPosHeight - 1 == box.currPosHeight || currPosHeight + 1 == box.currPosHeight)
            {
                checkRowTop = (box.currPosWidth >= currPosWidth) && (box.currPosWidth <= (currPosWidth + length)); 
                checkColBottom = ((box.currPosWidth + length) >= currPosWidth) && ((box.currPosWidth + length) <= (currPosWidth + length));

                if(checkRowTop || checkColBottom)
                {
                    incDecHeight = !incDecHeight;
                    box.incDecHeight = !box.incDecHeight;
                }
            }  

            return box;
        }

        int print(int i, int j)
        {
            if(i == currPosHeight && j == currPosWidth)
            {
                std::cout << name;
                j += length;
            }
            else
            {
                std::cout << " ";
            }
            return j;
        }
};

int main()
{
    const int screenHeight = 20, screenWidth = 20;
    std::string name = "vpra";
    std::string name2 = "vpra1";

    int i = 0, j = 0;
    screensaver box = screensaver(name, screenHeight, screenWidth, 1, 1, true, true);
    screensaver box2 = screensaver(name2, screenHeight, screenWidth, 10, 10, false, true);

    while(1)
    {
        //system("sleep 0.1");
        system("clear");

        for(i = 0; i < screenHeight; i++)
        {
            for(j = 0; j < screenWidth; j++)
            {
                box2 = box.check(box2);
                j = box.print(i, j);
                j = box2.print(i, j);

            }
            std::cout << std::endl;
        }

        box.move();
        box2.move();
    }

    return 0;
}