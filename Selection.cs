//  Selection Sort
using System;

class GFG
{
	static void sort(int[] arr)
	{
		int n = arr.Length;
		bool flag = false;
		for (int i = 0; i < n - 1; i++)
		{
			int min_idx = i;
			for (int j = i + 1; j < n; j++)
				if (arr[j] < arr[min_idx])
				{
					min_idx = j;
					flag = true;
				}

			if (flag)
			{
				int temp = arr[min_idx];
				arr[min_idx] = arr[i];
				arr[i] = temp;
			}
		}
	}

	// Driver code
	public static void Main()
	{
		int[] arr = { 64, 25, 12, 22, 11 };
		sort(arr);
		Console.WriteLine("Sorted array");
		for (int i = 0; i < arr.Length; ++i)
			Console.Write(arr[i] + " ");
	}

}
