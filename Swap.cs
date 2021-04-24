using System;

class Swap
{
    static void outinplaceSwap<T>(ref T input1 , ref T input2)
    {
		T temp = input1;
		input1 = input2;
		input2 = temp;
	}

	public static void Main()
	{
        int a = 2;
        int b = 5;
        Console.WriteLine("Initial a = " , a);
        Console.WriteLine("Initial b = ", b);
        outinplaceSwap<int>(ref a,ref b);
        Console.WriteLine("Out-In-place Swap : ");
        Console.WriteLine("a = ", a);
        Console.WriteLine("b = ", b);
    }
}

