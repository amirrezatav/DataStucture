using System;
enum Direction
{
	descending,
	ascending
}
class SortClass
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

		Array.Copy(arr , low , L , 0 , lenL);
		Array.Copy(arr , mid + 1 ,  R , 0 , lenR);

		if(dir == Direction.ascending)
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
	static void sort(int[] arr, int low, int up , Direction dir)
	{
		if (low < up)
		{
			int mid = (low + up) / 2;

			sort(arr, low, mid , dir);
			sort(arr, mid + 1, up , dir);

			merge(arr, low, mid, up , dir);
		}
	}
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
		else if (dir == Direction.descending)
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
	public static void Insertionsort(int[] arr, Direction dir)
	{
		for (int i = 1; i < arr.Length; ++i)
		{
			int key = arr[i];
			int j = i - 1;

			if (dir == Direction.ascending)
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
	static void Selectionsort(int[] arr, Direction dir)
	{
		int n = arr.Length;
		bool flag = false;
		for (int i = 0; i < n - 1; i++)
		{
			int min_idx = i;
				if(dir == Direction.ascending)
                {
				for (int j = i + 1; j < n; j++)
					if (arr[j] < arr[min_idx])
					{
						min_idx = j;
						flag = true;
					}
				}
				else
                {
				for (int j = i + 1; j < n; j++)
					if (arr[j] > arr[min_idx])
					{
						min_idx = j;
						flag = true;
					}
			}

			if (flag)
			{
				int temp = arr[min_idx];
				arr[min_idx] = arr[i];
				arr[i] = temp;
			}
		}
	}
	static void Shellsort(int[] arr, Direction dir)
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

	}
	static void bubbleSort(int[] arr, Direction dir)
	{
		int n = arr.Length;
		bool flag = true;
		for (int i = 0; i < n - 1 && flag; i++)
        {
			flag = false;
			if(dir == Direction.ascending)
            {
				for (int j = 0; j < n - i - 1; j++)
					if (arr[j] > arr[j + 1])
					{
						int temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
						flag = true;
					}
			}
            else 
			{
				for (int j = 0; j < n - i - 1; j++)
					if (arr[j] < arr[j + 1])
					{
						int temp = arr[j];
						arr[j] = arr[j + 1];
						arr[j + 1] = temp;
						flag = true;
					}
			}
		}
	}

	public static void PrintArray(int[] arr , string Title)
    {
		Console.Write(Title + " : ");
		foreach (int tar in arr)
        {
			Console.Write(tar);
			Console.Write(" ");
		}
		Console.WriteLine();
	}
	public static void Main()
	{
		var watch_bitonicSort = new System.Diagnostics.Stopwatch();
		var watch_Insertionsort = new System.Diagnostics.Stopwatch();
		var watch_Selectionsort = new System.Diagnostics.Stopwatch();
		var watch_Shellsort = new System.Diagnostics.Stopwatch();
		var watch_bubbleSort = new System.Diagnostics.Stopwatch();
		var watch_MergeSort = new System.Diagnostics.Stopwatch();

		int arrayLen = (int)Math.Pow(2, 16);
		int[] array = new int[arrayLen];

		Random rd = new Random();
		for(int i = 0; i < arrayLen; i++)
        {
			array[i] = rd.Next(1, 1000);
		}

		int[] array_bitonicSort = new int[arrayLen];
		var array_Insertionsort = new int[arrayLen];
		var array_Selectionsort = new int[arrayLen];
		var array_Shellsort = new int[arrayLen];
		var array_bubbleSort = new int[arrayLen];
		var array_MergeSort = new int[arrayLen];

		Array.Copy(array, array_bitonicSort, arrayLen);
		Array.Copy(array, array_Insertionsort, arrayLen);
		Array.Copy(array, array_Selectionsort, arrayLen);
		Array.Copy(array, array_Shellsort, arrayLen);
		Array.Copy(array, array_bubbleSort, arrayLen);
		Array.Copy(array, array_MergeSort, arrayLen);


		watch_bitonicSort.Start();
		bitonicSort(array_bitonicSort, 0, array_bitonicSort.Length, Direction.ascending);
		watch_bitonicSort.Stop();

		watch_Insertionsort.Start();
		Insertionsort(array_Insertionsort, Direction.ascending);
		watch_Insertionsort.Stop();

		watch_Selectionsort.Start();
		Selectionsort(array_Selectionsort, Direction.ascending);
		watch_Selectionsort.Stop();

		watch_Shellsort.Start();
		Shellsort(array_Shellsort, Direction.ascending);
		watch_Shellsort.Stop();

		watch_bubbleSort.Start();
		bubbleSort(array_bubbleSort, Direction.ascending);
		watch_bubbleSort.Stop();

		watch_MergeSort.Start();
		sort(array_MergeSort, 0, arrayLen-1, Direction.ascending);
		watch_MergeSort.Stop();

		//PrintArray(array,               "UnSorted Array     ");
		//PrintArray(array_bitonicSort,   "bitonicSort Array  ");
		//PrintArray(array_Insertionsort, "Insertionsort Array");
		//PrintArray(array_Selectionsort, "Selectionsort Array");
		//PrintArray(array_Shellsort,     "Shellsort Array    ");
		//PrintArray(array_bubbleSort,    "bubbleSort Array   ");
		//PrintArray(array_MergeSort,    "mergeSort Array   ");
		//Console.WriteLine();
		//Console.WriteLine();
		//Console.WriteLine();
		//Console.WriteLine();
		//Console.WriteLine();
		Console.WriteLine("> Time Elapsed : ");
		Console.WriteLine(">> Bitonic Sort Time Elapsed :   {0}", watch_bitonicSort.Elapsed);
		Console.WriteLine(">> Insertion Sort Time Elapsed : {0}", watch_Insertionsort.Elapsed);
		Console.WriteLine(">> Shell Sort Time Elapsed :     {0}", watch_Shellsort.Elapsed);
		Console.WriteLine(">> Selection Sort Time Elapsed : {0}", watch_Selectionsort.Elapsed);
		Console.WriteLine(">> Bubble Sort Time Elapsed :    {0}", watch_bubbleSort.Elapsed);
		Console.WriteLine(">> Merge Sort Time Elapsed :   {0}", watch_MergeSort.Elapsed);

		Console.ReadLine();
	}
}

