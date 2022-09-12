import java.util.*;
public class gold  
{
    public static void main(String[] args)
    {
        int a,b,c;
        System.out.println("Enter the first value");
        Scanner in = new Scanner(System.in);
        a=in.nextInt();
        System.out.println("Enter the second value");
        b=in.nextInt();
        System.out.println("the addition of two number ");
        c=a+b;
        System.out.println(c);
        System.out.println("the subrat of two number ");
        c=a-b;
        System.out.println(c);
        System.out.println("the multiple of two number");
        c=a*b;
        System.out.println(c);
        System.out.println("the division of two number");
        c=a/b;
        System.out.println(c);
        in.close();
    }
}
