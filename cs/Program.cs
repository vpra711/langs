namespace cs
{
    internal class Program
    {
        static void Main(string[] args)
        {
            
            Sorting sorting = new Sorting();
            int[] sortedArray = sorting.BubbleSort( new int[]{ 5, 4, 3, 2, 1 });

            foreach( int i in sortedArray ) 
            {
                Console.WriteLine(i);
            }
        }
    }
}
