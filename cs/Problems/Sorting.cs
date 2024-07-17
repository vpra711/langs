namespace cs
{
    internal class Sorting
    {
        public int[] BubbleSort(int[] array)
        {
            for (int i = 0; i < array.Length; i++)
            {
                for (int j = i + 1; j < array.Length; j++)
                {
                    if (array[i] > array[j])
                    {
                        int temp = array[j];
                        array[j] = array[i];
                        array[i] = temp;
                    }
                }
            }

            return array;
        }

        public int[] SleepSort(int[] array)
        {
            return array;
        }

        public int[] MergeSort(int[] array)
        {
            return array;
        }
    }
}
