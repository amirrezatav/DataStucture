using System;

class ShellSort
{
	int sort(int[] arr)
	{
		int n = arr.Length;

		for (int gap = n / 2; gap > 0; gap /= 2)
		{

			for (int i = gap; i < n; i += 1)
			{
				int temp = arr[i];

				int j;
				for (j = i; j >= gap && arr[j - gap] > temp; j -= gap)
					arr[j] = arr[j - gap];

				arr[j] = temp;
			}
		}
		return 0;
	}

	public static void Main()
	{
		int[] arr = { 1, 0, 2, 22, 582 };
		Console.Write("Array before sorting :\n");
		for (int i = 0; i < arr.Length; ++i)
			Console.Write(arr[i] + " ");

		ShellSort ob = new ShellSort();
		ob.sort(arr);

		Console.Write("Array after sorting :\n");
		for (int i = 0; i < arr.Length; ++i)
			Console.Write(arr[i] + " ");
		Console.ReadLine();
	}
}

