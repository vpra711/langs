import java.util.Scanner;

public class calculator
{
    public static void main(String[] args) 
    {
        double n1, n2, result = 0;
        int operator;
        Scanner in = new Scanner(System.in);
        System.out.print("Enter the first number :");
        n1 = in.nextDouble();
        System.out.println("Enter the second number :");
        n2 = in.nextDouble();
        System.out.println("Enter the operation :\n1) Add\n2) Subract\n3) Multiply\n4)division");
        operator = in.nextInt();
        switch(operator)
        {
            case 1: result = n1 + n2; break;
            case 2: result = n1 - n2; break;
            case 3: result = n1 * n2; break;
            case 4: result = n1 / n2; break;
            default : System.out.println("Wrong option"); System.exit(0);
        }
        System.out.println("Result : "+ result);
    }
}