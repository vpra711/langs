import java.util.Scanner;

public class it 
{
    public static void main(String[] args)
    {
        int number, temp;

        boolean result = false;

        Scanner in = new Scanner(System.in);

        number = in.nextInt();
        temp = number;
        
        temp = reverse(temp);
        temp = reverse(temp);

        if(number == temp)
        {
            result = true;
        }
        else
        {
            result = false;
        }

        System.out.println(result);
    }    


    public static int reverse(int number)
    {
        int temp = number, reversed = 0;

        while(temp > 0)
        {
            reversed = reversed * 10 + (temp % 10);
            temp /= 10;
        }

        return reversed;
    }
}
