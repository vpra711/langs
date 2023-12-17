import java.util.HashMap;
import java.util.Scanner;

public class se
{
    public static void main(String[] args)
    {
        int n;
        Scanner in = new Scanner(System.in);
        n = in.nextInt();
        int[] arr = new int[n];

        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();

        for (int i : arr) 
        {
            if(map.containsKey(i))
            {
                map.put(i, map.get(i) + 1);
            }
            else
            {
                map.put(i, 1);
            }
        }

        for (HashMap<Integer,Integer> i : map)
        {
            System.out.println(i.get(i));            
        }
    }    
}
