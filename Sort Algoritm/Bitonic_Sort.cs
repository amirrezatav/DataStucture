using System;
enum Direction
{
	descending,
	ascending
}
class BitonicSort
{


	static void Swap<T>(ref T lhs, ref T rhs)
	{
		T temp;
		temp = lhs;
		lhs = rhs;
		rhs = temp;
	}

	public static void compAndSwap(int[] a, int i, int j, Direction dir)
	{
		if ((a[i] > a[j]))
        {
			if (dir == Direction.ascending)
			{
				Swap(ref a[i], ref a[j]);
			}
		}
		else if(dir == Direction.descending)
        {
			Swap(ref a[i], ref a[j]);
		}
			
	}
	public static void bitonicMerge(int[] a, int low, int count, Direction dir)
	{
		if (count > 1)
		{
			int k = count / 2;
			for (int i = low; i < low + k; i++)
				compAndSwap(a, i, i + k, dir);
        
			bitonicMerge(a, low, k, dir);
			bitonicMerge(a, low + k, k, dir);
		}
	}
	public static void bitonicSort(int[] a, int low, int count, Direction dir)
	{
		if (count > 1)
		{
			int k = count / 2;

			bitonicSort(a, low, k, Direction.ascending);

			bitonicSort(a, low + k, k, Direction.descending);

			bitonicMerge(a, low, count, dir);
		}
	}

	public static void sort(int[] a, int count, Direction up)
	{
		bitonicSort(a, 0, count, up);
	}
	static void Main()
	{
		var watch = new System.Diagnostics.Stopwatch();

		int[] a = new int[(int)Math.Pow(2,6)];
		int arrlen = a.Length;
		Random rd = new Random();

		for (int i = 0; i < arrlen; i++)
			a[i] = rd.Next(1, 1000);

		Console.Write("UnSorted array: \n");
		for (int i = 0; i < arrlen; i++)
			Console.Write(a[i] + " ");

		watch.Start();
		sort(a, a.Length , Direction.ascending);
		watch.Stop();

		Console.Write("\n Sorted array: \n");
		for (int i = 0; i < arrlen; i++)
			Console.Write(a[i] + " ");

		Console.WriteLine("");
		Console.WriteLine($"Execution Time: {watch.Elapsed} ");
		Console.ReadLine();
	}
}
© 2021 GitH
