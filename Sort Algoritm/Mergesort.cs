using System;
enum Direction
{
	descending,
	ascending
}

class Mergesort
{
	static void merge(int[] arr, int low, int mid, int up, Direction dir)
	{

		int lenL = mid - low + 1;
		int lenR = up - mid;

		int[] L = new int[lenL];
		int[] R = new int[lenR];

		int i = 0;
		int j = 0;
		int k = low;

		Array.Copy(arr, low, L, 0, lenL);
		Array.Copy(arr, mid + 1, R, 0, lenR);

		if (dir == Direction.ascending)
		{
			while (i < lenL && j < lenR)
			{
				if (L[i] <= R[j])
					arr[k++] = L[i++];
				else
					arr[k++] = R[j++];
			}
		}
		else
		{
			while (i < lenL && j < lenR)
			{
				if (L[i] > R[j])
					arr[k++] = L[i++];
				else
					arr[k++] = R[j++];
			}
		}

		while (i < lenL)
			arr[k++] = L[i++];

		while (j < lenR)
			arr[k++] = R[j++];
	}
	static void sort(int[] arr, int low, int up, Direction dir)
	{
		if (low < up)
		{
			int mid = (low + up) / 2;

			sort(arr, low, mid, dir);
			sort(arr, mid + 1, up, dir);

			merge(arr, low, mid, up, dir);
		}
	}
	static void Main()
	{
		var watch = new System.Diagnostics.Stopwatch();

		int[] a = new int[(int)Math.Pow(2, 6)];
		int arrlen = a.Length;
		Random rd = new Random();

		for (int i = 0; i < arrlen; i++)
			a[i] = rd.Next(1, 1000);

		Console.Write("UnSorted array: \n");
		for (int i = 0; i < arrlen; i++)
			Console.Write(a[i] + " ");

		watch.Start();
		sort(a, 0, a.Length - 1, Direction.ascending);
		watch.Stop();

		Console.Write("\n Sorted array: \n");
		for (int i = 0; i < arrlen; i++)
			Console.Write(a[i] + " ");

		Console.WriteLine("");
		Console.WriteLine($"Execution Time: {watch.Elapsed} ");
		Console.ReadLine();
	}
}
