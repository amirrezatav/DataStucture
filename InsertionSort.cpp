// C# program for implementation of Insertion Sort
using System;
enum Direction
{
	descending,
	ascending
}
class InsertionSort
{

	public static void Insertionsort(int[] arr , Direction dir )
	{
		for (int i = 1; i < arr.Length; ++i)
		{
			int key = arr[i];
			int j = i - 1;

			if(dir == Direction.ascending)
            {
				while (j >= 0 && arr[j] > key)
				{
					arr[j + 1] = arr[j];
					j = j - 1;
				}
			}
            else
            {
				while (j >= 0 && arr[j] < key)
				{
					arr[j + 1] = arr[j];
					j = j - 1;
				}
			}
		
			arr[j + 1] = key;
		}
	}

	// Driver Code
	public static void Main()
	{
		var watch = new System.Diagnostics.Stopwatch();

		int[] a = new int[(int)Math.Pow(2, 6)];
		Random rd = new Random();

		for (int i = 0; i < a.Length; i++)
			a[i] = rd.Next(1, 1000);

		Console.Write("UnSorted array: \n");
		for (int i = 0; i < a.Length; i++)
			Console.Write(a[i] + " ");

		watch.Start();
		Insertionsort(a , Direction.ascending);
		watch.Stop();

		Console.Write("\n Sorted array: \n");
		for (int i = 0; i < a.Length; i++)
			Console.Write(a[i] + " ");

		Console.WriteLine("");
		Console.WriteLine($"Execution Time: {watch.Elapsed} ");
		Console.ReadLine();
	}
}

