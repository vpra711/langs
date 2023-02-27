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
    const int screenHeight = 20, screenWidth = 60;
    std::string name = "vpra";

    int i = 0, j = 0;
    screensaver box = screensaver(name, screenHeight, screenWidth, 1, 1, true, true);

    while(1)
    {
        //system("sleep 0.1");
        system("clear");

        for(i = 0; i < screenHeight; i++)
        {
            for(j = 0; j < screenWidth; j++)
            {
                j = box.print(i, j);
            }
            std::cout << std::endl;
        }

        box.move();
    }

    return 0;
}