import java.util.Scanner;

public class ladderMatrix {

    public static void main(String[] args) {
        int r, c;
        Scanner in = new Scanner(System.in);

        r = in.nextInt();
        c = in.nextInt();

        int[][] array = new int[r][c];

        int i = 0, j = 0, k = 0;

        System.out.println("Enter the " + r + " x " + c + " Matrix:");

        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                array[i][j] = in.nextInt();
            }
        }

        System.out.println("The Matrix : ");

        for(i = 0; i < r; i++)
        {
            for(j = 0; j < c; j++)
            {
                System.out.print(array[i][j] + " ");
            }

            System.out.println();
        }

        System.out.println("Travesal : ");

        for(i = 0; i < r; i++)
        {
            j = i;
            k = 0;

            while(j > -1)
            {
                System.out.print(array[j][k]);
                j--;
                k++;
            }

            System.out.println();

        }

        for(j = 1; j < c; j++)
        {
            i = r-1;
            k = j;

            while(k < c)
            {
                System.out.print(array[i][k]);
                i--;
                k++;
            }

            System.out.println();

        }
    }
}