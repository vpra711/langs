namespace cs
{
	internal class ArrayProbs
	{ // yet to test
		public (int, int) firstLastOccurance(int[] numbers) 
		{
			int numberToFind = 5;
			int startPointer = 0;
			int endPointer = numbers.Length;
			int midPointer = 0;
			var cutomType = (-1, -1);

			while(startPointer <= endPointer)
			{
				midPointer = (endPointer - startPointer) / 2 + startPointer;

				if(numbers[midPointer] == numberToFind)
				{
					endPointer = midPointer - 1;
					cutomType.Item1 = midPointer;
				}
				else if(numbers[midPointer] > numberToFind)
				{
					startPointer = midPointer + 1;
				}
				else
				{
					endPointer = midPointer - 1;
				}
			}

			startPointer = 0;
			endPointer = numbers.Length;

			while(startPointer <= endPointer)
			{
				midPointer = (endPointer = startPointer) / 2 + startPointer;

				if(numbers[midPointer] == numberToFind)
				{
					startPointer = midPointer + 1;
					cutomType.Item2 = midPointer;
				}
				else if (numbers[midPointer] < numberToFind)
				{
					endPointer = midPointer - 1;
				}
				else
				{
					startPointer = midPointer + 1;
				}
			}

			return cutomType;
		}
	}
}