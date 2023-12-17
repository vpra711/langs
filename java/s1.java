import java.lang.System;

public class s1
{
    public static void main(String[] args)
    {
        int size = 5;
        zzz(size);
        System.out.println("Hello wolrd!");
    }

    public static void zzz(int zzz)
    {
        if(zzz > 2000)
            return;
        System.out.println(zzz);
        zzz++;
        zzz(zzz);
    }
}
