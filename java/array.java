public class array
{
    public static void main(String[] args) 
    {
        int[] numbers = new int[5];
        
        numbers[0] = 10;
        numbers[1] = 11;

        for(int i : numbers)
            System.out.println(i);

    }
}