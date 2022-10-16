class ScreenSaver
{
    String name;
    int nameLength;
    int screenHeight;
    int screenWidth;
    int posHeight;
    int posWidth;
    bool incDecHeight;
    bool incDecWidth;

    bool check;
    bool check1;

    public ScreenSaver(String name, int screenHeight, int screenWidth, int PositionHeight, int PositionWidth, bool incDecHeight, bool incDecWidth)
    {
        this.name = name;
        this.nameLength = name.Length;
        this.screenHeight = screenHeight;
        this.screenWidth = screenWidth;
        this.posHeight = PositionHeight;
        this.posWidth = PositionWidth;
        this.incDecHeight = incDecHeight;
        this.incDecWidth = incDecWidth;
    }

    public void move()
    {
        if(posHeight <= 0 || posHeight >= screenHeight)
        {
            incDecHeight = !incDecHeight;
        }

        if(posWidth <= 0 || posWidth >= (screenWidth - nameLength))
        {
            incDecWidth = !incDecWidth;
        }

        if(incDecHeight)
        {
            posHeight++;
        }
        else
        {
            posHeight--;
        }

        if(incDecWidth)
        {
            posWidth++;
        }
        else
        {
            posWidth--;
        }
    }

    public void checkBeforeSmash(ScreenSaver box)
    {
        if(posHeight - 1 == box.posHeight || posHeight + 1 == box.posHeight)
        {
            check = (box.posWidth >= posWidth) && (box.posWidth <= (posWidth + nameLength));
            check1 = ((box.posWidth + box.nameLength) >= posWidth) && ((box.posWidth + box.nameLength) <= (posWidth + nameLength));

            if(check || check1)
            {
                incDecHeight = !incDecHeight;
                //incDecWidth = !incDecWidth;
                box.incDecHeight = !box.incDecHeight;
                //box.incDecWidth = !box.incDecWidth;
            }
        }
    }

    public int print(int i, int j)
    {
        if(i == posHeight && j == posWidth)
        {
            Console.Write(name);
            j += nameLength;
        }
        else
        {
            Console.Write(" ");
        }

        return j;
    }
}