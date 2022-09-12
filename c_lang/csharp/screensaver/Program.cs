using System;

class Program
{
    static void Main(String[] args)
    {
        String name1 = "vpra";
        String name2 = "vpra1";
        int screenHeight = 20;
        int screenWidth = 60;
        int i, j;

        // screenHeight = Convert.ToInt32(Console.ReadLine());
        // screenWidth = Convert.ToInt32(Console.ReadLine());

        ScreenSaver box1 = new ScreenSaver(name1, screenHeight, screenWidth, 1, 1, true, true);
        ScreenSaver box2 = new ScreenSaver(name2, screenHeight, screenWidth, 1, 10, true, false);

        while(true)
        {
            Thread.Sleep(50);
            Console.SetCursorPosition(0, 0);
            //Console.Clear();

            for(i = 0; i < screenHeight; i++)
            {
                for(j = 0; j < screenWidth; j++)
                {
                    j = box1.print(i, j);
                    j = box2.print(i, j);
                }
                
                Console.WriteLine();
            }

            box1.checkBeforeSmash(box2);
            box1.move();
            box2.move();
            
        }
    }
}